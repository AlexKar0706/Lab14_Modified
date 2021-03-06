#ifndef SSD1306_H
#define SSD1306_H

// 0. Slave address table
#define SSD1306_ADDRESS 0x78

// 1. Fundamental Command Table
#define SSD1306_CONTRAST 0x81
#define SSD1306_ENTIRE_DISPLAY_OFF 0xA4
#define SSD1306_ENTIRE_DISPLAY_ON 0xA5
#define SSD1306_INVERSE_DISPLAY_OFF 0xA6
#define SSD1306_INVERSE_DISPLAY 0xA7
#define SSD1306_DISPLAY_OFF 0xAE
#define SSD1306_DISPLAY_ON 0xAF

// 2. Scrolling Command Table
#define SSD1306_SCROLL_CONTINUOUS_H_RIGHT 0x26
#define SSD1306_SCROLL_CONTINUOUS_H_LEFT 0x27
#define SSD1306_SCROLL_CONTINUOUS_HV_RIGHT 0x29
#define SSD1306_SCROLL_CONTINUOUS_HV_LEFT 0x2A
#define SSD1306_SCROLL_V_AREA 0xA3
#define SSD1306_SCROLL_STOP 0x2E
#define SSD1306_SCROLL_START 0x2F
#define SSD1306_SCROLL_PAGE0 0x00
#define SSD1306_SCROLL_PAGE1 0x01
#define SSD1306_SCROLL_PAGE2 0x02
#define SSD1306_SCROLL_PAGE3 0x03
#define SSD1306_SCROLL_PAGE4 0x04
#define SSD1306_SCROLL_PAGE5 0x05
#define SSD1306_SCROLL_PAGE6 0x06
#define SSD1306_SCROLL_PAGE7 0x07
#define SSD1306_SCROLL_TIME_5FRAMES 0x00
#define SSD1306_SCROLL_TIME_64FRAMES 0x01
#define SSD1306_SCROLL_TIME_128FRAMES 0x02
#define SSD1306_SCROLL_TIME_265FRAMES 0x03
#define SSD1306_SCROLL_TIME_3FRAMES 0x04
#define SSD1306_SCROLL_TIME_4FRAMES 0x05
#define SSD1306_SCROLL_TIME_25FRAMES 0x06
#define SSD1306_SCROLL_TIME_2FRAMES 0x07

// 3. Addressing Setting Command Table
#define SSD1306_ADDR_LOWER_COLUMN_PAGE_MODE 0x00
#define SSD1306_ADDR_HIGHER_COLUMN_PAGE_MODE 0x10
#define SSD1306_ADDR_MODE 0x20
#define SSD1306_ADDR_COL_HV 0x21
#define SSD1306_ADDR_PAGE_HV 0x22
#define SSD1306_ADDR_PAGE 0xB0

// 4. Hardware Configuration (Panel resolution & layout related) Command Table 
#define SSD1306_DISPLAY_START_LINE 0x40
#define SSD1306_DISPLAY_OFFSET 0xD3
#define SSD1306_SEG_REMAP_0 0xA0
#define SSD1306_SEG_REMAP_127 0xA1
#define SSD1306_MUX_RATIO 0xA8
#define SSD1306_COM_REMAP_NORMAL 0xC0
#define SSD1306_COM_REMAP_REVERSE 0xC8
#define SSD1306_SET_COM_PINS 0xDA

// 5. Timing & Driving Scheme Setting Command Table
#define SSD1306_DISPLAY_CLOCK 0xD5
#define SSD1306_PRECHARGE 0xD9
#define SSD1306_VCOMH_LVL 0xDB
#define SSD1306_NOP 0xE3

// 6. Charge Pump Command Table 
#define SSD1306_CHARGE_PUMP_REGULATOR 0x8D

#define SSD1306_WITH_PLL 1
#define SSD1306_WITHOUT_PLL 0

#ifdef __cplusplus
extern "C" {
#endif

typedef enum SSD1306_Err_Status {
SSD1306_OK, SSD1306_I2C_ERR, SSD1306_WRONG_DATA} SSD1306Status;
	
SSD1306Status SSD1306_Send_Commands(unsigned const char* buffer, unsigned long n_Bytes);
SSD1306Status SSD1306_Init(unsigned short PLLoption);
SSD1306Status SSD1306_SetCursor(unsigned short newX, unsigned short newY);
SSD1306Status SSD1306_SetPixel(unsigned short x, unsigned short y);
SSD1306Status SSD1306_Draw(void);
SSD1306Status SSD1306_Write_Char(const char ch);
SSD1306Status SSD1306_Write_Str(const char* str);
SSD1306Status SSD1306_Clear_Display(void);

#ifdef __cplusplus
}
#endif

#endif
