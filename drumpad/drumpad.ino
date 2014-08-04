
byte sensorValue[9];
int maxValue;
int maxPad;
int lastPad = 0;

void setup() {
  Serial.begin(115200);
  Serial1.begin(9600);
  positionReset();
  clearLCD();
  
  Serial1.print("Rie Drum");
  selectLineTwo();
  Serial1.print("by C.Miyama 2014");
  delay(1000);
  positionReset();
  clearLCD();


}

void loop() {
  sensorValue[0] = analogRead(A0)/4;
  sensorValue[1] = analogRead(A1)/4;
  sensorValue[2] = analogRead(A2)/4;
  sensorValue[3] = analogRead(A3)/4;
  sensorValue[4] = analogRead(A4)/4;
  sensorValue[5] = analogRead(A5)/4;
  sensorValue[6] = analogRead(A6)/4;
  sensorValue[7] = analogRead(A7)/4;
  sensorValue[8] = analogRead(A8)/4;
  

  Serial.write(255);
  for(int i = 0; i< 9; i++){
    Serial.write(min(sensorValue[i], 254)); 
  }
  

  
  maxPad = -1;
  maxValue = 0;
  for(int i = 0; i < 8; i++){
      if(maxValue < sensorValue[i]){
        maxValue = sensorValue[i];
        maxPad = i; 
      }
  }
  if(maxPad != lastPad && maxPad > -1){
     lastPad = maxPad; 
  }
  
  String lineOne = "max:";
  if(maxPad < 0){
    lineOne += 'n';
  }else{
    lineOne += maxPad;
  }
  lineOne += " val:";
  
  char strOut[3];
  sprintf(strOut, "%03d", maxValue);
  
  lineOne += strOut;
  String lineTwo = "last:" ;
  lineTwo += lastPad;

  positionReset();
  Serial1.print(lineOne);
  selectLineTwo();
  Serial1.print(lineTwo);


}
