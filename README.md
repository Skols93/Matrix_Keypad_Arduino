# Matrix_Keypad_Arduino
Arduino code for testing matrix keypad functionality

In the code written in Arduino IDE is demnostrated the work of a matrix keypad consisted of three rows and four columns.

The three row pins and four column pins are attached to Arduino board.

Assigned pins for the three row pins and the four column pins is in the code below.

pinMode(2, OUTPUT);
pinMode(3, OUTPUT);
pinMode(4, OUTPUT);

pinMode(5, INPUT);
pinMode(6,INPUT);
pinMode(7, INPUT);
pinMode(8, INPUT);

Row pins must be outputs and column pins must be inputs because we have to multiplex the keys to determine the pressed key on the keypad.

