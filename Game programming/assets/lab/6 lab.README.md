# 6. Implement event-driven logic and user interface (scoreboard, health bar) using a UI manager 

- Choose your own color pallet [click me](https://color.adobe.com/create/color-wheel)

### simple version 1

```py
# --------------------------------------------------------------
# Simple Event-Driven UI Example using Pygame
# --------------------------------------------------------------
# This script demonstrates basic event handling in Pygame
# along with a simple User Interface (UI) that displays a score
# and a health bar, both of which update based on user input.
# --------------------------------------------------------------

import pygame
import sys

# -----------------------------
# Initialize Pygame
# -----------------------------
pygame.init()

# -----------------------------
# Screen setup
# -----------------------------
WIDTH, HEIGHT = 800, 600  # Window dimensions
screen = pygame.display.set_mode((WIDTH, HEIGHT))
pygame.display.set_caption("Event-Driven UI Example")  # Title bar text

# -----------------------------
# Define basic colors
# -----------------------------
WHITE = (255, 255, 255)
BLACK = (0, 0, 0)
GREEN = (50, 200, 50)
RED = (200, 50, 50)

# -----------------------------
# Font setup for text rendering
# -----------------------------
font = pygame.font.Font(None, 36)  # Use default font, size 36


# ==============================================================
#                         UI Manager
# ==============================================================
class UIManager:
    """
    This class manages the game's UI elements like score and health.
    It also handles updating and drawing them on the screen.
    """

    def __init__(self):
        # Initialize score and health
        self.score = 0
        self.health = 100

    def update_score(self, points):
        """Increase or decrease the score."""
        self.score += points
        # Prevent score from going negative
        if self.score < 0:
            self.score = 0

    def update_health(self, change):
        """Change health and clamp the value between 0–100."""
        self.health += change
        # Keep health within the 0–100 range
        self.health = max(0, min(100, self.health))

    def draw(self, surface):
        """Render the score and health bar on the screen."""
        # --- Draw score text ---
        score_text = font.render(f"Score: {self.score}", True, WHITE)
        surface.blit(score_text, (20, 20))

        # --- Draw health bar border (rectangle outline) ---
        pygame.draw.rect(surface, WHITE, (20, 60, 200, 30), 2)

        # --- Draw filled health bar based on health percentage ---
        fill_width = int(196 * (self.health / 100))  # Dynamic bar length
        # Health bar turns red if health < 30%
        pygame.draw.rect(surface, GREEN if self.health > 30 else RED, (22, 62, fill_width, 26))


# ==============================================================
#                        Main Game Loop
# ==============================================================
clock = pygame.time.Clock()  # Used to control the frame rate
ui = UIManager()             # Create an instance of the UI manager

running = True  # Main loop flag
while running:
    # Fill the background with black every frame
    screen.fill(BLACK)

    # ----------------------------------------------------------
    # Event handling section
    # ----------------------------------------------------------
    for event in pygame.event.get():
        # If the window's close button is clicked, exit the loop
        if event.type == pygame.QUIT:
            running = False

        # Handle key press events
        elif event.type == pygame.KEYDOWN:
            if event.key == pygame.K_ESCAPE:
                running = False  # ESC key quits the game
            elif event.key == pygame.K_SPACE:
                ui.update_score(10)  # Spacebar increases score
            elif event.key == pygame.K_h:
                ui.update_health(-10)  # 'H' decreases health
            elif event.key == pygame.K_j:
                ui.update_health(+10)  # 'J' increases health

    # ----------------------------------------------------------
    # Drawing section
    # ----------------------------------------------------------
    ui.draw(screen)  # Draw the UI (score + health bar)

    # ----------------------------------------------------------
    # Update the display
    # ----------------------------------------------------------
    pygame.display.flip()  # Refresh the screen
    clock.tick(60)         # Limit frame rate to 60 FPS

# --------------------------------------------------------------
# Cleanup and exit
# --------------------------------------------------------------
pygame.quit()
sys.exit()

```


<br>
<br>

###  version 2


```py
"""
Simple Pygame Mini-Game
-----------------------
A small example showing event-driven gameplay, a basic UI manager
(score + health bar), and sprite-based interactions.

Author: ChatGPT (written like a human 😉)
Date: 2025-10-27
"""

import pygame
import random
import sys

# --- Initialize Pygame ---
pygame.init()

# --- Screen Configuration ---
WIDTH, HEIGHT = 800, 600
screen = pygame.display.set_mode((WIDTH, HEIGHT))
pygame.display.set_caption("Catch or Crash - Simple Pygame Example")

# --- Colors ---
WHITE = (255, 255, 255)
BLACK = (25, 25, 25)
GREEN = (0, 200, 100)
RED = (200, 50, 50)
YELLOW = (255, 220, 0)

# --- Fonts & Clock ---
font = pygame.font.Font(None, 36)
clock = pygame.time.Clock()


# =====================================================================
#                            UI MANAGER
# =====================================================================
class UIManager:
    """Manages all UI elements (scoreboard + health bar)."""

    def __init__(self):
        self.score = 0
        self.health = 100

    def update_score(self, points: int):
        """Increase or decrease score."""
        self.score = max(0, self.score + points)

    def update_health(self, change: int):
        """Modify player health, keeping it between 0 and 100."""
        self.health = max(0, min(100, self.health + change))

    def draw(self, surface: pygame.Surface):
        """Draw the score and health bar on the given surface."""
        # --- Draw Score ---
        score_text = font.render(f"Score: {self.score}", True, WHITE)
        surface.blit(score_text, (20, 20))

        # --- Draw Health Bar Border ---
        pygame.draw.rect(surface, WHITE, (20, 60, 200, 30), 2)

        # --- Fill Health Bar ---
        bar_width = int(196 * (self.health / 100))
        bar_color = GREEN if self.health > 30 else RED
        pygame.draw.rect(surface, bar_color, (22, 62, bar_width, 26))


# =====================================================================
#                            PLAYER SPRITE
# =====================================================================
class Player(pygame.sprite.Sprite):
    """Represents the player rectangle controlled by arrow keys."""

    def __init__(self):
        super().__init__()
        self.image = pygame.Surface((50, 50))
        self.image.fill(GREEN)
        self.rect = self.image.get_rect(center=(WIDTH // 2, HEIGHT - 60))
        self.speed = 7

    def update(self, keys):
        """Move player left or right based on pressed keys."""
        if keys[pygame.K_LEFT]:
            self.rect.x -= self.speed
        if keys[pygame.K_RIGHT]:
            self.rect.x += self.speed

        # Keep the player within screen boundaries
        self.rect.x = max(0, min(self.rect.x, WIDTH - self.rect.width))


# =====================================================================
#                        FALLING OBJECT SPRITE
# =====================================================================
class FallingObject(pygame.sprite.Sprite):
    """
    Represents a falling object.
    Can be a 'coin' (yellow) or a 'hazard' (red).
    """

    def __init__(self, x, y, color, speed, value, kind):
        super().__init__()
        self.image = pygame.Surface((30, 30))
        self.image.fill(color)
        self.rect = self.image.get_rect(center=(x, y))
        self.speed = speed
        self.value = value  # How much it changes score/health
        self.kind = kind    # "coin" or "hazard"

    def update(self):
        """Move downward and delete when off-screen."""
        self.rect.y += self.speed
        if self.rect.top > HEIGHT:
            self.kill()  # Remove object when it leaves the screen


# =====================================================================
#                            GAME SETUP
# =====================================================================
ui = UIManager()
player = Player()
player_group = pygame.sprite.Group(player)
objects = pygame.sprite.Group()

# Custom event for spawning new falling objects
SPAWN_EVENT = pygame.USEREVENT + 1
pygame.time.set_timer(SPAWN_EVENT, 1000)  # Every 1 second

running = True
game_over = False


# =====================================================================
#                            MAIN GAME LOOP
# =====================================================================
while running:
    # --- Handle Events ---
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False

        # Spawn coins/hazards periodically
        elif event.type == SPAWN_EVENT and not game_over:
            x = random.randint(20, WIDTH - 20)
            if random.random() < 0.6:
                # 60% chance to spawn a coin
                obj = FallingObject(x, -20, YELLOW, 5, 10, "coin")
            else:
                # 40% chance to spawn a hazard
                obj = FallingObject(x, -20, RED, 7, -15, "hazard")
            objects.add(obj)

        # Restart game when pressing R after game over
        elif event.type == pygame.KEYDOWN and game_over:
            if event.key == pygame.K_r:
                ui = UIManager()
                player = Player()
                player_group = pygame.sprite.Group(player)
                objects.empty()
                game_over = False

    # --- Game Logic ---
    screen.fill(BLACK)  # Clear the screen each frame

    if not game_over:
        keys = pygame.key.get_pressed()
        player.update(keys)
        objects.update()

        # Detect collisions between player and objects
        for obj in pygame.sprite.spritecollide(player, objects, True):
            if obj.kind == "coin":
                ui.update_score(obj.value)
            else:
                ui.update_health(obj.value)

        # Check for game over condition
        if ui.health <= 0:
            game_over = True

        # Draw active game elements
        player_group.draw(screen)
        objects.draw(screen)
        ui.draw(screen)

    else:
        # --- Game Over Screen ---
        over_text = font.render("GAME OVER - Press R to Restart", True, WHITE)
        screen.blit(over_text, (WIDTH // 2 - over_text.get_width() // 2, HEIGHT // 2 - 20))

        final_score = font.render(f"Final Score: {ui.score}", True, WHITE)
        screen.blit(final_score, (WIDTH // 2 - final_score.get_width() // 2, HEIGHT // 2 + 30))

    # --- Update the Display ---
    pygame.display.flip()
    clock.tick(60)

# --- Quit the Game ---
pygame.quit()
sys.exit()

```