#include <string.h>
char str[0];
const int Button_Pin1 = 13;
const int Button_Pin2=12;
const int Button_Pin3=11;
String Character[26] ={".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
int Alphabets[26]={65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,80,81,82,83,84,85,86,87,88,89,90};

void setup()
{
  pinMode(Button_Pin1,INPUT); 
  pinMode(Button_Pin2,INPUT); 
  pinMode(Button_Pin3,INPUT); 
  Serial.begin(9600);
}

void decode_morse()
{
  for (int i =0;i<26;i++)
  {
    if (Character[i]==str)
    {
    Serial.print(Alphabets[i]);
    }
  }
}

void loop()
{
  if (digitalRead(Button_Pin1)==HIGH)
  {
    Serial.print(".");
    strncat(str,".",1);
    delay(200);
  }
  else if (digitalRead(Button_Pin2)==HIGH)
  {
    Serial.print("-");
    strncat(str,"-",1);
    delay(200);
  }
  else if (digitalRead(Button_Pin3)==HIGH)
  {
    Serial.print(" ");
    delay(200);
    decode_morse();
  }
}
