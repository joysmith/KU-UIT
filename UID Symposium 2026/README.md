# UID Symposium 2026

## Setting up the system

1. Download Arduino Ide [click me](https://www.arduino.cc/en/software/)

2. (Optional) Download Driver: In case Arduino Ide couldn't detect Arduino uno board [click me](https://github.com/joysmith/KU-UIT/raw/refs/heads/main/UID%20Symposium%202026/assets/driver/arduino%20driver.zip)

3. Testing Arduino UNO board: Run blink LED Example
	- Go to File--> Example--> Basic--> Blink
	- Select Arduino Uno board: Tools--> Board--> Arduino AVR Board-->Arduino uno
	- Select Port: Tools--> Ports--> <Select Com port>
	- Click on Verify, then Click on Upload

4. Editing Arduino Blink LED code: make LED Blink faster
	- Click on Verify, then Click on Upload

<br>
<br>

## VIBE CODING:

1. Go to ChatGPT and type prompt "generate happy birthday tune melody for arduino uno also tell connection pins"

```js
#define BUZZER 8

// Notes
#define NOTE_E4 330
#define NOTE_F4 349
#define NOTE_G4 392
#define NOTE_A4 440
#define NOTE_B4 494
#define NOTE_C5 523
#define NOTE_D5 587

int tempo = 700; // slower tempo

// Full melody (extended)
int melody[] = {

  // Phrase A
  NOTE_E4, NOTE_E4, NOTE_F4, NOTE_G4,
  NOTE_G4, NOTE_F4, NOTE_E4, NOTE_D5,
  NOTE_C5, NOTE_C5, NOTE_D5, NOTE_E4,
  NOTE_E4, NOTE_D5, NOTE_D5,

  // Phrase A repeat
  NOTE_E4, NOTE_E4, NOTE_F4, NOTE_G4,
  NOTE_G4, NOTE_F4, NOTE_E4, NOTE_D5,
  NOTE_C5, NOTE_C5, NOTE_D5, NOTE_E4,
  NOTE_D5, NOTE_C5, NOTE_C5,

  // Phrase B (variation)
  NOTE_D5, NOTE_D5, NOTE_E4, NOTE_C5,
  NOTE_D5, NOTE_E4, NOTE_F4, NOTE_E4,
  NOTE_C5, NOTE_D5, NOTE_E4, NOTE_F4,
  NOTE_E4, NOTE_D5, NOTE_C5,

  // Phrase A (final return)
  NOTE_E4, NOTE_E4, NOTE_F4, NOTE_G4,
  NOTE_G4, NOTE_F4, NOTE_E4, NOTE_D5,
  NOTE_C5, NOTE_C5, NOTE_D5, NOTE_E4,
  NOTE_D5, NOTE_C5, NOTE_C5
};

// Durations
int durations[] = {

  // A
  4,4,4,4,
  4,4,4,4,
  4,4,4,4,
  4,4,2,

  // A repeat
  4,4,4,4,
  4,4,4,4,
  4,4,4,4,
  4,4,2,

  // B
  4,4,4,4,
  4,4,4,4,
  4,4,4,4,
  4,4,2,

  // A final
  4,4,4,4,
  4,4,4,4,
  4,4,4,4,
  4,4,2
};

void setup() {
  int size = sizeof(melody) / sizeof(int);

  for (int i = 0; i < size; i++) {
    int noteDuration = tempo / durations[i];

    tone(BUZZER, melody[i], noteDuration);

    int pause = noteDuration * 1.5;
    delay(pause);

    noTone(BUZZER);
  }
}

void loop() {
  // Plays once
}
```


2. piano

```js
#define BUZZER 10

int buttons[] = {2,3,4,5,6,7,8,9};

int notes[] = {
  262, // C4
  294, // D4
  330, // E4
  349, // F4
  392, // G4
  440, // A4
  494, // B4
  523  // C5
};

void setup() {
  for(int i = 0; i < 8; i++) {
    pinMode(buttons[i], INPUT_PULLUP);
  }
  pinMode(BUZZER, OUTPUT);
}

void loop() {

  bool isPlaying = false;

  for(int i = 0; i < 8; i++) {

    if(digitalRead(buttons[i]) == LOW) {
      tone(BUZZER, notes[i]);  // REAL musical tone
      isPlaying = true;
      break;
    }
  }

  if(!isPlaying) {
    noTone(BUZZER); // stop sound
  }
} 
```





























