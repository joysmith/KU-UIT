# 5. Design a basic game application layer including game state management (menu, play, pause)

- Choose your own color pallet [click me](https://color.adobe.com/create/color-wheel)

```py
import pygame
import sys

# -----------------------------------------------------------
# Initialize the Pygame library
# -----------------------------------------------------------
pygame.init()

# -----------------------------------------------------------
# Set up screen dimensions and create the main game window
# -----------------------------------------------------------
SCREEN_WIDTH, SCREEN_HEIGHT = 800, 600
screen = pygame.display.set_mode((SCREEN_WIDTH, SCREEN_HEIGHT))
pygame.display.set_caption("Game State Management Example")

# -----------------------------------------------------------
# Define some common RGB color values for use throughout the game
# -----------------------------------------------------------
WHITE = (255, 255, 255)
BLACK = (0, 0, 0)
GRAY = (180, 180, 180)
BLUE = (50, 50, 255)

# -----------------------------------------------------------
# Create a font object for rendering text on the screen
# -----------------------------------------------------------
font = pygame.font.SysFont("Arial", 36)

# ===================================================================
#                     BASE GAME STATE CLASS
# ===================================================================
class GameState:
    """
    Base class for all game states (e.g., menu, play, pause).

    Each state should implement:
        - handle_events(events): process user input or system events
        - update(): update game logic (e.g., movement, physics)
        - draw(screen): render visuals on the screen
    """

    def __init__(self, game):
        self.game = game  # Reference to the Game object for switching states

    def handle_events(self, events):
        pass

    def update(self):
        pass

    def draw(self, screen):
        pass


# ===================================================================
#                     MENU STATE
# ===================================================================
class MenuState(GameState):
    """
    Represents the main menu of the game.
    Allows the player to start the game or quit.
    """

    def draw(self, screen):
        """Draw the menu background and text options."""
        screen.fill(GRAY)

        # Render the menu text
        title_text = font.render("Main Menu", True, BLACK)
        play_text = font.render("Press ENTER to Play", True, BLUE)
        quit_text = font.render("Press ESC to Quit", True, BLUE)

        # Center text on the screen
        screen.blit(title_text, (SCREEN_WIDTH//2 - title_text.get_width()//2, 150))
        screen.blit(play_text, (SCREEN_WIDTH//2 - play_text.get_width()//2, 300))
        screen.blit(quit_text, (SCREEN_WIDTH//2 - quit_text.get_width()//2, 360))

    def handle_events(self, events):
        """Handle key presses for starting or quitting the game."""
        for event in events:
            if event.type == pygame.QUIT:
                pygame.quit()
                sys.exit()

            elif event.type == pygame.KEYDOWN:
                if event.key == pygame.K_RETURN:
                    # Switch to the PlayState when ENTER is pressed
                    self.game.change_state(PlayState(self.game))
                elif event.key == pygame.K_ESCAPE:
                    # Exit the game when ESC is pressed
                    pygame.quit()
                    sys.exit()


# ===================================================================
#                     PLAY STATE
# ===================================================================
class PlayState(GameState):
    """
    Represents the active gameplay state.
    The player can move a blue square around the screen.
    """

    def __init__(self, game):
        super().__init__(game)

        # Create a simple player represented as a rectangle
        self.player = pygame.Rect(380, 280, 40, 40)
        self.speed = 5  # Movement speed (pixels per frame)

    def handle_events(self, events):
        """Handle pause or exit input during gameplay."""
        for event in events:
            if event.type == pygame.QUIT:
                pygame.quit()
                sys.exit()

            elif event.type == pygame.KEYDOWN:
                if event.key == pygame.K_p:
                    # Switch to PauseState when 'P' is pressed
                    self.game.change_state(PauseState(self.game))
                elif event.key == pygame.K_ESCAPE:
                    # Return to main menu when ESC is pressed
                    self.game.change_state(MenuState(self.game))

    def update(self):
        """Update player position based on key presses."""
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
        """Render the game scene."""
        screen.fill(WHITE)

        # Draw the player as a blue square
        pygame.draw.rect(screen, BLUE, self.player)

        # Display helpful controls text
        text = font.render("Press P to Pause | ESC for Menu", True, BLACK)
        screen.blit(text, (20, 20))


# ===================================================================
#                     PAUSE STATE
# ===================================================================
class PauseState(GameState):
    """
    Represents a paused version of the game.
    The game stops updating movement, but displays pause options.
    """

    def draw(self, screen):
        """Render the pause menu overlay."""
        screen.fill(GRAY)

        # Render pause menu text
        pause_text = font.render("Game Paused", True, BLACK)
        resume_text = font.render("Press R to Resume", True, BLUE)
        menu_text = font.render("Press ESC for Menu", True, BLUE)

        # Center text vertically
        screen.blit(pause_text, (SCREEN_WIDTH//2 - pause_text.get_width()//2, 200))
        screen.blit(resume_text, (SCREEN_WIDTH//2 - resume_text.get_width()//2, 300))
        screen.blit(menu_text, (SCREEN_WIDTH//2 - menu_text.get_width()//2, 360))

    def handle_events(self, events):
        """Handle resume or menu navigation keys."""
        for event in events:
            if event.type == pygame.QUIT:
                pygame.quit()
                sys.exit()

            elif event.type == pygame.KEYDOWN:
                if event.key == pygame.K_r:
                    # Resume the game (return to PlayState)
                    self.game.change_state(PlayState(self.game))
                elif event.key == pygame.K_ESCAPE:
                    # Return to the main menu
                    self.game.change_state(MenuState(self.game))


# ===================================================================
#                     GAME CONTROLLER CLASS
# ===================================================================
class Game:
    """
    The Game class manages the overall flow of the program.
    It keeps track of the current state (menu, play, pause)
    and handles switching between them.
    """

    def __init__(self):
        # Create a clock object to control frame rate
        self.clock = pygame.time.Clock()

        # Controls whether the main loop should continue running
        self.running = True

        # Start the game in the main menu
        self.state = MenuState(self)

    def change_state(self, new_state):
        """
        Replace the current game state with a new one.
        Each state handles its own drawing and event logic.
        """
        self.state = new_state

    def run(self):
        """Main game loop that updates and draws the active state."""
        while self.running:
            # Collect all Pygame events (keyboard, mouse, etc.)
            events = pygame.event.get()

            # Let the active state handle input events
            self.state.handle_events(events)

            # Update game logic (only for active states like PlayState)
            self.state.update()

            # Draw the current state to the screen
            self.state.draw(screen)

            # Refresh the screen to display new frame
            pygame.display.flip()

            # Limit the frame rate to 60 FPS
            self.clock.tick(60)


# ===================================================================
#                     PROGRAM ENTRY POINT
# ===================================================================
if __name__ == "__main__":
    # Create the game instance and start the main loop
    Game().run()


```

<br>
<br>


#### Version 2: super mario


```py
import pygame
import sys

# -----------------------------------------------------------
# Initialize the Pygame engine. This must be done before
# creating windows, fonts, or any Pygame objects.
# -----------------------------------------------------------
pygame.init()

# -----------------------------------------------------------
# Screen setup
# -----------------------------------------------------------
SCREEN_WIDTH, SCREEN_HEIGHT = 800, 600  # Window size in pixels
screen = pygame.display.set_mode((SCREEN_WIDTH, SCREEN_HEIGHT))
pygame.display.set_caption("Super Mario Menu Example")

# -----------------------------------------------------------
# Define some basic colors as RGB tuples for convenience
# -----------------------------------------------------------
WHITE = (255, 255, 255)
BLACK = (0, 0, 0)
RED = (200, 0, 0)
YELLOW = (255, 215, 0)
BLUE = (0, 120, 255)
DARK_BLUE = (0, 0, 80)

# -----------------------------------------------------------
# Font setup
# -----------------------------------------------------------
# Large font for titles, medium for menu options, small for hints
font_title = pygame.font.SysFont("Arial", 72, bold=True)
font_menu = pygame.font.SysFont("Arial", 42)
font_small = pygame.font.SysFont("Arial", 24)

# ===================================================================
#                     BASE GAME STATE CLASS
# ===================================================================
class GameState:
    """
    The base class for all game states (e.g., Menu, Play, Options).

    Each state defines how it:
        - Handles input events (keyboard, mouse)
        - Updates logic each frame
        - Draws content to the screen
    """

    def __init__(self, game):
        # Reference to the main Game controller (used to switch states)
        self.game = game

    def handle_events(self, events):
        """Process keyboard, mouse, and system events."""
        pass

    def update(self):
        """Update game logic or animations each frame."""
        pass

    def draw(self, screen):
        """Render all graphics for this state to the screen."""
        pass


# ===================================================================
#                     MARIO MENU STATE
# ===================================================================
class MarioMenu(GameState):
    """
    The main title screen inspired by classic Super Mario games.
    
    Features:
        - "SUPER MARIO" title text at the top.
        - Menu options: Start Game, Options, Exit.
        - Red arrow indicating the current selection.
        - Keyboard navigation (↑, ↓, Enter).
    """

    def __init__(self, game):
        super().__init__(game)

        # Define the menu options that will be shown
        self.options = ["Start Game", "Options", "Exit"]

        # Keeps track of which option is currently highlighted (0 = top)
        self.selected_index = 0

        # Background color (deep blue like Mario title screens)
        self.bg_color = DARK_BLUE

        # (Optional) If you had a logo image, you could load it here:
        # self.logo = pygame.image.load("mario_logo.png").convert_alpha()

    # -----------------------------------------------------------
    # Handle keyboard input for navigating the menu
    # -----------------------------------------------------------
    def handle_events(self, events):
        """
        Respond to player input:
            - UP / DOWN arrow keys to change selection
            - ENTER to confirm choice
            - Window close button exits the game
        """
        for event in events:
            # Handle window close
            if event.type == pygame.QUIT:
                pygame.quit()
                sys.exit()

            # Handle key presses
            elif event.type == pygame.KEYDOWN:
                if event.key == pygame.K_UP:
                    # Move selection up (wraps around if at top)
                    self.selected_index = (self.selected_index - 1) % len(self.options)
                elif event.key == pygame.K_DOWN:
                    # Move selection down (wraps around if at bottom)
                    self.selected_index = (self.selected_index + 1) % len(self.options)
                elif event.key == pygame.K_RETURN:
                    # Confirm the selected option
                    self.activate_option()

    # -----------------------------------------------------------
    # Determine what happens when the player selects a menu item
    # -----------------------------------------------------------
    def activate_option(self):
        """
        Executes the action corresponding to the currently selected menu item.
        """
        selected = self.options[self.selected_index]

        if selected == "Start Game":
            # Switch to the gameplay screen
            self.game.change_state(MarioPlay(self.game))
        elif selected == "Options":
            # Open the options screen
            self.game.change_state(MarioOptions(self.game))
        elif selected == "Exit":
            # Close the game window and terminate the program
            pygame.quit()
            sys.exit()

    # -----------------------------------------------------------
    # Draw the title screen layout
    # -----------------------------------------------------------
    def draw(self, screen):
        """
        Render the title screen elements:
            - Title text
            - Menu options with highlight arrow
            - On-screen instructions
        """
        # Fill the background with a dark blue color
        screen.fill(self.bg_color)

        # --- Title Text ---
        title = font_title.render("SUPER MARIO", True, YELLOW)
        # Center horizontally, place near top
        screen.blit(title, (SCREEN_WIDTH // 2 - title.get_width() // 2, 120))

        # --- Menu Options ---
        for i, option in enumerate(self.options):
            # Highlight the selected option in white, others gray
            color = WHITE if i == self.selected_index else (150, 150, 150)

            # Render the text surface for this option
            text = font_menu.render(option, True, color)

            # Position each option vertically spaced 60px apart
            x = SCREEN_WIDTH // 2 - text.get_width() // 2
            y = 300 + i * 60
            screen.blit(text, (x, y))

            # Draw the red arrow ("▶") next to the selected option
            if i == self.selected_index:
                arrow = font_menu.render("▶", True, RED)
                screen.blit(arrow, (x - 60, y))

        # --- Instructions at the bottom ---
        info = font_small.render("Use ↑ ↓ to navigate, ENTER to select", True, WHITE)
        screen.blit(info, (SCREEN_WIDTH // 2 - info.get_width() // 2, 520))


# ===================================================================
#                     GAMEPLAY STATE
# ===================================================================
class MarioPlay(GameState):
    """
    Represents the active gameplay screen.
    For demonstration, this shows a red square (Mario block)
    that the player can move around using the arrow keys.
    """

    def __init__(self, game):
        super().__init__(game)

        # Create a simple rectangle to represent the player
        self.player_rect = pygame.Rect(380, 280, 40, 40)

        # Player movement speed (pixels per frame)
        self.speed = 5

    def handle_events(self, events):
        """
        Handle user input during gameplay:
            - ESC returns to the main menu
            - Window close exits the game
        """
        for event in events:
            if event.type == pygame.QUIT:
                pygame.quit()
                sys.exit()
            elif event.type == pygame.KEYDOWN:
                # ESC returns to main menu
                if event.key == pygame.K_ESCAPE:
                    self.game.change_state(MarioMenu(self.game))

    def update(self):
        """
        Update the player's position based on arrow key input.
        """
        keys = pygame.key.get_pressed()

        if keys[pygame.K_LEFT]:
            self.player_rect.x -= self.speed
        if keys[pygame.K_RIGHT]:
            self.player_rect.x += self.speed
        if keys[pygame.K_UP]:
            self.player_rect.y -= self.speed
        if keys[pygame.K_DOWN]:
            self.player_rect.y += self.speed

    def draw(self, screen):
        """
        Draw the gameplay environment.
        Currently includes a simple blue background and player block.
        """
        # Fill background with sky blue
        screen.fill((100, 200, 255))

        # Draw player as a red block (placeholder for Mario sprite)
        pygame.draw.rect(screen, (255, 0, 0), self.player_rect)

        # Display on-screen help text
        text = font_small.render("Playing... Press ESC to return to Menu", True, BLACK)
        screen.blit(text, (SCREEN_WIDTH // 2 - text.get_width() // 2, 550))


# ===================================================================
#                     OPTIONS STATE
# ===================================================================
class MarioOptions(GameState):
    """
    Simple options menu that demonstrates switching between states.
    """

    def handle_events(self, events):
        """
        Handle input for the options screen:
            - ESC returns to main menu
            - Window close exits game
        """
        for event in events:
            if event.type == pygame.QUIT:
                pygame.quit()
                sys.exit()
            elif event.type == pygame.KEYDOWN:
                if event.key == pygame.K_ESCAPE:
                    self.game.change_state(MarioMenu(self.game))

    def draw(self, screen):
        """
        Draw the options screen with placeholder text.
        """
        screen.fill((30, 30, 30))

        title = font_title.render("OPTIONS", True, YELLOW)
        screen.blit(title, (SCREEN_WIDTH // 2 - title.get_width() // 2, 200))

        info = font_small.render("Press ESC to return to Menu", True, WHITE)
        screen.blit(info, (SCREEN_WIDTH // 2 - info.get_width() // 2, 500))


# ===================================================================
#                     MAIN GAME CONTROLLER
# ===================================================================
class Game:
    """
    The central controller that manages:
        - The current active state (Menu, Play, Options)
        - The main game loop
        - Frame timing and transitions between states
    """

    def __init__(self):
        # Create a clock to manage frame rate (60 FPS)
        self.clock = pygame.time.Clock()

        # Running flag controls whether the main loop continues
        self.running = True

        # Start with the main menu
        self.state = MarioMenu(self)

    def change_state(self, new_state):
        """
        Replaces the current state with a new one.
        This allows easy transitions (e.g., Menu -> Play).
        """
        self.state = new_state

    def run(self):
        """
        Main game loop:
            - Collect and handle events
            - Update game logic
            - Draw the current state
            - Refresh display at 60 FPS
        """
        while self.running:
            # Gather all pending Pygame events
            events = pygame.event.get()

            # Delegate event handling, logic, and drawing to the active state
            self.state.handle_events(events)
            self.state.update()
            self.state.draw(screen)

            # Refresh the display to show the latest frame
            pygame.display.flip()

            # Wait to maintain 60 frames per second
            self.clock.tick(60)


# ===================================================================
#                     PROGRAM ENTRY POINT
# ===================================================================
if __name__ == "__main__":
    # Create and run the Game instance
    Game().run()
```

<br>
<br>

#### Version 3: Mobile game subway surfer

```py
import pygame
import sys

# -----------------------------------------------------------
# Initialize Pygame before creating any surfaces or fonts.
# This sets up all internal Pygame modules.
# -----------------------------------------------------------
pygame.init()

# -----------------------------------------------------------
# Define screen dimensions similar to a phone screen (portrait mode).
# -----------------------------------------------------------
SCREEN_WIDTH, SCREEN_HEIGHT = 480, 800
screen = pygame.display.set_mode((SCREEN_WIDTH, SCREEN_HEIGHT))
pygame.display.set_caption("Subway Surfers Menu Example")

# -----------------------------------------------------------
# Define color constants (RGB)
# -----------------------------------------------------------
WHITE = (255, 255, 255)
BLACK = (0, 0, 0)
GRAY = (180, 180, 180)
BLUE = (66, 135, 245)
YELLOW = (255, 223, 0)
GREEN = (0, 200, 100)
RED = (255, 70, 70)

# -----------------------------------------------------------
# Define fonts for different text elements
# -----------------------------------------------------------
font_title = pygame.font.SysFont("Arial", 60, bold=True)
font_button = pygame.font.SysFont("Arial", 32, bold=True)
font_small = pygame.font.SysFont("Arial", 22)


# ===================================================================
#                     BUTTON CLASS
# ===================================================================
class Button:
    """
    Represents a clickable button on the screen.

    Handles:
        - Rendering (color, text)
        - Hover effects
        - Click/touch detection
    """

    def __init__(self, x, y, width, height, text, color, callback):
        # The rectangle defining button position and size
        self.rect = pygame.Rect(x, y, width, height)

        # Button label text and main color
        self.text = text
        self.color = color

        # Function to call when the button is clicked
        self.callback = callback

        # Track whether the cursor/touch is over the button
        self.hovered = False

    def draw(self, surface):
        """Draw the button and its text on the given surface."""
        # Lighten color when hovered for feedback
        color = tuple(min(255, c + 40) for c in self.color) if self.hovered else self.color

        # Draw the button shape (rounded rectangle)
        pygame.draw.rect(surface, color, self.rect, border_radius=15)

        # Render the text and center it inside the button
        text_surface = font_button.render(self.text, True, WHITE)
        text_rect = text_surface.get_rect(center=self.rect.center)
        surface.blit(text_surface, text_rect)

    def handle_event(self, event):
        """Detect hover and click events."""
        if event.type == pygame.MOUSEMOTION:
            # Update hover state when mouse moves
            self.hovered = self.rect.collidepoint(event.pos)

        elif event.type == pygame.MOUSEBUTTONDOWN:
            # If clicked/touched inside button, trigger callback
            if self.rect.collidepoint(event.pos):
                self.callback()


# ===================================================================
#                     BASE GAME STATE CLASS
# ===================================================================
class GameState:
    """
    Abstract parent class for all states (Menu, Shop, Game, etc.)
    Each subclass should override:
        - handle_events()
        - update()
        - draw()
    """

    def __init__(self, game):
        self.game = game

    def handle_events(self, events):
        pass

    def update(self):
        pass

    def draw(self, screen):
        pass


# ===================================================================
#                     MAIN MENU STATE
# ===================================================================
class MainMenu(GameState):
    """
    The main menu screen inspired by Subway Surfers.

    Layout:
        - Game logo at top
        - Character preview in middle (placeholder box)
        - Big PLAY button in the center
        - Smaller Shop, Missions, Settings buttons at bottom
    """

    def __init__(self, game):
        super().__init__(game)

        # Load background image (optional, using solid color here)
        self.bg_color = (50, 160, 255)  # Light blue like Subway Surfers

        # Create interactive buttons
        self.buttons = [
            Button(140, 500, 200, 70, "PLAY", GREEN, lambda: self.game.change_state(PlayState(self.game))),
            Button(40, 700, 100, 50, "Shop", YELLOW, lambda: self.game.change_state(ShopState(self.game))),
            Button(190, 700, 100, 50, "Missions", BLUE, lambda: self.game.change_state(MissionState(self.game))),
            Button(340, 700, 100, 50, "Settings", GRAY, lambda: self.game.change_state(SettingsState(self.game)))
        ]

    def draw(self, screen):
        """Draw all UI elements for the menu."""
        # Fill screen with bright sky color
        screen.fill(self.bg_color)

        # --- Draw Title (Game Logo Placeholder) ---
        title_text = font_title.render("SUBWAY RUNNER", True, YELLOW)
        title_rect = title_text.get_rect(center=(SCREEN_WIDTH // 2, 100))
        screen.blit(title_text, title_rect)

        # --- Character Preview Placeholder ---
        # In a real game, this would show a 3D or sprite character.
        pygame.draw.rect(screen, RED, (140, 200, 200, 250), border_radius=30)
        char_text = font_small.render("Character Preview", True, WHITE)
        char_rect = char_text.get_rect(center=(SCREEN_WIDTH // 2, 440))
        screen.blit(char_text, char_rect)

        # --- Draw All Buttons ---
        for button in self.buttons:
            button.draw(screen)

        # --- Footer Text ---
        footer_text = font_small.render("Tap or Click buttons to navigate", True, WHITE)
        footer_rect = footer_text.get_rect(center=(SCREEN_WIDTH // 2, 780))
        screen.blit(footer_text, footer_rect)

    def handle_events(self, events):
        """Handle button clicks and hover interactions."""
        for event in events:
            if event.type == pygame.QUIT:
                pygame.quit()
                sys.exit()

            # Forward the event to each button to check for clicks or hover
            for button in self.buttons:
                button.handle_event(event)


# ===================================================================
#                     GAMEPLAY STATE
# ===================================================================
class PlayState(GameState):
    """
    Represents the actual running game (simplified mock).
    """

    def handle_events(self, events):
        for event in events:
            if event.type == pygame.QUIT:
                pygame.quit()
                sys.exit()
            elif event.type == pygame.KEYDOWN and event.key == pygame.K_ESCAPE:
                # Return to the main menu
                self.game.change_state(MainMenu(self.game))

    def draw(self, screen):
        """Draw a simple 'game running' placeholder screen."""
        screen.fill((0, 150, 100))
        text = font_button.render("GAME RUNNING!", True, WHITE)
        text_rect = text.get_rect(center=(SCREEN_WIDTH // 2, SCREEN_HEIGHT // 2))
        screen.blit(text, text_rect)

        info = font_small.render("Press ESC to return to Menu", True, WHITE)
        info_rect = info.get_rect(center=(SCREEN_WIDTH // 2, SCREEN_HEIGHT // 2 + 60))
        screen.blit(info, info_rect)


# ===================================================================
#                     SHOP STATE
# ===================================================================
class ShopState(GameState):
    """Mock shop menu where the player can buy items."""

    def handle_events(self, events):
        for event in events:
            if event.type == pygame.QUIT:
                pygame.quit()
                sys.exit()
            elif event.type == pygame.KEYDOWN and event.key == pygame.K_ESCAPE:
                self.game.change_state(MainMenu(self.game))

    def draw(self, screen):
        screen.fill((255, 180, 60))
        text = font_title.render("SHOP", True, WHITE)
        screen.blit(text, (SCREEN_WIDTH // 2 - text.get_width() // 2, 300))
        info = font_small.render("Press ESC to return to Menu", True, WHITE)
        screen.blit(info, (SCREEN_WIDTH // 2 - info.get_width() // 2, 700))


# ===================================================================
#                     MISSIONS STATE
# ===================================================================
class MissionState(GameState):
    """Displays the missions/challenges list."""

    def handle_events(self, events):
        for event in events:
            if event.type == pygame.QUIT:
                pygame.quit()
                sys.exit()
            elif event.type == pygame.KEYDOWN and event.key == pygame.K_ESCAPE:
                self.game.change_state(MainMenu(self.game))

    def draw(self, screen):
        screen.fill((60, 180, 255))
        text = font_title.render("MISSIONS", True, WHITE)
        screen.blit(text, (SCREEN_WIDTH // 2 - text.get_width() // 2, 300))
        info = font_small.render("Press ESC to return to Menu", True, WHITE)
        screen.blit(info, (SCREEN_WIDTH // 2 - info.get_width() // 2, 700))


# ===================================================================
#                     SETTINGS STATE
# ===================================================================
class SettingsState(GameState):
    """Settings screen placeholder (e.g., audio, controls, etc.)"""

    def handle_events(self, events):
        for event in events:
            if event.type == pygame.QUIT:
                pygame.quit()
                sys.exit()
            elif event.type == pygame.KEYDOWN and event.key == pygame.K_ESCAPE:
                self.game.change_state(MainMenu(self.game))

    def draw(self, screen):
        screen.fill((120, 120, 120))
        text = font_title.render("SETTINGS", True, WHITE)
        screen.blit(text, (SCREEN_WIDTH // 2 - text.get_width() // 2, 300))
        info = font_small.render("Press ESC to return to Menu", True, WHITE)
        screen.blit(info, (SCREEN_WIDTH // 2 - info.get_width() // 2, 700))


# ===================================================================
#                     MAIN GAME CLASS
# ===================================================================
class Game:
    """
    The Game class controls:
        - The current active state (menu, shop, game, etc.)
        - The main loop for event handling, updating, and rendering.
    """

    def __init__(self):
        # Pygame clock for controlling FPS (frames per second)
        self.clock = pygame.time.Clock()

        # The game continues to run as long as this flag is True
        self.running = True

        # Start with the main menu screen
        self.state = MainMenu(self)

    def change_state(self, new_state):
        """Switches the current screen/state to another."""
        self.state = new_state

    def run(self):
        """Main game loop: handles events, updates, and draws."""
        while self.running:
            # Collect user inputs (mouse, keyboard, touch)
            events = pygame.event.get()

            # Pass input and logic handling to the current active state
            self.state.handle_events(events)
            self.state.update()
            self.state.draw(screen)

            # Update the window display
            pygame.display.flip()

            # Limit game loop to 60 frames per second for smooth animation
            self.clock.tick(60)


# ===================================================================
#                     PROGRAM ENTRY POINT
# ===================================================================
if __name__ == "__main__":
    # Create and run the game instance
    Game().run()


```