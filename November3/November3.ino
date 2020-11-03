const int blueLED = 2;
const int greenLED = 4;
const int yellowLED = 6;
const int redLED = 8;

// Array of LED pins
const int leds[4] = {blueLED, greenLED, yellowLED, redLED};

// Array of button input pins
byte buts[4] = {A0,A1,A2,A3};

// Iterator for loop thing
int iter = 0;

void setup() {
  pinMode(2, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(A3, INPUT);
  Serial.begin(9600);
}

void loop() {
  // Light up current LED
  digitalWrite(leds[iter], HIGH);
  delay(100);
  digitalWrite(leds[iter], LOW);

  // If the current LED's corresponding button is pressed, light everything up
  if(digitalRead(buts[iter]) == HIGH){
      Serial.print(digitalRead(buts[iter]));
      victoryDance();
  }

  // Iterate, or wrap back to 0
  iter++;
  if(iter >= 4){
    iter = iter % 4;
  }
}

void victoryDance(){
  // Light up all the LEDs for half a second
  for(int i = 0; i < 4; i++){
    digitalWrite(leds[i], HIGH);
  }
  delay(500);
  for(int i = 0; i < 4; i++){
    digitalWrite(leds[i], LOW);
  }
}
