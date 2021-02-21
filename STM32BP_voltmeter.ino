//STM32F103C8T6-Blue-Pill Voltmeter
//
//James Steven Dulangon     
//
#define analogInPin PA0                 

void setup()
{
    Serial.begin(115200);
    pinMode(analogInPin, INPUT);
}

void loop()
{   
  uint8_t num_sample = 30;
  int sum = 0;  

   while (0 < num_sample) 
   {            
      int analogValue = analogRead(analogInPin);
      sum += analogValue;
      num_sample--;                                
      delay(3);
   }
    
   float ave = (float)sum/30.0;
   float vout = (ave*3.29)/ 4096.0 ;
   float va = (vout / (10000.0/110000.0));
       
   Serial.println(va);
  
   delay(100);
}
