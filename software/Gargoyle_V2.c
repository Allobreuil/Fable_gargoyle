// Author: HAVARD Henry, based on the flower-player by Nicolas Brondin-Bernard.
#define CAPTEUR 17
#define BUSY_PIN D4

#include "Arduino.h"
#include "DFRobotDFPlayerMini.h"


#define FPSerial Serial1

DFRobotDFPlayerMini myDFPlayer;
void printDetail(uint8_t type, int value);
int song_number = 1;
bool flag = false; 

void IRAM_ATTR startSound()
{
  flag = true;
}

void setup()
{
  pinMode(LED_RED, OUTPUT);
  pinMode(LED_GREEN, OUTPUT);
  pinMode(LED_BLUE, OUTPUT);
  pinMode(D4, INPUT);
  FPSerial.begin(9600, SERIAL_8N1, /*rx =*/D0, /*tx =*/D1);

  Serial.begin(115200);

  Serial.println();
  Serial.println(F("DFRobot DFPlayer Mini Demo"));
  Serial.println(F("Initializing DFPlayer ... (May take 3~5 seconds)"));
  
  while(!myDFPlayer.begin(FPSerial, /*isACK = */true, /*doReset = */true)) {  //Use serial to communicate with mp3.
    Serial.println(F("Unable to begin:"));
    Serial.println(F("1.Please recheck the connection!"));
    Serial.println(F("2.Please insert the SD card!"));
    digitalWrite(LED_RED, LOW);
  }

  digitalWrite(LED_RED, HIGH);
  digitalWrite(LED_GREEN, LOW);
  Serial.println(F("DFPlayer Mini online."));
  
  myDFPlayer.volume(15);  //Set volume value. From 0 to 30
  //myDFPlayer.play(1);  //Play the first mp3
  attachInterrupt(CAPTEUR, startSound, RISING);
}

void loop()
{
  static unsigned long timer = millis();
  song_number = random(1,20);
  if(flag == true)
  {
    if(digitalRead(BUSY_PIN) == LOW)
    {
      digitalWrite(LED_GREEN, HIGH);
      digitalWrite(LED_BLUE, LOW);
    }
    if(digitalRead(BUSY_PIN) == HIGH)
    {
      digitalWrite(LED_BLUE, HIGH);
      digitalWrite(LED_GREEN, LOW);
      myDFPlayer.play(song_number); 
    }
    if (myDFPlayer.available()) {
      //for debug.
      //printDetail(myDFPlayer.readType(), myDFPlayer.read()); //Print the detail message from DFPlayer to handle different errors and states.
    }
    flag = false;
  }
}

void printDetail(uint8_t type, int value){
  switch (type) {
    case TimeOut:
      Serial.println(F("Time Out!"));
      break;
    case WrongStack:
      Serial.println(F("Stack Wrong!"));
      break;
    case DFPlayerCardInserted:
      Serial.println(F("Card Inserted!"));
      break;
    case DFPlayerCardRemoved:
      Serial.println(F("Card Removed!"));
      break;
    case DFPlayerCardOnline:
      Serial.println(F("Card Online!"));
      break;
    case DFPlayerUSBInserted:
      Serial.println("USB Inserted!");
      break;
    case DFPlayerUSBRemoved:
      Serial.println("USB Removed!");
      break;
    case DFPlayerPlayFinished:
      Serial.print(F("Number:"));
      Serial.print(value);
      Serial.println(F(" Play Finished!"));
      break;
    case DFPlayerError:
      Serial.print(F("DFPlayerError:"));
      switch (value) {
        case Busy:
          Serial.println(F("Card not found"));
          break;
        case Sleeping:
          Serial.println(F("Sleeping"));
          break;
        case SerialWrongStack:
          Serial.println(F("Get Wrong Stack"));
          break;
        case CheckSumNotMatch:
          Serial.println(F("Check Sum Not Match"));
          break;
        case FileIndexOut:
          Serial.println(F("File Index Out of Bound"));
          break;
        case FileMismatch:
          Serial.println(F("Cannot Find File"));
          break;
        case Advertise:
          Serial.println(F("In Advertise"));
          break;
        default:
          break;
      }
      break;
    default:
      break;
  }
  
}
