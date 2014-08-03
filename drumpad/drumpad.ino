

void setup() {
  Serial.begin(115200);
}

void loop() {
  byte sensorValue[9];
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
}
