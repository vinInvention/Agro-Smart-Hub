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
T:STPTRUCK  → Stop truck movement


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
#include <AFMotor.h>  // Include the motor driver library

// RX, TX
SoftwareSerial hubSerial(A4, A5);

int truck_LED = A0;
bool syst_on_or_not = false;
bool truck_on_or_not = false;
bool hub_on_or_not = false;
int linkage_relay1 = A1;
int linkage_relay2 = A2;
int leadscrew_relay = A3;
unsigned long lastCommandTime = millis();

int Speeed = 200; // Motor speed (0 - 255)

AF_DCMotor motor1(1);  // Create motor objects
AF_DCMotor motor2(2);
AF_DCMotor motor3(3);
AF_DCMotor motor4(4);

void setup() {
  pinMode(linkage_relay1, OUTPUT);
  pinMode(linkage_relay2, OUTPUT);
  pinMode(leadscrew_relay, OUTPUT);
  pinMode(truck_LED, OUTPUT);
  digitalWrite(truck_LED, LOW);
  digitalWrite(linkage_relay1, LOW);
  digitalWrite(linkage_relay2, LOW);
  // Phone Bluetooth
  Serial.begin(9600);

  // Hub Bluetooth
  hubSerial.begin(9600);
  
  Serial.println("Truck Ready");


}

void loop() {
  if (Serial.available() > 0){
    String data = Serial.readStringUntil('\n');
    data.trim();
    //Serial.println(data);

    //split data and store in seperate variables
    int delimiterIndex = data.indexOf(':'); // Find the semicolon/delimiter position
    String split1 = "";
    String split2 = "";
    
    if (delimiterIndex != -1) {
      split1 = data.substring(0, delimiterIndex);         // 
      split2 = data.substring(delimiterIndex + 1);       //
      
      Serial.println("//New Splitted message recieved =======");
      Serial.println(split1);
      Serial.println(split2);
      Serial.println("=========================");
    }

    // ==========================
    // TURN ON Entire SYSTEM
    // ========================== 
    if (split1 == "syst" && split2 == "entSyst_START" && syst_on_or_not == false){
      
      //Change entire system ON state to true, thereby turning entire syst ON
      syst_on_or_not = true;
        
      // Transmit data to Hub Bluetooth
      hubSerial.println("Turn entire system ON"); 
      Serial.println("Sent --> entire system ON to Hub:");
      Serial.println(split2);
      

            
    }else if (split1 == "syst" && split2 == "entSyst_START" && syst_on_or_not == true){ 
      //Change entire system ON state to false, thereby turning entire syst OFF
      syst_on_or_not = false;      

      //Turn OFF truck
      truck_on_or_not = false; 
      digitalWrite(truck_LED, LOW);

      //Turn OFF hub
      hub_on_or_not = false; 

      // Transmit data to Hub Bluetooth
      hubSerial.println("Turn entire system OFF"); 
      Serial.println("Sent --> entire system OFF to Hub:");
      Serial.println(split2);
      
    }

    // ==========================
    // SEND OTHER HUB CONTROL DATA TO HUB
    // ==========================
    if (split1 == "H" && syst_on_or_not == true) {

      // Transmit data to Hub Bluetooth
      hubSerial.println(split2); 

      Serial.println("Sent to Hub Control Data to hub:");
      Serial.println(split2);
      Serial.println(split2);
    }else if (split1 == "H" && syst_on_or_not == false){
      //Do nothing
    }

    // ==========================
    // TURN ON TRUCK
    // ========================== 
    if (syst_on_or_not == true && split1 == "T" && split2 == "START"){
      digitalWrite(truck_LED, HIGH);
      truck_on_or_not = true;      
      Serial.println("truck turned ON");
    }else if (syst_on_or_not == true && split1 == "T" && split2 == "STOP"){
          digitalWrite(truck_LED, LOW);
          truck_on_or_not = false;
          Serial.println("truck turned OFF");
    }

    
//    // ==========================
//    // TURN OFF SYSTEM
//    // ==========================   
//    if(split1 == "T" && split2 == "STOP"){
//      digitalWrite(truck_LED, LOW);
//      truck_on_or_not = false;
//    }

     



    // ==========================
    // MOVE TRUCK
    // ==========================
    if (split1 == "T" && truck_on_or_not == true && split2 == "FWD"){
      //Set SPeed
      motor1.setSpeed(Speeed);
      motor2.setSpeed(Speeed);
      motor3.setSpeed(Speeed);
      motor4.setSpeed(Speeed);
      
      //Move truck forward
      motor1.run(FORWARD);
      motor2.run(FORWARD);
      motor3.run(FORWARD);
      motor4.run(FORWARD);
      Serial.println("Moving Truck FWD");
    }else if (split1 == "T" && truck_on_or_not == true && split2 == "BWD"){
      
      //Set Speed
      motor1.setSpeed(Speeed);
      motor2.setSpeed(Speeed);
      motor3.setSpeed(Speeed);
      motor4.setSpeed(Speeed);
      
      //Move truck backward
      motor1.run(BACKWARD);
      motor2.run(BACKWARD);
      motor3.run(BACKWARD);
      motor4.run(BACKWARD);
      Serial.println("Moving Truck BWD");
    }else if (split1 == "T" && truck_on_or_not == true && split2 == "LEFT"){
      //Move truck left
      //Set the speed
      Speeed = 250;
      motor1.setSpeed(Speeed);
      motor2.setSpeed(Speeed);
      motor3.setSpeed(Speeed);
      motor4.setSpeed(Speeed);
      //Pivotal turn for truck left
      // Right side forward
      motor1.run(FORWARD);
      motor2.run(FORWARD);
      // Left side backward
      motor3.run(BACKWARD);
      motor4.run(BACKWARD);

      Serial.println("Moving Truck Left");
    }else if (split1 == "T" && truck_on_or_not == true && split2 == "RIGHT"){      
      //Set the speed
      Speeed = 250;
      motor1.setSpeed(Speeed);
      motor2.setSpeed(Speeed);
      motor3.setSpeed(Speeed);
      motor4.setSpeed(Speeed);

      //Pivotal turn for truck right
      // Right side backward
      motor1.run(BACKWARD);
      motor2.run(BACKWARD);
      // Left side forward
      motor3.run(FORWARD);
      motor4.run(FORWARD);
      
      Serial.println("Moving Truck Right");
    }else if (split1 == "T" && truck_on_or_not == true && split2 == "STPTRUCK"){
      //Stop truck's movement
      //Set the speed
      motor1.setSpeed(0);
      motor2.setSpeed(0);
      motor3.setSpeed(0);
      motor4.setSpeed(0);
      //move
      motor1.run(RELEASE);
      motor2.run(RELEASE);
      motor3.run(RELEASE);
      motor4.run(RELEASE);

      //Forces truck to stop immediately If no command is received for 300 ms truck automatically stops
      if (millis() - lastCommandTime > 300){
        motor1.run(RELEASE);
        motor2.run(RELEASE);
        motor3.run(RELEASE);
        motor4.run(RELEASE);
        }
      Serial.println("Stopping truck");
    }

    // ==========================
    // CODE TO LIFT THE MECHANISMS (LINKAGE AND LEAD SCREW)  ON TRUCK
    // ==========================    
    if (split1 == "T" && truck_on_or_not == true && split2 == "LIFT"){
      digitalWrite(linkage_relay1, HIGH);
      Serial.println("Lifting Truck Linkage");
      digitalWrite(linkage_relay2, LOW);
    }else if (split1 == "T" && truck_on_or_not == true && split2 == "LOWER"){
      digitalWrite(linkage_relay1, LOW);
      digitalWrite(linkage_relay2, HIGH);
      Serial.println("Lowering Truck Linkage");
    }else if (split1 == "T" && truck_on_or_not == true && split2 == "DIS"){
      digitalWrite(leadscrew_relay, HIGH);
      Serial.println("Up.... driving Lead Srew actuatore");
      delay(10000);
      Serial.println("Down... driving Lead Srew actuatore");
      digitalWrite(leadscrew_relay, LOW);
    } 
    else{
     digitalWrite(linkage_relay1, LOW);
     digitalWrite(linkage_relay2, LOW);
     digitalWrite(leadscrew_relay, LOW);
 }
  }







  // ==========================
  // Ai Mode
  // ==========================


  
  // ==========================
  // Read Limit switch data from hub
  // ==========================
  if (hubSerial.available()) {

    String hubcmd = hubSerial.readStringUntil('\n');
    hubcmd.trim();

    if (truck_on_or_not == true && hubcmd == "distance reached, stop truck") {   
      
      //Stop truck's movement
      //Set the speed
      motor1.setSpeed(0);
      motor2.setSpeed(0);
      motor3.setSpeed(0);
      motor4.setSpeed(0);
      //move
      motor1.run(RELEASE);
      motor2.run(RELEASE);
      motor3.run(RELEASE);
      motor4.run(RELEASE);


      //Blink truck LED three times
      digitalWrite(truck_LED, HIGH);
      delay(1000);
      digitalWrite(truck_LED, LOW);
      delay(1000);
      digitalWrite(truck_LED, HIGH);
      delay(1000);
      digitalWrite(truck_LED, LOW);
      delay(1000);
      digitalWrite(truck_LED, HIGH);
    }
  }

}
