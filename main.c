#include <stdio.h>
#include <string.h>
#include "lcd.h"

#define RED_BUTTON_PIN 2    // Röda knappens pin
#define YELLOW_BUTTON_PIN 4 // Gula knappens pin
#define GREEN_BUTTON_PIN 5  // Gröna knappens pin

const int buttonPin[]{RED_BUTTON_PIN, YELLOW_BUTTON_PIN, GREEN_BUTTON_PIN};
const int numButton[] sizeof(buttonPin) / sizeof(buttonPin[0]);

char currentText[5] = {0};
char questionText[20] = " "; // Frågan som står på LCD-skärmen

struct ButtonEvent
{
    int button;
    unsigned long timestamp;
};

struct ButtonEvent buttonEvents[60] // Sparar knapptryckningar
    int numEvents = 0;

void HandleButtonClick(char *txt)
{
    delay(200);
    strcat(currentText, txt);
    lcd_set_cursor(0, 1);
    lcd_puts(currentText);

    if (strlen(currentText) == 4)
    {
        if (strcmp("1442", currentText) == 0)
        {
            lcd_printf("That's correct!");
        }
        else
        {
            lcd_printf("Incorrct code!"); // Felmeddelande
            delay(3000);
            lcd_set_cursor(0, 1); // LCD-cursor rad 1
            lcd_puts("  ");
            lcd_set_cursor(0, 1);
        }
        currentText[0] = 0;
    }
}

void setup()
{
    for (int i = 0; i < numButton; i++)
    {
        pinMode(buttonPin[i], INPUT_PULLUP);
    }

    lcd_init();            // Initialiserar LCD
    lcd_enable_blinking(); // Aktiverar blink
    lcd_enable_cursor();   // Aktiverar cursor

    lcd_set_cursor(0, 0);   // LCD-cursor rad 0
    lcd_puts(questionText); // Frågan visas på lcd skärmen
}

void loop()
{

    for (int i = 0; i < numButton; i++)
    {
        if (digitalRead(buttonPin[i]) == LOW)
        {

            if (numEvents < sideof(buttonEvents) / sizeof(buttonEvents[0]))
            {
                buttonEvents[numEvents].button = i;
            buttonEvents[numEvents].timestamp = millis();
            numEvents++;
        }
    }
}
}
