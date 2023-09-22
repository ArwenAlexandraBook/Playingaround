#include <Arduino.h> 
#include <stdio.h>
#include <string.h> 
#include "lcd.h"


#define RED_BUTTON_PIN 0  //Röda knappens pin
#define YELLOW_BUTTON_PIN 1 //Gula knappens pin
#define GREEN_BUTTON_PIN 2 // Gröna knappens pin

const int buttonPin[] {RED_BUTTON_PIN, YELLOW_BUTTON_PIN, GREEN_BUTTON_PIN};
const int numButton[] sizedof (buttonPin) / sizeof (buttonPin[0]);

char currentText[5] = {0};
char questionText [20] = " "; //Frågan som står på LCD-skärmen


void HandleButtonClick(char *txt) {
    _delay_ms(200);
    strcat(currenText,txt);
    lcd_set_cursor (0,1)
    lcd_puts(currentText);
    return;


if (strl(currentText)==4) {
if (strcmp("1442",currentText)) 
    lcd_printf("That's correct!"); 
}else{
    lcd_printf("Incorrct code!"); //Felmeddelande
    _delay_ms(3000);
    lcd_set_cursor(0,1); //LCD-cursor rad 1
    lcd_puts( "  ");
    lcd_set_cursor (0,1); 
}
currentText[0] = 0;

void setup () {
    for (int i = 0; i <numButton; i++) {
        pinMode(buttonPin[i], INPUT_PULLUP)
    }

millis_init();

lcd_init(); // Initialiserar LCD
lcd_enable_blinking(); // Aktiverar blink
lcd_enable_cursor(); // Aktiverar cursor

lcd_set_cursor (0,0) //LCD-cursor rad 0 
lcd_puts(questionText); //Frågan visas på lcd skärmen
}


while(1)
{
if RED_BUTTON_PIN {HandleButtonClick ("1"); // Röd knapp ger värde 1
}
if YELLOW_BUTTON_PIN {HandleButtonClick ("2"); //Guld knapp ger värde 2
}
if GREEN_BUTTON_PIN {HandleButtonClick ("3"); //Grön kanpp värde 3
}
return;     
}