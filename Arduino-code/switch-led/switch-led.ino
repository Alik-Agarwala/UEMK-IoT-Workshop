void setup()
{

  pinMode(10, INPUT);
  pinMode(13, OUTPUT);
  
}

void loop()
{
 if (digitalRead(10) == 1)
   digitalWrite(13, HIGH);
 else
   digitalWrite(13, LOW);
  	
}