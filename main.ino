#include <LiquidCrystal.h>          //the liquid crystal library contains commands for printing to the display

LiquidCrystal lcd(13, 12, 11, 10, 9, 8);   // tell the RedBoard what pins are connected to the display

int button[] = {2}; // button[0] is red
int pressedButton = 4;


void setup() {

  pinMode(button[0], INPUT_PULLUP);

  lcd.begin(16, 2);                 //tell the lcd library that we are using a display that is 16 characters wide and 2 characters high
  lcd.clear();                      //clear the display
}

void loop() {



  lcd.setCursor(0, 0);              //set the cursor to the 0,0 position (top left corner)
  //lcd.print(randNum);
  //delay(500);
  //lcd.clear();

  pressedButton = buttonCheck();
  if (pressedButton == 0) {
    int randNum = random(0, 20);
    lcd.print(randNum);
    delay(500);
    lcd.clear();
  }

  //lcd.setCursor(0, 1);              //move the cursor to the first space of the bottom row
  //lcd.print(millis() / 1000);       //print the number of seconds that have passed since the last reset
}

int buttonCheck() {
  //check if any buttons are being pressed
  if (digitalRead(button[0]) == LOW) {
    return 0;
  } //else if (digitalRead(button[1]) == LOW) {
    //return 1;
  //} //else if (digitalRead(button[2]) == LOW) {
    //return 2;
  //} //else if (digitalRead(button[3]) == LOW) {
    //return 3;
  //}
   else {
    return 4; //this will be the value for no button being pressed
  }
}
