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
    - Simulation tools: [cirkitdesigner](https://app.cirkitdesigner.com/)
    - 01 [Happy Birthday with buzzer](https://app.cirkitdesigner.com/project/9e4ce60e-bb97-4b6d-af90-5df06dac0b38)
    - 02 [Twinkle Twinkle little star with buzzer controlled with push button](https://app.cirkitdesigner.com/project/a9028b93-60c9-417c-a2f9-fde65e167484) 
    - 03 [Super Mario with buzzer controlled with push button + LED](https://app.cirkitdesigner.com/project/aae148cf-cd47-47de-8233-a2e0fa615c23)
    - 04 [Mini piano](https://app.cirkitdesigner.com/project/ed31b82a-8ca5-4953-ad53-ba3a7b24c813)
    - 05 [Melody Beat box](https://app.cirkitdesigner.com/project/e21881ca-0a24-462b-b530-3df98f946eb5)
    - 06 []()

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
#define BUZZER 10

// Notes frequencies
#define NOTE_C4  262
#define NOTE_D4  294
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_G4  392
#define NOTE_A4  440
#define NOTE_AS4 466
#define NOTE_C5  523
#define NOTE_D5  587

void setup() {
  playHappyBirthday();
}

void loop() {
  // nothing here
}

void playTone(int note, int duration) {
  tone(BUZZER, note, duration);
  delay(duration * 1.3); // slight pause between notes
  noTone(BUZZER);
}

void playHappyBirthday() {
  // Happy Birthday melody

  playTone(NOTE_C4, 300);
  playTone(NOTE_C4, 200);
  playTone(NOTE_D4, 500);
  playTone(NOTE_C4, 500);
  playTone(NOTE_F4, 500);
  playTone(NOTE_E4, 1000);

  playTone(NOTE_C4, 300);
  playTone(NOTE_C4, 200);
  playTone(NOTE_D4, 500);
  playTone(NOTE_C4, 500);
  playTone(NOTE_G4, 500);
  playTone(NOTE_F4, 1000);

  playTone(NOTE_C4, 300);
  playTone(NOTE_C4, 200);
  playTone(NOTE_C5, 500);
  playTone(NOTE_A4, 500);
  playTone(NOTE_F4, 500);
  playTone(NOTE_E4, 500);
  playTone(NOTE_D4, 1000);

  playTone(NOTE_AS4, 300);
  playTone(NOTE_AS4, 200);
  playTone(NOTE_A4, 500);
  playTone(NOTE_F4, 500);
  playTone(NOTE_G4, 500);
  playTone(NOTE_F4, 1000);
}
```

2. Connect +ive end of buzzer to ardunino pin no 10 and other end to GND arduino pin.
  	- Click on Verify, then Click on Upload

<br>
<br>

## Mini Simple Piano

1. piano

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





























