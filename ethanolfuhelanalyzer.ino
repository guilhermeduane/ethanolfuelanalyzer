#include <Wire.h>

int analy=0, value=0;
volatile int state = LOW;
volatile int state1 = LOW;
void analyzer()
{
analy++;
} 
void setup()
{
 Serial.begin(9600);
 attachInterrupt(0, analyzer, FALLING);
 delay(4000);

  noInterrupts();           
  TCCR1A = 0;
  TCCR1B = 0;
  TCNT1  = 0;

  OCR1A = 31250;            
  TCCR1B |= (1 << WGM12);   
  TCCR1B |= (1 << CS12);    
  TIMSK1 |= (1 << OCIE1A);  
  interrupts();             
}

ISR(TIMER1_COMPA_vect)          
{
  value=analy*2-50;   

  analy=0;
 
}

void loop()
{
 Serial.println("ETHANOL FUEL ANALYZER");
 Serial.println("ETHANOL= ");
 if( value > 2 ){
 Serial.print(value);
 Serial.println("%       ");
 } else {
  Serial.println("NO FUEL");
 }
 if(value > 100) {
  Serial.println("ERROR");
 }else{
 Serial.println("        ");
}
}
