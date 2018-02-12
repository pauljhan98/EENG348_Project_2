int pd2 = HIGH; //current value of pin
int last_state =HIGH; //last value of pin


void setup() {

  Serial.begin(9600); //start serial monitor
  DDRD &= ~(1 << PD2); //sets port d pin 2 as input, no changes to others
  PORTD = (1<<PD2); //sets port d pin 2 as high
}

void loop() {

pd2 = ((PIND & (1<<PD2))/4); //checks port d pin 2 and sets pd2 to that value (division by 4 due to 00000100 = 4)
if (pd2 !=last_state) { //if state of pin has changed
  Serial.println(pd2); //print 1 or 0 
}
last_state = pd2; //updates last state
delay(100); //delay for debounce

}
