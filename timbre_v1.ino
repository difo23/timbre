#include <TimeLib.h>
#include "pitches.h"
// Proyecto tiembre 

int melody[] = {
  NOTE_C4, NOTE_G3,NOTE_G3, NOTE_A3, NOTE_G3,0, NOTE_B3, NOTE_C4, NOTE_C4, NOTE_G3,NOTE_G3, NOTE_A3, NOTE_G3,0, NOTE_B3, NOTE_C4};

// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations[] = {
  4, 8, 8, 4,4,4,4, 4, 4, 8, 8, 4,4,4,4,4 };
  
// Inputs:
int button= 2;
int button_value = 0;


// Outputs:
int doorbell= 13;
int rele = 12;
int buzz = 8;


// Hours de clase tiempo en minutos

String Hours[] = {
  "7:05 am",
  "8:00 am", 
  "8:50 am", 
  "9:40 am", 
  "10:00 am", 
  "10:50 am", 
  "11:40 am", 
  "12:20 pm", 
  "1:00 pm", 
  "1:50 pm", 
  "2:40 pm"
};

String Days[] = {
  "Empty",
  "Sunday", 
  "Monday", 
  "Tuesday", 
  "Wednesday", 
  "Thursday", 
  "Friday", 
  "Saturday", 
};





void setup(){

  pinMode(button, INPUT);
  pinMode(doorbell, OUTPUT);
  pinMode(rele, OUTPUT);
  
  
  digitalWrite(button, HIGH);
  digitalWrite(rele, HIGH);
  Serial.begin(9600);
  Serial.println("Start clock setup 7:04 am ");
  resetTime();
}


void loop() {
  button_value = digitalRead(button);
  
  int weekDay = 2;//weekday();
  int hourDay = hour();
  int minuteDay = minute();
 
  // Button state on, not weekend, not woking hours 
  
  if(button_value && ( weekDay > 1 && weekDay < 7) && (hourDay > 6 && hourDay < 15 )) {
    
    // Boton presionado
    // Serial.println("Button on ");
    String timeNowString = ""+ String(hourDay) +""+ String(minuteDay);
    int caseSwitch = timeNowString.toInt();
    
    switch (caseSwitch) {
        case 75:
              Serial.println("Good Morning, start the day.");
              Serial.println(Days[weekDay]);
              Serial.println(Hours[0]);
              printTime();
              Serial.println("Button on y doorbell on");
              ring();     
        break;
        
        case 80:
              Serial.println(Hours[1]);
              printTime();
              Serial.println("Button on y doorbell on");
              ring();
        break;
        
        case 850:
              Serial.println(Hours[2]);
              printTime();
              Serial.println("Button on y doorbell on");
              ring();
        break;
        
        case 940:
              Serial.println(Hours[3]);
              printTime();
              Serial.println("Button on y doorbell on");
              ring();
        break;
        
        
        case 100:
              Serial.println(Hours[4]);
              printTime();
              Serial.println("Button on y doorbell on");
              ring();
        break;
        case 1050:
              Serial.println(Hours[5]);
              printTime();
              Serial.println("Button on y doorbell on");
              ring();
        break;
        case 1140:
              Serial.println(Hours[6]);
              printTime();
              Serial.println("Button on y doorbell on");
              ring();
        break;
        case 1220:
              Serial.println(Hours[7]);
              Serial.println("Button on y doorbell on");
              ring();
        break;
        case 130:
              Serial.println(Hours[8]);
              printTime();
              Serial.println("Button on y doorbell on");
              ring();
        break;
        case 1350:
              Serial.println(Hours[9]);
              printTime();
              Serial.println("Button on y doorbell on");
              ring();
        break;
        case 1440:
              Serial.println("Bye!!, end the day.");
              Serial.println(Hours[10]);
              printTime();
              Serial.println("Button on y doorbell on");
              ring();
        break;
        
        default:
            Serial.println("Time between hours doorbell off y button on");
            printTime();
            digitalWrite(doorbell, LOW);
            digitalWrite(rele, HIGH); 
            delay(30000);
        break;
    }
   
    

  } 
  else if(button_value == false){
    
    Serial.println("Button off and doorbell off");
    digitalWrite(doorbell, LOW);
    digitalWrite(rele, HIGH);
    Serial.println(Days[weekDay]);
    printTime();
    waitMinute();
    
    
  } else {
    Serial.println("Button on in weekend, not working hours and doorbell off");
    digitalWrite(doorbell, LOW);
    digitalWrite(rele, HIGH);
    Serial.println(Days[weekDay]);
    printTime();
    delay(30000);
  
  }
  
  


}


void ring() {
  
 digitalWrite(doorbell, HIGH);
 digitalWrite(rele, LOW);
 Serial.println("doorbell on");

 for (int thisNote = 0; thisNote < 16; thisNote++) {
    // to calculate the note duration, take one second 
    // divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int noteDuration = 1000/noteDurations[thisNote];
    tone(buzz, melody[thisNote],noteDuration);

    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    // stop the tone playing:
    noTone(buzz);
   }
   
   digitalWrite(doorbell, LOW);
   digitalWrite(rele, HIGH);     
   Serial.println("doorbell off");
   waitMinute();
   
}


void printTime(){
  
  Serial.println("Time now: ");
  Serial.print("Hour: ");
  Serial.print(hour());
  Serial.print(":");
  Serial.print(minute());
  Serial.print(":");
  Serial.println(second());
  
  Serial.print("Day:");
  Serial.print(day());  // the day now (1-31)
  Serial.print(" ( ");
  Serial.println(Days[weekday()]); // day of the week (1-7), Sunday is day 1
  Serial.print(" )");
  Serial.print("Month:");
  Serial.println(month()); // the month now (1-12)
  Serial.print("Year:");
  Serial.println(year());            // the full four digit year: (2009, 2010 etc)

}

void resetTime() {
  // Establecemos la Hour y la fecha 
  // setTime(Hour,minutos,segundos,dia,mes,anyo);
  setTime(7, 4, 0, 5, 12, 2021);
  
}


void waitMinute() {

  delay(56000);

}

