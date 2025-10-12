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

### Simple Pong Game

1. 