int minValues[6], maxValues[6], threshold[6];
int calibrate(){
  int sum=0;
  for ( int i = 0; i < 6; i++)
  {
    minValues[i] = analogRead(i);
    maxValues[i] = analogRead(i);
  }
  
  for (int i = 0; i < 500; i++)
  {
    analogWrite(5,150);
    analogWrite(6,0);
    analogWrite(9,0);
    analogWrite(10,150);
    

    for ( int i = 0; i < 6; i++)
    {
      if (analogRead(i) < minValues[i])
      {
        minValues[i] = analogRead(i);
      }
      if (analogRead(i) > maxValues[i])
      {
        maxValues[i] = analogRead(i);
      }
    }
    delay(10);
  }

  for ( int i = 0; i < 6; i++)
  {
    threshold[i] = (minValues[i] + maxValues[i]) / 2;
    // Serial.print(threshold[i]);
    // Serial.print(" ");
    sum=sum+threshold[i];
  }

  analogWrite(5,0);
  analogWrite(6,0);
  analogWrite(9,0);
  analogWrite(10,0);
  return(sum/6);
}