int latchPin = 12;
int clockPin = 11;
int dataPin = 13;
int column = 0;
int row = 0;

int columns[] = {0x7f, 0xbf, 0xdf, 0xef, 0xf7};

int zero[] = {0x3E, 0x45, 0x49, 0x51, 0x3E};
int one[] = {0x00, 0x40, 0x7F, 0x42, 0x00};
int two[] = {0x46, 0x49, 0x51, 0x61, 0x42};
int three[] = {0x31, 0x4B, 0x45, 0x41, 0x21};
int four[] = {0x10, 0x7F, 0x12, 0x14, 0x18};
int five[] = {0x39, 0x45, 0x45, 0x45, 0x27};
int six[] = {0x30, 0x49, 0x49, 0x4A, 0x3C};
int seven[] = {0x03, 0x05, 0x09, 0x71, 0x01};
int eight[] = {0x36, 0x49, 0x49, 0x49, 0x36};
int nine[] = {0x1E, 0x29, 0x49, 0x49, 0x06};


void setup() {
  // put your setup code here, to run once:

  /*
   * Turn this code from Arduino functions
   * to register operations for PORTB
  pinMode(latchPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  */

  //Output Data
  DDRB = 0b00111000; //sets port b pin 13 as output
                     //sets port b pin 12 as output
                     //sets port b pin 11 as output
}

void display_number(int row, int column)
{
  /* Turn this code from Arduino functions
   *  to output operations for PORTB
   *  digitalWrite(latchPin, LOW);
      shiftOut(dataPin, clockPin, MSBFIRST, column);
      shiftOut(dataPin, clockPin, MSBFIRST, row);
      digitalWrite(latchPin, HIGH);
   */
   PORTB = 0b00000000; //set latchbit low
   shift_out(column);
   shift_out(row);
   PORTB = 0b00010000; //set latchbit high
   
   
}

void shift_out(int output)
{
  int bit_value = 0;
  
  for (int i = 7; i >= 0; i--)
  {
    bit_value = bitRead(output, i);

    if (bit_value == 1)
    {
      PORTB = 0b00100000;
    }
    else
    {
      PORTB = 0b00000000;
    }
  
  PORTB = 0b00001000;//set clock high
  PORTB = 0b00000000;//set clock low
  }
}

void loop() {
  // put your main code here, to run repeatedly:

  for (int i = 0; i < 5000; i++)
  {
    for (int i = 0; i < 5; i++)
    {
      display_number(zero[i], columns[i]);
    }
  }

  for (int i = 0; i < 5000; i++)
  {
    for (int i = 0; i < 5; i++)
    {
      display_number(one[i], columns[i]);
    }
  }

  for (int i = 0; i < 5000; i++)
  {
    for (int i = 0; i < 5; i++)
    {
      display_number(two[i], columns[i]);
    }
  }

  for (int i = 0; i < 5000; i++)
  {
    for (int i = 0; i < 5; i++)
    {
      display_number(three[i], columns[i]);
    }
  }
  for (int i = 0; i < 5000; i++)
  {
    for (int i = 0; i < 5; i++)
    {
      display_number(four[i], columns[i]);
    }
  }

    for (int i = 0; i < 5000; i++)
  {
    for (int i = 0; i < 5; i++)
    {
      display_number(five[i], columns[i]);
    }
  }

  for (int i = 0; i < 5000; i++)
  {
    for (int i = 0; i < 5; i++)
    {
      display_number(six[i], columns[i]);
    }
  }

  for (int i = 0; i < 5000; i++)
  {
    for (int i = 0; i < 5; i++)
    {
      display_number(seven[i], columns[i]);
    }
  }

  for (int i = 0; i < 5000; i++)
  {
    for (int i = 0; i < 5; i++)
    {
      display_number(eight[i], columns[i]);
    }
  }

  for (int i = 0; i < 5000; i++)
  {
    for (int i = 0; i < 5; i++)
    {
      display_number(nine[i], columns[i]);
    }
  }

  
}
