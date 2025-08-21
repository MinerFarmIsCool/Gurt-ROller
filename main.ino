#include <LiquidCrystal.h>          //the liquid crystal library contains commands for printing to the display

LiquidCrystal lcd(13, 12, 11, 10, 9, 8);   // tell the RedBoard what pins are connected to the display

int button[] = {2, 3, 4}; // button[0] is red, 
int pressedButton = 4;


void setup() {

  pinMode(button[0], INPUT_PULLUP);
  pinMode(button[1], INPUT_PULLUP);
  pinMode(button[2], INPUT_PULLUP);


  lcd.begin(16, 2);                 //tell the lcd library that we are using a display that is 16 characters wide and 2 characters high
  lcd.clear();                      //clear the display
}

void loop() {



  lcd.setCursor(0, 0);              //set the cursor to the 0,0 position (top left corner)
  //lcd.print(randNum);
  //delay(500);
  //lcd.clear();

  pressedButton = buttonCheck();
  if (pressedButton == 0) { //d20
    int dieMaxRoll = 21;
    lcd.clear();
    int daskfak = generateNumbersAnimation(dieMaxRoll);
    int randNum = random(1, dieMaxRoll);
    printTheNum(randNum, dieMaxRoll);
  }
    else if (pressedButton == 1) { //d10
    int dieMaxRoll = 11;
    lcd.clear();
    int daskfak = generateNumbersAnimation(dieMaxRoll);
    int randNum = random(1, dieMaxRoll);
    printTheNum(randNum, dieMaxRoll);
  }
   else if (pressedButton == 2) { //d6
    int dieMaxRoll = 7;
    lcd.clear();
    int daskfak = generateNumbersAnimation(dieMaxRoll);
    int randNum = random(1, dieMaxRoll);
    printTheNum(randNum, dieMaxRoll);
  }

  //lcd.setCursor(0, 1);              //move the cursor to the first space of the bottom row
  //lcd.print(millis() / 1000);       //print the number of seconds that have passed since the last reset
}

int buttonCheck() {
  //check if any buttons are being pressed
  if (digitalRead(button[0]) == LOW) {
    return 0;
  } else if (digitalRead(button[1]) == LOW) {
    return 1;
  } else if (digitalRead(button[2]) == LOW) {
    return 2;
  } else {
    return 4;
  }
}


int generateNumbersAnimation(int dieMaxRoll) {
  for (int i = 0; i < 35; i++) {
    int randNumRolling = random(1, dieMaxRoll);

    generateLettersAnimation();

    lcd.setCursor(0, 0);
    lcd.print(randNumRolling);

    int delayTime = 10 * (i / 3);
    delay(delayTime);
    lcd.clear();
  }
  return 0;
}

int generateLettersAnimation() {
  for (int i = 0; i < 16; i++) {
    char randomUpperChar = 'A' + (rand() % 26);
    lcd.setCursor(i, 1);
    lcd.print(randomUpperChar);
  }
  return 0;
}

void printTheNum(int randNum, int dieMaxRoll) {
  lcd.print(randNum);
    if (randNum == (dieMaxRoll-1)) {
      lcd.setCursor(0, 1);
      lcd.print("Critical Success!");
      lcd.setCursor(0, 0);
    } else if (randNum == 1) {
      lcd.setCursor(0, 1);
      lcd.print("Critical Failure!");
      lcd.setCursor(0, 0);
    }
}
