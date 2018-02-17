int latchPin = 12;
int clockPin = 11;
int dataPin = 13;
int column = 0;
int row = 0;


void setup() {
  // put your setup code here, to run once:
  pinMode(latchPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  pinMode(clockPin, OUTPUT);

  
}

void loop() {
  // put your main code here, to run repeatedly:
  for (int i = 0; i < 5; i++)
  {
    column = 0;
    row = 0;
    
    if (i == 0)
    {
      column = 0x7f;
      row = 0x00;

      digitalWrite(latchPin, LOW);
      shiftOut(dataPin, clockPin, MSBFIRST, column);
      shiftOut(dataPin, clockPin, MSBFIRST, row);
      digitalWrite(latchPin, HIGH);
    }

    if (i == 1)
    {
      column = 0xBF;
      row = 0x42;

      digitalWrite(latchPin, LOW);
      shiftOut(dataPin, clockPin, MSBFIRST, column);
      shiftOut(dataPin, clockPin, MSBFIRST, row);
      digitalWrite(latchPin, HIGH);
    } //

    if (i == 2)
    {
      column = 0xDF;
      row = 0x7f;

      digitalWrite(latchPin, LOW);
      shiftOut(dataPin, clockPin, MSBFIRST, column);
      shiftOut(dataPin, clockPin, MSBFIRST, row);
      digitalWrite(latchPin, HIGH);
    }

    
    if (i == 3)
    {

      column = 0xEF;
      row = 0x40;
      digitalWrite(latchPin, LOW);
      shiftOut(dataPin, clockPin, MSBFIRST, column);
      shiftOut(dataPin, clockPin, MSBFIRST, row);
      digitalWrite(latchPin, HIGH);
    }

    if (i == 4)
    {
 
      column = 0xF7;
      row = 0x00;

      digitalWrite(latchPin, LOW);
      shiftOut(dataPin, clockPin, MSBFIRST, column);
      shiftOut(dataPin, clockPin, MSBFIRST, row);
      digitalWrite(latchPin, HIGH);
    }
    
    }
  }
