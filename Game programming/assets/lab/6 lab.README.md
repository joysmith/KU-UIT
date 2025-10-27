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


<br>
<br>

### Version 3


```py
"""
Simple Space Invaders Game 
-------------------------------------------------------------
A beginner-friendly Space Invaders clone using Pygame.

Features:
- Player spaceship moves left/right and shoots bullets.
- Enemies (aliens) spawn and move downward.
- Score increases when aliens are destroyed.
- Health decreases if aliens reach the bottom.
- Includes UI manager with score and health bar.
"""

import pygame
import random
import sys

# --- Initialize Pygame ---
pygame.init()

# --- Screen Configuration ---
WIDTH, HEIGHT = 800, 600
screen = pygame.display.set_mode((WIDTH, HEIGHT))
pygame.display.set_caption("Space Invaders - Pygame Example")

# --- Colors ---
WHITE = (255, 255, 255)
BLACK = (25, 25, 25)
GREEN = (0, 200, 100)
RED = (200, 50, 50)
YELLOW = (255, 220, 0)
BLUE = (50, 150, 255)

# --- Fonts & Clock ---
font = pygame.font.Font(None, 36)
clock = pygame.time.Clock()


# =====================================================================
#                            UI MANAGER
# =====================================================================
class UIManager:
    """Handles score display and player health bar."""

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
        """Draw score and health bar."""
        # Draw score
        score_text = font.render(f"Score: {self.score}", True, WHITE)
        surface.blit(score_text, (20, 20))

        # Health bar border
        pygame.draw.rect(surface, WHITE, (20, 60, 200, 30), 2)

        # Health bar fill
        bar_width = int(196 * (self.health / 100))
        bar_color = GREEN if self.health > 30 else RED
        pygame.draw.rect(surface, bar_color, (22, 62, bar_width, 26))


# =====================================================================
#                            PLAYER SPRITE
# =====================================================================
class Player(pygame.sprite.Sprite):
    """Represents the player's spaceship."""

    def __init__(self):
        super().__init__()
        self.image = pygame.Surface((60, 40))
        self.image.fill(BLUE)
        self.rect = self.image.get_rect(center=(WIDTH // 2, HEIGHT - 60))
        self.speed = 7
        self.cooldown = 0  # Time between shots

    def update(self, keys):
        """Handle player movement and shooting cooldown."""
        if keys[pygame.K_LEFT]:
            self.rect.x -= self.speed
        if keys[pygame.K_RIGHT]:
            self.rect.x += self.speed

        # Keep player on screen
        self.rect.x = max(0, min(self.rect.x, WIDTH - self.rect.width))

        # Reduce cooldown timer
        if self.cooldown > 0:
            self.cooldown -= 1

    def shoot(self, bullets_group):
        """Fire a bullet upward if not cooling down."""
        if self.cooldown == 0:
            bullet = Bullet(self.rect.centerx, self.rect.top)
            bullets_group.add(bullet)
            self.cooldown = 15  # roughly 0.25 seconds


# =====================================================================
#                            BULLET SPRITE
# =====================================================================
class Bullet(pygame.sprite.Sprite):
    """Represents a bullet shot by the player."""

    def __init__(self, x, y):
        super().__init__()
        self.image = pygame.Surface((6, 12))
        self.image.fill(YELLOW)
        self.rect = self.image.get_rect(center=(x, y))
        self.speed = -10  # Move upward

    def update(self):
        """Move the bullet upward and remove if off-screen."""
        self.rect.y += self.speed
        if self.rect.bottom < 0:
            self.kill()


# =====================================================================
#                            ENEMY SPRITE
# =====================================================================
class Enemy(pygame.sprite.Sprite):
    """Represents an alien enemy."""

    def __init__(self, x, y):
        super().__init__()
        self.image = pygame.Surface((40, 30))
        self.image.fill(RED)
        self.rect = self.image.get_rect(center=(x, y))
        self.speed = random.randint(2, 4)

    def update(self):
        """Move enemy downward, remove if off-screen."""
        self.rect.y += self.speed
        if self.rect.top > HEIGHT:
            self.kill()


# =====================================================================
#                            GAME SETUP
# =====================================================================
ui = UIManager()
player = Player()

player_group = pygame.sprite.Group(player)
bullets = pygame.sprite.Group()
enemies = pygame.sprite.Group()

# Spawn new enemies periodically
SPAWN_EVENT = pygame.USEREVENT + 1
pygame.time.set_timer(SPAWN_EVENT, 1000)  # Every 1 second

running = True
game_over = False


# =====================================================================
#                            MAIN GAME LOOP
# =====================================================================
while running:
    # --- Event Handling ---
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False

        # Spawn enemies
        elif event.type == SPAWN_EVENT and not game_over:
            x = random.randint(40, WIDTH - 40)
            enemy = Enemy(x, -20)
            enemies.add(enemy)

        # Restart after Game Over
        elif event.type == pygame.KEYDOWN and game_over:
            if event.key == pygame.K_r:
                ui = UIManager()
                player = Player()
                player_group = pygame.sprite.Group(player)
                bullets.empty()
                enemies.empty()
                game_over = False

    # --- Game Logic ---
    screen.fill(BLACK)

    if not game_over:
        keys = pygame.key.get_pressed()
        player.update(keys)

        # Shooting bullets
        if keys[pygame.K_SPACE]:
            player.shoot(bullets)

        bullets.update()
        enemies.update()

        # --- Collision Detection ---
        # Bullet hits enemy
        for bullet in bullets:
            hit_list = pygame.sprite.spritecollide(bullet, enemies, True)
            if hit_list:
                bullet.kill()
                ui.update_score(10 * len(hit_list))

        # Enemy reaches bottom (player loses health)
        for enemy in enemies:
            if enemy.rect.bottom >= HEIGHT:
                ui.update_health(-10)
                enemy.kill()

        # Game Over Condition
        if ui.health <= 0:
            game_over = True

        # --- Drawing ---
        player_group.draw(screen)
        bullets.draw(screen)
        enemies.draw(screen)
        ui.draw(screen)

    else:
        # --- Game Over Screen ---
        over_text = font.render("GAME OVER - Press R to Restart", True, WHITE)
        screen.blit(over_text, (WIDTH // 2 - over_text.get_width() // 2, HEIGHT // 2 - 20))

        final_score = font.render(f"Final Score: {ui.score}", True, WHITE)
        screen.blit(final_score, (WIDTH // 2 - final_score.get_width() // 2, HEIGHT // 2 + 30))

    # --- Update Display ---
    pygame.display.flip()
    clock.tick(60)

# --- Exit ---
pygame.quit()
sys.exit()
```


<br>
<br>


### Version 4

```py
"""
Fancy Space Invaders Game
-------------------------
Features:
    - Player spaceship that can move left/right and shoot.
    - Colorful alien enemies that drift down in wavy patterns.
    - Bullets, explosions, and simple particle-style stars.
    - Scoreboard and health bar displayed on screen.
    - Smooth animations and restartable Game Over screen.

"""

import pygame
import random
import sys
import math

# -------------------------------------------------------------------
#                         BASIC SETUP
# -------------------------------------------------------------------

# Initialize Pygame
pygame.init()

# Screen dimensions
WIDTH, HEIGHT = 800, 600
screen = pygame.display.set_mode((WIDTH, HEIGHT))
pygame.display.set_caption("Fancy Space Invaders")

# Colors (RGB values)
WHITE  = (255, 255, 255)
BLACK  = (15, 15, 25)
RED    = (255, 80, 80)
GREEN  = (0, 255, 100)
YELLOW = (255, 230, 60)
CYAN   = (80, 200, 255)
PURPLE = (190, 0, 255)

# Fonts and timing
font      = pygame.font.Font(None, 36)
big_font  = pygame.font.Font(None, 72)
clock     = pygame.time.Clock()

# -------------------------------------------------------------------
#                        USER INTERFACE
# -------------------------------------------------------------------
class UIManager:
    """Handles all user interface elements like score and health bar."""

    def __init__(self):
        self.score  = 0
        self.health = 100

    def update_score(self, amount):
        """Increase the score by a given amount."""
        self.score = max(0, self.score + amount)

    def update_health(self, amount):
        """Increase or decrease player health, clamped between 0 and 100."""
        self.health = max(0, min(100, self.health + amount))

    def draw(self, surface):
        """Draw the scoreboard and health bar on the screen."""
        # --- Draw Score ---
        score_text = font.render(f"Score: {self.score}", True, WHITE)
        surface.blit(score_text, (20, 20))

        # --- Draw Health Bar ---
        pygame.draw.rect(surface, WHITE, (20, 60, 200, 25), 2)
        fill_width = int(196 * (self.health / 100))
        bar_color = GREEN if self.health > 30 else RED
        pygame.draw.rect(surface, bar_color, (22, 62, fill_width, 21))


# -------------------------------------------------------------------
#                         PLAYER SPRITE
# -------------------------------------------------------------------
class Player(pygame.sprite.Sprite):
    """Player spaceship controlled by the user."""

    def __init__(self):
        super().__init__()
        # Draw a simple triangular spaceship
        self.image = pygame.Surface((60, 40), pygame.SRCALPHA)
        pygame.draw.polygon(self.image, CYAN, [(0, 40), (30, 0), (60, 40)])
        self.rect = self.image.get_rect(center=(WIDTH // 2, HEIGHT - 60))
        self.speed = 6
        self.cooldown = 0  # Frames between shots

    def update(self, keys):
        """Move the ship left or right based on key input."""
        if keys[pygame.K_LEFT]:
            self.rect.x -= self.speed
        if keys[pygame.K_RIGHT]:
            self.rect.x += self.speed

        # Keep player within screen boundaries
        self.rect.x = max(0, min(WIDTH - self.rect.width, self.rect.x))

        # Reduce shot cooldown timer each frame
        if self.cooldown > 0:
            self.cooldown -= 1

    def shoot(self, bullet_group):
        """Create a bullet object if the player can shoot."""
        if self.cooldown == 0:
            bullet = Bullet(self.rect.centerx, self.rect.top)
            bullet_group.add(bullet)
            self.cooldown = 12  # About 0.2 seconds delay between shots


# -------------------------------------------------------------------
#                         BULLET SPRITE
# -------------------------------------------------------------------
class Bullet(pygame.sprite.Sprite):
    """A projectile fired by the player's ship."""

    def __init__(self, x, y):
        super().__init__()
        self.image = pygame.Surface((4, 12))
        self.image.fill(YELLOW)
        self.rect = self.image.get_rect(center=(x, y))
        self.speed = -10  # Negative because bullets move upward

    def update(self):
        """Move bullet upward and destroy if off-screen."""
        self.rect.y += self.speed
        if self.rect.bottom < 0:
            self.kill()


# -------------------------------------------------------------------
#                          ENEMY SPRITE
# -------------------------------------------------------------------
class Enemy(pygame.sprite.Sprite):
    """Enemy alien that drifts down the screen in a sine-wave pattern."""

    def __init__(self, x, y):
        super().__init__()
        # Create a simple alien shape using rectangles/circles
        self.image = pygame.Surface((40, 30), pygame.SRCALPHA)
        pygame.draw.rect(self.image, PURPLE, (0, 0, 40, 30))
        pygame.draw.circle(self.image, RED, (20, 15), 8)
        self.rect = self.image.get_rect(center=(x, y))

        # Movement pattern attributes
        self.base_x = x
        self.angle  = random.randint(0, 360)
        self.speed  = random.uniform(2.0, 3.5)

    def update(self):
        """Move enemy downward with a side-to-side sine motion."""
        self.angle += 4
        self.rect.x = self.base_x + int(math.sin(math.radians(self.angle)) * 40)
        self.rect.y += self.speed

        # Remove enemy if it goes off-screen
        if self.rect.top > HEIGHT:
            self.kill()


# -------------------------------------------------------------------
#                         STAR BACKGROUND
# -------------------------------------------------------------------
class Star:
    """Small moving points of light for a parallax star background."""

    def __init__(self):
        self.x = random.randint(0, WIDTH)
        self.y = random.randint(0, HEIGHT)
        self.size  = random.randint(1, 3)
        self.speed = random.uniform(1, 3)

    def update(self):
        """Scroll star downward and loop it to the top when it exits."""
        self.y += self.speed
        if self.y > HEIGHT:
            self.y = 0
            self.x = random.randint(0, WIDTH)

    def draw(self, surface):
        pygame.draw.circle(surface, WHITE, (int(self.x), int(self.y)), self.size)


# -------------------------------------------------------------------
#                          GAME SETUP
# -------------------------------------------------------------------
ui = UIManager()
player = Player()

# Sprite groups keep code organized and efficient
player_group = pygame.sprite.Group(player)
bullet_group = pygame.sprite.Group()
enemy_group  = pygame.sprite.Group()

# Generate some background stars
stars = [Star() for _ in range(80)]

# Timed event to spawn enemies
SPAWN_EVENT = pygame.USEREVENT + 1
pygame.time.set_timer(SPAWN_EVENT, 900)  # every 0.9 seconds

running = True
game_over = False

# -------------------------------------------------------------------
#                         MAIN GAME LOOP
# -------------------------------------------------------------------
while running:
    # ---------------------------------------------------------------
    # Handle all incoming events (keyboard, quit, etc.)
    # ---------------------------------------------------------------
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False

        elif event.type == SPAWN_EVENT and not game_over:
            # Spawn a new alien at a random x-position
            x = random.randint(50, WIDTH - 50)
            enemy_group.add(Enemy(x, -30))

        elif event.type == pygame.KEYDOWN and game_over:
            # Restart the game by reinitializing everything
            if event.key == pygame.K_r:
                ui = UIManager()
                player = Player()
                player_group = pygame.sprite.Group(player)
                bullet_group.empty()
                enemy_group.empty()
                game_over = False

    # ---------------------------------------------------------------
    # Update game state
    # ---------------------------------------------------------------
    screen.fill(BLACK)

    # Animate background stars
    for star in stars:
        star.update()
        star.draw(screen)

    if not game_over:
        # --- Player controls ---
        keys = pygame.key.get_pressed()
        player.update(keys)
        if keys[pygame.K_SPACE]:
            player.shoot(bullet_group)

        # --- Update all sprites ---
        bullet_group.update()
        enemy_group.update()

        # --- Bullet/enemy collision ---
        hits = pygame.sprite.groupcollide(enemy_group, bullet_group, True, True)
        for _ in hits:
            ui.update_score(10)

        # --- Enemies reaching bottom ---
        for enemy in enemy_group:
            if enemy.rect.bottom >= HEIGHT:
                ui.update_health(-15)
                enemy.kill()

        # --- Check for Game Over ---
        if ui.health <= 0:
            game_over = True

        # --- Draw everything ---
        player_group.draw(screen)
        bullet_group.draw(screen)
        enemy_group.draw(screen)
        ui.draw(screen)

    else:
        # -----------------------------------------------------------
        # Game Over Screen
        # -----------------------------------------------------------
        over_text = big_font.render("GAME OVER", True, RED)
        tip_text  = font.render("Press R to Restart", True, WHITE)
        score_txt = font.render(f"Final Score: {ui.score}", True, YELLOW)

        # Center the text on screen
        screen.blit(over_text, (WIDTH//2 - over_text.get_width()//2, HEIGHT//2 - 60))
        screen.blit(score_txt, (WIDTH//2 - score_txt.get_width()//2, HEIGHT//2 + 10))
        screen.blit(tip_text, (WIDTH//2 - tip_text.get_width()//2, HEIGHT//2 + 50))

    # Refresh the display and limit frame rate
    pygame.display.flip()
    clock.tick(60)

# -------------------------------------------------------------------
#                           CLEAN EXIT
# -------------------------------------------------------------------
pygame.quit()
sys.exit()

```