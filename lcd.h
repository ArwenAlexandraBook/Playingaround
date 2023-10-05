#ifndef LCD_H
#define LCD_H

#include <stdint.h>

#define LCD_RS_PIN 2  // GPIO-pin till RS
#define LCD_EN_PIN 3  // GPIO-pin till EN 
#define LCD_D4_PIN 4  // GPIO-pin till D4
#define LCD_D5_PIN 5  // GPIO-pin till D5
#define LCD_D6_PIN 6  // GPIO-pin till D6
#define LCD_D7_PIN 7  // GPIO-pin till D7

#define COL_COUNT 16  //Kolumner på LCD skärmen
#define LCD_ROW_COUNT 2

void lcd_init(void);

void lcd_clear(void);

void lcd_command(uint_ command); 

void lcd_on (void);
void lcd_off(void);

void lcd_return_home(void)

void lcd_enable_blinking(void);
void lcd_disable_blinking(void);

void lcd_enable_cursor(void);
void lcd_lcd_disable_cursor(void)

void lcd_scroll_left(void);
void lcd_scroll_right(void);

void lcd_lcd_enable_autoscroll(void);
void lcd_disable_autoscroll(void);

void lcd_create_char(uint8_t location, uint8_t *charmap); 

void lcd_set_cursor(uint8 col, uint8_t row);

void lcd_puts(char *string);
void lcd_printf(char *format,... );


#endif 
