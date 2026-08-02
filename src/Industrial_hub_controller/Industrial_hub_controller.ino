/* Command Structure (Protocol)
Use simple tagged messages.
Example:
syst:entSyst_START   → Entire Sytem turn on
T:START     → Truck turn on
T:STOP     → Truck turn stop
T:FWD      → Truck move forward
T:BWD      → Truck move backward
T:LEFT     → Truck turn left
T:RIGHT     → Truck turn right


H:CLSTART    → Conveyor lifting cassava on hub start lifting
H:CLSTOP     → Conveyor lifting cassava on hub stop lifting
H:CUSSTART    → Conveyor under Siever start working
H:CUSSTOP     → Conveyor under Siever stop working
H:SSTART    → Siever on hub start sieving
H:SSTOP     → Siever on hub stop sieving
When message is received, a green LED will blink twice.
So:
•  T: = Truck command 
• H: = Hub command 
Arduino checks prefix → decides action.
*/

#include <SoftwareSerial.h>

// RX, TX
SoftwareSerial truckSerial(2, 13); //RX, TX

int convLift = 3;
int flatConv = 4;
int siever = 5;
int hub_LED = 6;
int syst_LED = 7;


bool syst_on_or_not = false;
bool hub_on_or_not = false;

// Stop status variables
bool stopCL = false;
bool stopCUS = false;
bool stopSiv = false;

unsigned long lastCommandTime = 0;
const unsigned long timeout = 300; // 300ms safety stop

void setup() {

  pinMode(convLift, OUTPUT);
  pinMode(flatConv, OUTPUT);
  pinMode(siever, OUTPUT);
  pinMode(hub_LED, OUTPUT);
  pinMode(syst_LED, OUTPUT);

  digitalWrite(convLift, LOW);
  digitalWrite(flatConv, HIGH); //This relay behaves in a different way, this is why I set it to HIGH at the beginning intead of LOW. In the void loop insted of sending High I will send LOWV
  digitalWrite(siever, LOW);
  digitalWrite(hub_LED, LOW);

  Serial.begin(9600);

  truckSerial.begin(9600);

  Serial.println("Hub Ready");
}

void loop() {

  if (truckSerial.available()) {

    String cmd = truckSerial.readStringUntil('\n');
    cmd.trim();
    lastCommandTime = millis();

    //Serial.println("Received from Truck:");
    Serial.println(cmd);

    // ==========================
    // TURN ON ENTIRE SYSTEM
    // ==========================

    if (cmd == "Turn entire system ON") {
      
      //Change entire system ON state to true, thereby turning entire syst ON
      syst_on_or_not = true;
      digitalWrite(syst_LED, HIGH);

    } else if (cmd == "Turn entire system OFF") {
      //Change entire system ON state to false, thereby turning entire syst OFF
      syst_on_or_not = false;
      hub_on_or_not = false;
      digitalWrite(syst_LED, LOW);
      digitalWrite(hub_LED, LOW);
      Serial.println("Sent --> entire system OFF:");
    }


    // ==========================
    // TURN ON HUB
    // ==========================

    if (syst_on_or_not == true && cmd == "CLSTART" || syst_on_or_not == true && cmd == "CUSSTART" || syst_on_or_not == true && cmd == "SSTART") {

      hub_on_or_not = true;
      digitalWrite(hub_LED, HIGH);
      Serial.println("Sent --> Hub ON:");

    } else if (syst_on_or_not == false && cmd == "CLSTART" || syst_on_or_not == false && cmd == "CUSSTART" || syst_on_or_not == false && cmd == "SSTART"){
      hub_on_or_not = false;
      digitalWrite(hub_LED, LOW);
      Serial.println("Sent --> hub OFF:");
    }
        

    // ==========================
    // START LIFT CONVEYOR
    // ==========================

    if (cmd == "CLSTART" && hub_on_or_not == true) {

      // Start lifting conveyor
      digitalWrite(convLift, HIGH);
      stopCL = false;
      Serial.println("Slanting Conveyor Lifter turned ON");

    } else if (cmd == "CLSTOP" && hub_on_or_not == true) {
      
      // Stop lifting conveyor
      digitalWrite(convLift, LOW);
      stopCL = true;
      Serial.println("Slanting Conveyor Lifter turned OFF");
    }



    // ==========================
    // START SIEVER
    // ==========================

    if (cmd == "SSTART" && hub_on_or_not == true) {

      // Start siever
      digitalWrite(siever, HIGH);
      stopSiv = false;
      Serial.println("Cassava Seiver turned ON");

    } else if (cmd == "SSTOP" && hub_on_or_not == true) {

      // Stop siever
      digitalWrite(siever, LOW);
      stopSiv = true;
      Serial.println("Cassava Seiver turned OFF");
    }

    

    // ==========================
    // START CONVEYOR UNDER SIEVER
    // ==========================

    if (cmd == "CUSSTART" && hub_on_or_not == true) {

      // Start conveyor under siever
      digitalWrite(flatConv, LOW);
      stopCUS = false;
      Serial.println("Flat Conveyor turned ON");

    } else if (cmd == "CUSSTOP" && hub_on_or_not == true) {

      // Stop conveyor under siever
      digitalWrite(flatConv, HIGH);
      stopCUS = true;
      Serial.println("Flat Conveyor turned OFF");
    }



    // ==========================
    // TURN OFF SYSTEM
    // ==========================
    if (stopCL == true && stopCUS == true && stopSiv == true) {
      hub_on_or_not = false;
      digitalWrite(hub_LED, LOW);
      Serial.println("Hub turned ON");
    }
  }


    // ==========================
    // Use Millis to pull system out of unexpected Loop
    // ==========================
//    if (millis() - lastCommandTime > timeout)
//    {
//      digitalWrite(convLift, HIGH);
//      digitalWrite(flatConv, HIGH);
//      digitalWrite(siever, LOW);
//    
//      stopCL = true;
//      stopCUS = true;
//      stopSiv = true;
//    
//      hub_on_or_not = false;
//      digitalWrite(hub_LED, LOW);
//    }


  // ==========================
  // Ai Mode
  // ==========================


  
  // ==========================
  // Read Limit switch data from pin 8
  // ==========================
  int limitSwitch = digitalRead(8);
  if (limitSwitch == 1) {
    // Transmit data to truck Bluetooth
     truckSerial.println("distance reaached, stop truck");
  }
}
