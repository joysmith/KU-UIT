# UID Symposium 2026

## Setting up the system

1. Download Arduino Ide [click me](https://www.arduino.cc/en/software/)

2. (Optional) Download Driver: In case Arduino Ide couldn't detect Arduino uno board [click me](https://github.com/joysmith/KU-UIT/raw/refs/heads/main/UID%20Symposium%202026/assets/driver/arduino%20driver.zip)

3. Testing Arduino UNO board: Run blink LED Example
	- Go to File--> Example--> Basic--> Blink
	- Select Arduino Uno board: Tools--> Board--> Arduino AVR Board-->Arduino uno
	- Select Port: Tools--> Ports--> Select Com port
	- Click on Verify, then Click on Upload

4. Editing Arduino Blink LED code: make LED Blink faster
	- Click on Verify, then Click on Upload

5. Simulation _Optional_
    - Simulation tools: [wokwi](https://wokwi.com/)
    - Simulation tools: [cirkitdesigner](https://app.cirkitdesigner.com/)

<br>
<br>

## VIBE CODING:

1. Go to [ChatGPT](https://www.google.com/aclk?sa=L&pf=1&ai=DChsSEwjbqMDS08CTAxWrWw8CHR6NKD4YACICCAEQABoCdGI&co=1&ase=2&gclid=Cj0KCQjw1ZjOBhCmARIsADDuFTC0DZPSruZP54F7LvRZ0aHhqChYy4ccF1CbrihSBecpnenXT9UpePEaAt1LEALw_wcB&cid=CAASZeRov38oKPu2lxNMiOcoO3k87MWn74rpid3mnXVHF22hAJyWcOsp2j61IIOtKC69MNiahfPtlSXjqjkpsgQH1oZ6ZaAgXHEmK6HlHrdYmnBaS308UYHiOXcoTGzI8qUiMBO_pzcQ&cce=2&category=acrcp_v1_32&sig=AOD64_2wDis2nXmbhQNXCCxa2ritvjeIYw&q&nis=4&adurl=https://chatgpt.com?utm_source%3Dgoogle%26utm_medium%3Dpaid_search%26utm_campaign%3DGOOG_C_SEM_GBR_Core_CHT_BAU_ACQ_PER_MIX_ALL_APAC_IN_EN_032525%26c_id%3D22370388714%26c_agid%3D177344203135%26c_crid%3D741704613486%26c_kwid%3Dkwd-1927227100722%26c_ims%3D%26c_pms%3D9061748%26c_nw%3Dg%26c_dvc%3Dc%26gad_source%3D1%26gad_campaignid%3D22370388714%26gbraid%3D0AAAAA-I0E5dHS_TGm2L2ZY5-7ZejtAH0U%26gclid%3DCj0KCQjw1ZjOBhCmARIsADDuFTC0DZPSruZP54F7LvRZ0aHhqChYy4ccF1CbrihSBecpnenXT9UpePEaAt1LEALw_wcB&ved=2ahUKEwiagrzS08CTAxUoqFYBHWMVEjsQ0Qx6BAgMEAE) and type prompt __"generate happy birthday melody for arduino uno also tell connection pins"__

```sh
generate happy birthday tune melody for arduino uno also tell connection pins

generate Ode to joy for arduino uno also tell connection pins

or any other melody
```

```js
// Ode to joy music
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


<br>
<br>

## Mini Simple Piano

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





























