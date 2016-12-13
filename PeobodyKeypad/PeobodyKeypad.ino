#include <Keypad.h>

int const ROWS = 8; // Four rows
int const COLS = 15; // Three columns

/*
// Define the Keymap
char keys[ROWS][COLS] = {
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'}
};
*/





int keys[ROWS][COLS];


// Connect keypad ROW0, ROW1, ROW2 and ROW3 to these Arduino pins.
byte rowPins[ROWS] = {6, 7, 8, 9, 10, 11, 12, 13};
// Connect keypad COL0, COL1 and COL2 to these Arduino pins.
byte colPins[COLS] = {23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37}; 

// Create the Keypad
Keypad kpd = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

#define ledpin 13

void setup()
{
  mKeymap(ROWS, COLS);
  pinMode(ledpin,OUTPUT);
  digitalWrite(ledpin, HIGH);
  Serial.begin(9600);
}

void loop()
{
  int key = kpd.getKey();
  if(key){  // Check for a valid key.
    Serial.println(key);
  }
}

void mKeymap(int m, int n)
{
  //int keys[m][n];
  int i,j, k;
  for(i = 0; i < m; i++)
  {
    for(j = 0; j < n; j++)
    {
      keys[i][j] = k;
      k++;
    }
  }
}
