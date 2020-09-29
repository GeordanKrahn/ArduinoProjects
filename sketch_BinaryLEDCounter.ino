//This program allows LED's to act as the states for a binary number
//The lights will turn on or off according to the number of times 
//the connected button has been pressed
//feel free to use this code in your project
//LEDS should be connected in series with the first LED representing 
//the lowest values placed on the right hand side(for your project)
//created by Geordan Krahn

int switchState = 0;//to read state on pin(button press)
const int waitTime = 100;//wait time delay button press in ms
const int inputPin = 2; //input pin 2 to read button press
int counter = 0;
const int counterLimit = 16;

//Can have what ever colours make sense for your project
const int LED_1 = 3; // red LED pin 3
const int LED_2 = 4;// green LED pin 4
const int LED_3 = 5;// blue LED pin 5
const int LED_4 = 7;// yellow LED pin 7

void setup() {
  // put your setup code here, to run once:
  pinMode(inputPin, INPUT);
  pinMode(LED_1, OUTPUT);
  pinMode(LED_2, OUTPUT);
  pinMode(LED_3, OUTPUT);
  pinMode(LED_4, OUTPUT);
}

//Check if the button is being pressed
int checkState() {
  //update switchstate
  switchState = digitalRead(inputPin);
  //if the button is being pressed
  if (switchState == HIGH) {
    //wait for user to let go
    delay(waitTime);
    //see if user is still pushing button
    switchState = digitalRead(inputPin);
    //if the button was let go, increment
    if (switchState == LOW) {
      return 1;
    } else {
      return 0;
    }
  } else {
    return 0;
  }
}

void updateLED()
{
  //make sure the number is not higher than max
  if (counter < counterLimit) {
    //if not higher than max, update number
    counter += checkState();
    //test cases for LEDs
    //for the far left LED numbers 8-15
    if (counter >= 8) {
      digitalWrite(LED_1, HIGH);
    } else {
      digitalWrite(LED_1, LOW);
    }
    //for the next LED to the right, numbers 4-7 and 12-15
    if (((counter >= 4) && (counter <= 7)) || ((counter >= 12) && (counter <= 15))) {
      digitalWrite(LED_2, HIGH);
    } else {
      digitalWrite(LED_2, LOW);
    }
    //for the next LED to the right, numbers 2,3,6,7,10,11,14,15
    if ((counter == 2) || (counter == 3) || (counter == 6) || (counter == 7) || (counter == 10) || (counter == 11) || (counter == 14) || (counter == 15)) {
      digitalWrite(LED_3, HIGH);
    } else {
      digitalWrite(LED_3, LOW);
    }
    //for the last LED, each odd number
    if ((counter % 2) == 1) {
      digitalWrite(LED_4, HIGH);
    } else {
      digitalWrite(LED_4, LOW);
    }
    //if counter is max value, reset counter
  } else {
    counter = 0;
  }
}
void loop() {
  updateLED();
}
