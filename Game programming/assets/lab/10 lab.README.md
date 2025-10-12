# 10. Design a multiplayer game prototype using networking libraries in Unity or Python 


### Basic of Networking
1. Create new project, 
2. Create new python file name it "server.py", "client.py"

#### Server side
```py
# server.py
import socket
import threading

HOST = '127.0.0.1'  # Localhost
PORT = 12345

game_state = {}  # Store shared game data


def handle_client(conn, addr):
    print(f"Connected by {addr}")
    while True:
        try:
            data = conn.recv(1024).decode('utf-8')
            if not data:
                break
            print(f"Received from {addr}: {data}")
            # Process client data and update game_state
            # Example: game_state['player_pos'] = data

            # Send updated game state to client (or specific data)
            response = "Server received your message!"
            conn.sendall(response.encode('utf-8'))
        except ConnectionResetError:
            print(f"Client {addr} disconnected.")
            break
    conn.close()


def start_server():
    with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
        s.bind((HOST, PORT))
        s.listen()
        print(f"Server listening on {HOST}:{PORT}")
        while True:
            conn, addr = s.accept()
            thread = threading.Thread(target=handle_client, args=(conn, addr))
            thread.start()


if __name__ == "__main__":
    start_server()
```

#### Client side
```py
# client.py
import socket

HOST = '127.0.0.1'  # Localhost
PORT = 12345

def start_client():
    with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
        s.connect((HOST, PORT))
        print(f"Connected to server on {HOST}:{PORT}")
        while True:
            message = input("Enter message to send: ")
            s.sendall(message.encode('utf-8'))
            data = s.recv(1024).decode('utf-8')
            print(f"Received from server: {data}")

if __name__ == "__main__":
    start_client()
```

3. Run server.py and client.py and type msg to check connection

<br>
<br>

### Simple  Game

1. Server

```py
import socket
import threading
import pickle
import time

# Server setup
HOST = 'localhost'
PORT = 5555
s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)  # UDP socket for game data
s.bind((HOST, PORT))
print(f"Server started on {HOST}:{PORT}")

# Game state management
players = {}  # Store player data: {player_id: {'pos': (x, y), 'health': 100}}
bullets = []


def game_loop():
    while True:
        # Simulate game physics (e.g., move bullets)
        for bullet in bullets:
            bullet['pos'][0] += bullet['vel'][0]
            bullet['pos'][1] += bullet['vel'][1]

        # Check for collisions on the server
        # For simplicity, this is omitted but would go here.
        # Broadcast game state to all clients
        game_state = {'players': players, 'bullets': bullets}
        serialized_state = pickle.dumps(game_state)
        for player_address in players.keys():
            s.sendto(serialized_state, player_address)
        time.sleep(1 / 60)  # 60 FPS update rate


def handle_client():
    while True:
        try:
            data, addr = s.recvfrom(4096)
            message = pickle.loads(data)

            if 'connect' in message:
                players[addr] = {'pos': [100, 100], 'health': 100}
                print(f"New player connected from {addr}")
            elif 'move' in message:
                players[addr]['pos'] = message['move']
            elif 'shoot' in message:
                # Add a new bullet to the game state
                bullets.append({
                    'id': time.time(),
                    'pos': list(players[addr]['pos']),
                    'vel': message['shoot']
                })
        except Exception as e:
            print(f"Error handling client: {e}")


# Start server threads
threading.Thread(target=game_loop, daemon=True).start()
threading.Thread(target=handle_client, daemon=True).start()

# Keep main thread alive
while True:
    time.sleep(1)

```

2. Client

```py
import pygame
import socket
import pickle
import threading
import time

# Pygame setup
pygame.init()
screen_width = 800
screen_height = 600
screen = pygame.display.set_mode((screen_width, screen_height))
clock = pygame.time.Clock()
WHITE = (255, 255, 255)
RED = (255, 0, 0)
BLUE = (0, 0, 255)

# Network setup
HOST = 'localhost'
PORT = 5555
s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
s.bind(('0.0.0.0', 0))  # Bind to a random port
s.sendto(pickle.dumps({'connect': True}), (HOST, PORT))
server_address = (HOST, PORT)

game_state = {'players': {}, 'bullets': []}
my_address = None


def receive_data():
    global game_state, my_address
    while True:
        try:
            data, addr = s.recvfrom(4096)
            game_state = pickle.loads(data)
            if not my_address:
                my_address = s.getsockname()
        except Exception as e:
            print(f"Error receiving data: {e}")


# Start receiving thread
threading.Thread(target=receive_data, daemon=True).start()

# Player movement variables
player_x, player_y = 100, 100
player_speed = 5

running = True
while running:
    # Handle events
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False
        if event.type == pygame.KEYDOWN:
            if event.key == pygame.K_SPACE and my_address:
                # Send a shoot message to the server
                mouse_pos = pygame.mouse.get_pos()
                dx = mouse_pos[0] - player_x
                dy = mouse_pos[1] - player_y
                dist = (dx ** 2 + dy ** 2) ** 0.5
                if dist > 0:
                    bullet_vel = [dx / dist * 10, dy / dist * 10]
                    s.sendto(pickle.dumps({'shoot': bullet_vel}), server_address)

    # Handle player movement based on keyboard input
    keys = pygame.key.get_pressed()
    if keys[pygame.K_LEFT]:
        player_x -= player_speed
    if keys[pygame.K_RIGHT]:
        player_x += player_speed
    if keys[pygame.K_UP]:
        player_y -= player_speed
    if keys[pygame.K_DOWN]:
        player_y += player_speed

    # Send player position to the server
    if my_address:
        s.sendto(pickle.dumps({'move': [player_x, player_y]}), server_address)

    # --- Drawing ---
    screen.fill((0, 0, 0))

    # Draw other players
    for player_address, player_data in game_state['players'].items():
        if player_address != my_address:
            pygame.draw.rect(screen, RED, (player_data['pos'][0], player_data['pos'][1], 30, 30))

    # Draw my player
    if my_address:
        pygame.draw.rect(screen, BLUE, (player_x, player_y, 30, 30))

    # Draw bullets
    for bullet in game_state['bullets']:
        pygame.draw.circle(screen, WHITE, (int(bullet['pos'][0]), int(bullet['pos'][1])), 5)

    pygame.display.flip()
    clock.tick(60)

pygame.quit()

```