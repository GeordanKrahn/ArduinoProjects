//Simple program to keep track of temperature
//requires Dallas Temperature temp sensor and library
//Connect the data pin to the one wire bus.
//uses the LCD screen to display the temperature
//you are free to use this in your project
//Created by Geordan Krahn

//get the needed libraries
#include<LiquidCrystal.h>
#include<OneWire.h>
#include<DallasTemperature.h>

//one wire bus on pin 7
#define One_Wire_Bus 7

//declare data
int rs = 2; //reset pin
int enable = 3; //enable pin
int d4 = 10, d5 = 11, d6 = 12, d7 = 13; //data pins (4 lane mode)

// initialize devices
LiquidCrystal lcd(rs, enable, d4, d5, d6, d7); 
OneWire oneWire(One_Wire_Bus);
DallasTemperature sensors(&oneWire);

//in milliseconds
//1000ms per 1s
int wait = 550;
int longWait = 800;

void setup() {
  // put your setup code here, to run once:
  lcd.begin(16, 2);
  sensors.begin();
  lcd.setCursor(2,0);
  lcd.print("Temperature");
  lcd.setCursor(5,1);
  lcd.print("Sensor");
}

//cute animated blinking face
void blinky(){
  lcd.setCursor(9, 1);
  lcd.print("('_')");
  delay(wait);
  lcd.setCursor(9, 1);
  lcd.print("('_')");
  delay(wait);
  lcd.setCursor(9, 1);
  lcd.print("(^_^)");
  delay(wait);
}

//uses animated face
void waitTime(){
  blinky();
  blinky();
  blinky();
  blinky();
  delay(longWait);
}

//indicates work
void dotdotdot(){
  delay(longWait);
  lcd.print('.');
  delay(wait);
  lcd.print('.');
  delay(wait);
  lcd.print('.');
  delay(longWait);
}

//the main logic...
//Print Temp in Celcius
void requestTemp(){
  // call sensors.requestTemperatures() to issue a global temperature
  // request to all devices on the bus
  //communicate
  lcd.clear();
  lcd.setCursor(4, 0);
  lcd.print("Reading");
  lcd.setCursor(4, 1);
  lcd.print("Temps");
  dotdotdot();//tell users we are working...(2700)
  sensors.requestTemperatures(); // Send the command to get temperatures
  lcd.clear();
  lcd.setCursor(3, 0);
  lcd.print("Acquiring");
  lcd.setCursor(4,1);
  lcd.print("Temps");
  dotdotdot();//tell users we are working...(2700)5400
  lcd.clear();
  lcd.setCursor(2, 0);
  lcd.print("Temperature:");
  lcd.setCursor(2, 1);
  lcd.print(sensors.getTempCByIndex(0));//use sensors.getTempFByIndex for F
  lcd.print('C');
  waitTime();//(7400)
  waitTime();//(7400)
}

void loop() {
  // put your main code here, to run repeatedly:
  requestTemp();
  
}
