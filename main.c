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

struct ButtonEvent {
    int button;
    unsigned long timestamp;
};

ButtonMemory buttonEvent [60] //Sparar knapptryckningar

void HandleButtonClick(char *txt) {
    delay(200);
    strcat(currentText, *txt) {
        lcd_set_cursor(0, 1);
        lcd_puts(currentText);
    return;

if (strlen(currentText) == 4) {
    if (strcmp("1442",currentText)==0) {
         lcd_printf("That's correct!"); 
}else{
    lcd_printf("Incorrct code!"); //Felmeddelande
    delay(3000);
    lcd_set_cursor(0, 1); //LCD-cursor rad 1
    lcd_puts( "  ");
    lcd_set_cursor (0,1); 
}
currentText[0] = 0;
}

}

void setup () {
    for (int i = 0; i <numButton; i++) {
        pinMode(buttonPin[i], INPUT_PULLUP);
    }

millis_init();

lcd_init(); // Initialiserar LCD
lcd_enable_blinking(); // Aktiverar blink
lcd_enable_cursor(); // Aktiverar cursor

lcd_set_cursor (0, 0) //LCD-cursor rad 0 
lcd_puts(questionText); //Frågan visas på lcd skärmen
}


void loop() {

for (int i =0; i <numButton; i++) {
    if (digitalRead(buttonPin[i]) == LOW) {

        if (numEvent < sideof(buttonEvent) / sizeof(buttonEvent[0]))
        buttonEvent[numEvent].button =i;
        buttonEvent[numEvents].timestamp =millis();
        numEvents++;
}