## Micro controller: Arduino UNO

### Ardunio uno specification

- Specification [Click me](https://docs.arduino.cc/hardware/uno-rev3/#tech-specs)

<br>

### Where to download arduino IDE

- Download Arduino IDE [Click me](https://www.arduino.cc/en/software)
- Optional [Driver](https://github.com/joysmith/KU-UIT/raw/refs/heads/main/AI%20for%20Edge%20IoT%20-4%20Sem/assets/resource/pololu-cp2102-windows-220616.zip)

<br>

### How to Select sketch

- From menu select file--> example--> digital--> BlinkwithoutDelay

<br>

### The Arduino IDE - Understanding the Preferences pane<a id="55"></a>

<img src="assets/images/1.png" width="700">

<br>

### How to upload a sketch to your Arduino<a id="57"></a>

- go to menu Files--> Example--> basic--> blink
- go to menu Tools--> Boards--> arduino avr board--> arduino uno
- go to menu Tools--> Port--> COM(arduino)

```ino

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(LED_BUILTIN, HIGH);  // turn the LED on (HIGH is the voltage level)
  delay(1000);                      // wait for a second

  digitalWrite(LED_BUILTIN, LOW);  // turn the LED off by making the voltage LOW
  delay(1000);                     // wait for a second
}

```

- click on ✅ to compile, then ➡️ to upload sketch on uno

<br>

### How to use serial monitor

<img src="assets/images/3.png" width="700">

- go to menu Files--> Example--> basic--> blink
- go to menu Tools--> Boards--> arduino avr board--> arduino uno
- go to menu Tools--> Port--> COM(arduino)

```ino

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(LED_BUILTIN, HIGH);  // turn the LED on (HIGH is the voltage level)
  delay(1000);                      // wait for a second
  Serial.println("ON");

  digitalWrite(LED_BUILTIN, LOW);  // turn the LED off by making the voltage LOW
  delay(1000);                     // wait for a second
  Serial.println("OFF");
}

```

- click on ✅ to compile, then ➡️ to upload sketch on uno
- go to menu Tools--> Serial Monitor

<br>

### How to use Serial Plotter

<img src="assets/images/2.png" width="700">

- go to menu Files--> Example--> basic--> blink
- go to menu Tools--> Boards--> arduino avr board--> arduino uno
- go to menu Tools--> Port--> COM(arduino)

```ino

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(LED_BUILTIN, HIGH);  // turn the LED on (HIGH is the voltage level)
  delay(1000);                      // wait for a second
  Serial.println(10);

  digitalWrite(LED_BUILTIN, LOW);  // turn the LED off by making the voltage LOW
  delay(1000);                     // wait for a second
  Serial.println(0);
}

```

- click on ✅ to compile, then ➡️ to upload sketch on uno
- go to menu Tools--> Serial Plotter

<br>

### Documentation

- Serial communication documentation [Click me](https://www.arduino.cc/reference/en/language/functions/communication/serial/read/)

- Language reference documentation [Click me](https://docs.arduino.cc/language-reference/)

<br>

## Tools
