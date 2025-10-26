# 4. Implement a resource manager for textures, audio, and 3D models using file I/O


- Choose your own color pallet [click me](https://color.adobe.com/create/color-wheel)

```py
import pygame
import sys

# Initialize Pygame
pygame.init()

# Screen dimensions and setup
SCREEN_WIDTH, SCREEN_HEIGHT = 800, 600
screen = pygame.display.set_mode((SCREEN_WIDTH, SCREEN_HEIGHT))
pygame.display.set_caption("Game State Management Example")

# Colors
WHITE = (255, 255, 255)
BLACK = (0, 0, 0)
GRAY = (180, 180, 180)
BLUE = (50, 50, 255)

# Fonts
font = pygame.font.SysFont("Arial", 36)

# -----------------------------------------------------------
# Base class for all game states
# -----------------------------------------------------------
class GameState:
    def __init__(self, game):
        self.game = game

    def handle_events(self, events):
        pass

    def update(self):
        pass

    def draw(self, screen):
        pass

# -----------------------------------------------------------
# MENU STATE
# -----------------------------------------------------------
class MenuState(GameState):
    def draw(self, screen):
        screen.fill(GRAY)
        title_text = font.render("Main Menu", True, BLACK)
        play_text = font.render("Press ENTER to Play", True, BLUE)
        quit_text = font.render("Press ESC to Quit", True, BLUE)
        screen.blit(title_text, (SCREEN_WIDTH//2 - title_text.get_width()//2, 150))
        screen.blit(play_text, (SCREEN_WIDTH//2 - play_text.get_width()//2, 300))
        screen.blit(quit_text, (SCREEN_WIDTH//2 - quit_text.get_width()//2, 360))

    def handle_events(self, events):
        for event in events:
            if event.type == pygame.QUIT:
                pygame.quit()
                sys.exit()
            elif event.type == pygame.KEYDOWN:
                if event.key == pygame.K_RETURN:
                    self.game.change_state(PlayState(self.game))
                elif event.key == pygame.K_ESCAPE:
                    pygame.quit()
                    sys.exit()

# -----------------------------------------------------------
# PLAY STATE
# -----------------------------------------------------------
class PlayState(GameState):
    def __init__(self, game):
        super().__init__(game)
        self.player = pygame.Rect(380, 280, 40, 40)
        self.speed = 5

    def handle_events(self, events):
        for event in events:
            if event.type == pygame.QUIT:
                pygame.quit()
                sys.exit()
            elif event.type == pygame.KEYDOWN:
                if event.key == pygame.K_p:
                    self.game.change_state(PauseState(self.game))
                elif event.key == pygame.K_ESCAPE:
                    self.game.change_state(MenuState(self.game))

    def update(self):
        keys = pygame.key.get_pressed()
        if keys[pygame.K_LEFT]:
            self.player.x -= self.speed
        if keys[pygame.K_RIGHT]:
            self.player.x += self.speed
        if keys[pygame.K_UP]:
            self.player.y -= self.speed
        if keys[pygame.K_DOWN]:
            self.player.y += self.speed

    def draw(self, screen):
        screen.fill(WHITE)
        pygame.draw.rect(screen, BLUE, self.player)
        text = font.render("Press P to Pause | ESC for Menu", True, BLACK)
        screen.blit(text, (20, 20))

# -----------------------------------------------------------
# PAUSE STATE
# -----------------------------------------------------------
class PauseState(GameState):
    def draw(self, screen):
        screen.fill(GRAY)
        pause_text = font.render("Game Paused", True, BLACK)
        resume_text = font.render("Press R to Resume", True, BLUE)
        menu_text = font.render("Press ESC for Menu", True, BLUE)
        screen.blit(pause_text, (SCREEN_WIDTH//2 - pause_text.get_width()//2, 200))
        screen.blit(resume_text, (SCREEN_WIDTH//2 - resume_text.get_width()//2, 300))
        screen.blit(menu_text, (SCREEN_WIDTH//2 - menu_text.get_width()//2, 360))

    def handle_events(self, events):
        for event in events:
            if event.type == pygame.QUIT:
                pygame.quit()
                sys.exit()
            elif event.type == pygame.KEYDOWN:
                if event.key == pygame.K_r:
                    self.game.change_state(PlayState(self.game))
                elif event.key == pygame.K_ESCAPE:
                    self.game.change_state(MenuState(self.game))

# -----------------------------------------------------------
# GAME CLASS - handles main loop and state management
# -----------------------------------------------------------
class Game:
    def __init__(self):
        self.clock = pygame.time.Clock()
        self.running = True
        self.state = MenuState(self)

    def change_state(self, new_state):
        self.state = new_state

    def run(self):
        while self.running:
            events = pygame.event.get()
            self.state.handle_events(events)
            self.state.update()
            self.state.draw(screen)
            pygame.display.flip()
            self.clock.tick(60)

# -----------------------------------------------------------
# Run the game
# -----------------------------------------------------------
if __name__ == "__main__":
    Game().run()

```