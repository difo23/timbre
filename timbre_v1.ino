#include <TimeLib.h>
#include "pitches.h"

// Proyecto tiembre 


// Outputs:
int rele = 13;


// Hours de clase tiempo en minutos

String Hours[] = {
  "7:02 am",
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
 
  pinMode(rele, OUTPUT);
  digitalWrite(rele, HIGH); 

  // LED on for load in the battery mode
  pinMode(3, OUTPUT);
  digitalWrite(3, HIGH);

  
  Serial.begin(9600);
  resetTime();
}


void loop() {
  
  int weekDay   = weekday();
  int hourDay   = hour();
  int minuteDay = minute();
 
  // Button state on, not weekend, not woking hours 
  
  if( ( weekDay > 1 && weekDay < 7) && (hourDay > 6 && hourDay < 15 )) {
    
  
    String timeNowString = ""+ String(hourDay) +""+ String(minuteDay);
    int caseSwitch = timeNowString.toInt();
    Serial.println(caseSwitch);
    
    switch (caseSwitch) {
        case 72:
              ring();     
        break;
        
        case 80:
              ring();
        break;
        
        case 850:
              ring();
        break;
        
        case 940:
              ring();
        break;
        
        case 100:
              ring();
        break;
        
        case 1050:
              ring();
        break;
        
        case 1140:
              ring();
        break;
        
        case 1220:
              ring();
        break;
        
        case 130:
              ring();
        break;
        
        case 1350:
              ring();
        break;
        case 1440:
              Serial.println("Bye!!, end the day.");
              ring();
        break;
        
        default:
            Serial.println("Time between hours doorbell off y button on");
            printTime();
            digitalWrite(rele, HIGH); 
            waitMinute();
        break;
    }
   
    

  } 
  else {
    Serial.println("Button on in weekend, not working hours and doorbell off");
    digitalWrite(rele, HIGH);
    printTime();
    waitMinute();  
  }
  
  


}


void ring() {
 printTime();
 Serial.println("doorbell on");  
 digitalWrite(rele, LOW);

 waitRing();
 
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
  Serial.print(second());
  
  Serial.print("  Day:");
  Serial.print(day());  // the day now (1-31)
  Serial.print(" ( ");
  Serial.print(Days[weekday()]); // day of the week (1-7), Sunday is day 1
  Serial.print(" )");
  Serial.print(" Month:");
  Serial.print(month()); // the month now (1-12)
  Serial.print(" Year:");
  Serial.println(year()); // the full four digit year: (2009, 2010 etc)

}

void resetTime() {
  // setTime(Hour, minutes, seconds, day, month, year);
  setTime(11,44 , 0, 14, 1, 2022);
}


void waitMinute() {

  int minuteWait = minute();
  
  while(minuteWait == minute()){
   
  }
}


void waitRing() {

  int waitSeconds = second();
 
  while((second() - waitSeconds)  < 6){
   
  }

}
