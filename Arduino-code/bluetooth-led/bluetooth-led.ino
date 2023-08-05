void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(13, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
    if (Serial.available())
  {
    char BluetoothData=Serial.read();
    switch(BluetoothData)
    {
      case '1' : Serial.println("ON");
                digitalWrite(13, HIGH);
                break;
      
      case '0' : Serial.println("OFF");
                  digitalWrite(13, LOW);
                  break;
    }
  
  }

}
