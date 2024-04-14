// Bi-Directional counter for a room with single door (Entry and Exit from same door)
int Led_Pin = 10;
int LeftSensor_Pin =3;
int RightSensor_Pin = 5;

int LeftSensor_value =1;
int RightSensor_value =1;

int counter = 0;

void setup() 
{
 pinMode(Led_Pin,OUTPUT); //Led
 pinMode(LeftSensor_Pin,INPUT);
 pinMode(RightSensor_Pin,INPUT);

 Serial.begin(9600);
}

void loop()
{

  LeftSensor_value = digitalRead(LeftSensor_Pin);
  RightSensor_value = digitalRead(RightSensor_Pin);

  if(RightSensor_value == 0)
  {
    for(int i=0; i<10 ; i++)
    {
      delay(50);
       LeftSensor_value = digitalRead(LeftSensor_Pin);
       if(LeftSensor_value == 0)
       {
        counter++;
        break;
       }
    }
    RightSensor_value=1;

    LeftSensor_value=1;
  
  }


   if(LeftSensor_value == 0)
  {
    for(int i=0; i<10 ; i++)
    {
      delay(50);
       RightSensor_value = digitalRead(RightSensor_Pin);
       if(RightSensor_value == 0)
       {
        counter--;
        break;
       }
    }
    LeftSensor_value=1;

    RightSensor_value=1;
  
  }

  delay(10);

  Serial.println(counter);

  if(counter>0)
  {
    digitalWrite(Led_Pin,HIGH);
  }
  else
  {
    digitalWrite(Led_Pin,LOW);
  }

  if(counter<0)
  {
    counter=0;
  }

  

}
