int VRx = A0;
int VRy = A1;
int SW = 2;

int incomingByte = 0;
const int buzzer = 22;

int xPosition = 0;
int yPosition = 0;
int SW_state = 0;
int mapX = 0;
int mapY = 0;

void setup() {
  Serial.begin(9600); 
  
  pinMode(VRx, INPUT);
  pinMode(VRy, INPUT);
  pinMode(SW, INPUT_PULLUP); 
  pinMode(buzzer,OUTPUT);
  
}

void loop() {
  xPosition = analogRead(VRx);
  yPosition = analogRead(VRy);
  SW_state = digitalRead(SW);
  mapX = map(xPosition, 0, 1023, -512, 512);
  mapY = map(yPosition, 0, 1023, -512, 512);
  if (Serial.available() > 0) {
    // read the incoming byte:
    incomingByte = Serial.read();
    //Serial.println(incomingByte);
    
    if(incomingByte == 'E') {
      
      tone(buzzer, 500, 500);
    }
  }
  
  //Serial.print("X: ");
  Serial.print(mapX);
  Serial.print(" ");
  Serial.print(mapY);
 // Serial.print(" | Button: ");
  Serial.println(SW_state);
  
  delay(100);
  
}
