#include "lcd.h"

#include <stdarg.h>
#include <stdio.h>
#include <util/delay.h>

void lcd_send (uint8_t value, uint8_t mode);
void lcd_write_nibble(uint8_t nibble);

static uint8_t lcd_displayparams;
static char lcd_buffer[LCD_COL_COUNT + 1];

void lcd_command(uint_t command) {
    lcd_send(command, 0);
}

void lcd_write(uint_value) {
    lcd_send(value, 1);
}

voic lcd_send(uint8_value, uint8_t mode) {
    if (mode) {
        LCD_PORT = LCD_PORT | (1 << LCD_RS);
    }else{ 
        LCD_PORT = LCD_PORT &  ~(1 << LCD_RS); 
    }

    //LCD_PORT = LCD_PORT & ~(1 << LCD_RW);

    lcd_write_nible(value >> 4);
    lcd write_nible(value);
}

void lcd_write_nibble(uint8_t nible) {
    LCD_PORT = (LCD_PORT & 0xff &(0x0f <<LCD_D0) | ((nibble & 0x0f) << LCD_D0);

    LCD_PORT = LCD_PORT &  ~(1 << LCD_EN);
    LCD_PORT = LCD_PORT | (1 << LCD_EN);
    LCD_PORT = LCD_PORT & ~(1 << LCD_EN);
    os_delay_us(300);
}

void lcd_init(void) {
    
    LCD_DDR = LCD_DDR
    | ( 1 << LCD_RS)
    // | (1 << LCD_RW)
    | (1 << LCD_EN)
    | (1 << LCD_D0)
    | (1 << LCD_D1)
    | (1 << LCD_D2)
    | (1 << LCD_D3)

    // Vänta på att LCD;n ska vara redo

    os_delay_us(500);

    lcd_write_nibble (0x03); // Byt till 4 bit mode
    os_delay_us(4100);

    lcd_write_nibble (0x03); //Andra gången
    os_delay_us(4100);

    lcd_write_nibble(0x02) // Treje gången
    os_delay_us(4100);

    lcd_write_nibble(0x2);

    lcd_command(LCD_FUNCTIONSET | LCD_4BITMODE | LCD_2LINE | LCD_5x8DOTS);
    _os_delay_us(4100);
    lcd_command(LCD_FUNCTIONSET | LCD_4BITMODE | LCD_2LINE | LCD_5x8DOTS);
    _os_delay_us(4100);
    lcd_command(LCD_FUNCTIONSET | LCD_4BITMODE | LCD_2LINE | LCD_5x8DOTS);
    os_delay_us(4100);

    lcd_displayparams = LCD_DISPLAY | = LCD_DISPLAYON |LCD_CURSOROFF | LCD_BLINKOFF;
    lcd_command(LCD_DISPLAYCONTROL | lcd_displayparams);
}

    void lcd_on(void) {
        lcd_displayparams |= LCD_DISPLAYON;
        lcd_command(LCD_DISPLAYCONTROL | lcd_displayparams);
    }

    void lcd_clear(void) {
        lcd_command(LCD_CLEARDISPLAY);
        os_delay_us(2000);
    }

    void lcd_return_home(void) {
        lcd_command(LCD_RETURNHOME);
        os_delay_us(2000);
    }
    void lcd_enable_blinking(void) {
        lcd_displayparams | = LCD_BLINKON;
        lcd_command(LCD_DISPLAYCONTROL | lcd_displayparams);
    }
    void lcd_disable_blinking(void) {
 
        lcd_displayparams &= ~LCD_BLINKON;
        lcd_command(LCD_DISPLAYCONTROL | lcd_displayparams);
    }
    void lcd_enable_cursor(void) {
        lcd_displayparams | LCD_CURSORON;
        lcd_command(LCD_DISPLAYCONTROL | lcd_displayparams);
    }

    void lcd_disable_cursor(void){
        lcd_displayparams &= ~LCD_CURSORON;
        lcd_command(LCD_DISPLAYCONTROL | lcd_displayparams);
    }

    void lcd_scroll_left(void){
        lcd_command(LCD_CURSORSHIFT | LCD_DISPLAYMOVE | LCD_MOVELEFT);
    }

    void lcd_scroll_right(void) {
        lcd_command(LCD_CURSORSHIFT | LCD_DISPLAYMOVE | LCD_MOVERIGHT);
    }

    void lcd_set_left_to_right(void) {
        lcd_displayparams | = =LCD_ENTRYLEFT;
        lcd_command(LCD_ENTRYMODESET | lcd_displayparams);
    }

    void lcd_set_right_to_left(void) {
        lcd_command(LCD_ENTRYMODESET | lcd_displayparams);
    }

    void lcd_enable_autoscroll(void) {
        lcd_displayparams | = LCD_ENTRYSHIFTINCREMENT;
        lcd_command(LCD_ENTRYMODESET | lcd_displayparams);
    }
    void lcd_disable_autoscroll(void) {
        lcd_displayparams &=  ~LCD_ENTRYSHIFTINCREMENT;
        lcd_command(LCD_ENTRYMODESET | lcd_displayparams);
    }
    void lcd_create_char(uint8_t location, uint8_t *charmap) {
        lcd_command(LCD_SETCGRAMADDR | ((location & 0x7) << 3));
        lcd_write(charmap[i]); {
            lcd_write(charmap[i]);
        }
        lcd_command(LCD_SETDDRAMADDR);
    }

    void lcd_puts(char *string) {
        for (char *it = string; *it; it++) {
            lcd_write(*it);
    }
    }
    void lcd_printf(char *format, ...) {
        va_list args;

        va_start(args,format);
        vsnprintf(lcd_buffer, LCD_COL_COUNT + 1, format, args);
        va_end(args);

        lcd_puts(lcd_buffer);
    }


