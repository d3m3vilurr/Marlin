/**
 * Teensy++ 2.0 Breadboard pin assignments (AT90USB1286)
 * Requires the Teensyduino software with Teensy++ 2.0 selected in Arduino IDE!
 * http://www.pjrc.com/teensy/teensyduino.html
 * See http://reprap.org/wiki/Printrboard for more info
 *
 * CLI build: DEFINES=AT90USBxx_TEENSYPP_ASSIGNMENTS HARDWARE_MOTHERBOARD=84 make
 *
 *  DaveX plan for Teensylu/printrboard-type pinouts for a TeensyBreadboard:
 *  (ref teensylu & sprinter)
 *
 *                               USB
 *           GND       GND |-----#####-----| +5V              ATX +5SB
 *     ATX PS_ON    PWM 27 |b7   #####   b6| 26    PWM*       Stepper Enable 
 *                  PWM  0 |d0           b5| 25    PWM*        
 *                  PWM  1 |d1           b4| 24    PWM        
 *         X_MIN         2 |d2           b3| 23               MISO_PIN
 *         Y_MIN         3 |d3           b2| 22               MOSI_PIN
 *         Z_MIN         4 |d4  * *      b1| 21               SCK_PIN       
 *                       5 |d5  e e      b0| 20               SDSS              
 *                LED    6 |d6  5 4      e7| 19               
 *                       7 |d7           e6| 18               
 *       LCD  RS         8 |e0             | GND              
 *       LCD  EN         9 |e1   a4 a0    R| AREF             
 *       LCD  D4        10 |c0   a5 a1   f0| 38 A0            ENC_1           
 *       LCD  D5        11 |c1   a6 a2   f1| 39 A1            ENC_2
 *       LCD  D6        12 |c2   a7 a3   f2| 40 A2            ENC_CLK
 *       LCD  D6        13 |c3           f3| 41 A3            
 *      Bed Heat    PWM 14 |c4   V G R   f4| 42 A4            
 * Extruder Heat    PWM 15 |c5   c n S   f5| 43 A5            
 *           Fan    PWM 16 |c6   c d T   f6| 44 A6            Bed TC
 *                      17 |c7   * * *   f7| 45 A7            Extruder TC * 4.7k * +5        
 *                         -----------------                  
 *
 *      Interior E4: 36, INT4
 *      Interior E5: 37, INT5
 *      Interior PA0-7: 28-35  -- Printrboard and Teensylu use these pins for step & direction:
 *             T++ PA Signal  Marlin
 *    
 *       Z STEP  32 a4  a0 28 X STEP
 *       Z DIR   33 a5  a1 29 X DIR
 *       E STEP  34 a6  a2 30 Y STEP
 *       E DIR   35 a7  a3 31 Y DIR
 */

#ifndef __AVR_AT90USB1286__
  #error Oops!  Make sure you have 'Teensy++ 2.0' selected from the 'Tools -> Boards' menu.
#endif

#ifndef AT90USBxx_TEENSYPP_ASSIGNMENTS  // use Teensyduino Teensy++2.0 pin assignments instead of Marlin alphabetical.
  #error  Uncomment #define AT90USBxx_TEENSYPP_ASSIGNMENTS in fastio.h for this config
  // (or build from command line)
#endif

#define LARGE_FLASH        true

#define X_STEP_PIN         28 //  0 Marlin
#define X_DIR_PIN          29 //  1 Marlin
#define X_ENABLE_PIN       26 

#define Y_STEP_PIN         30 //  2 Marlin
#define Y_DIR_PIN          31 //  3
#define Y_ENABLE_PIN       26     // Shared w/x

#define Z_STEP_PIN         32 //  4
#define Z_DIR_PIN          33 //  5
#define Z_ENABLE_PIN       26 // Shared w/x

#define E0_STEP_PIN        34 //  6
#define E0_DIR_PIN         35 //  7
#define E0_ENABLE_PIN      26 // Shared w/x

#define HEATER_0_PIN       15 //  21  // Extruder
#define HEATER_1_PIN       -1
#define HEATER_2_PIN       -1
#define HEATER_BED_PIN     14 // 20  // Bed
#define FAN_PIN            16 // 22  // Fan

#define X_STOP_PIN          2
#define Y_STOP_PIN          3
#define Z_STOP_PIN          4

#define TEMP_0_PIN          7 // Extruder / Analog pin numbering
#define TEMP_BED_PIN        6 // Bed / Analog pin numbering
#define TEMP_1_PIN         -1
#define TEMP_2_PIN         -1

#define SDPOWER            -1
#define SDCARDDETECT       -1   
#define SDSS               20 // 8
#define LED_PIN             6
#define PS_ON_PIN          27
#define KILL_PIN           -1
#define ALARM_PIN          -1

#if DISABLED(SDSUPPORT)
// these pins are defined in the SD library if building with SD support
  #define SCK_PIN         21 // 9
  #define MISO_PIN        23 // 11
  #define MOSI_PIN        22 // 10
#endif

#if ENABLED(ULTIPANEL)
  #define LCD_PINS_RS         8
  #define LCD_PINS_ENABLE     9
  #define LCD_PINS_D4        10
  #define LCD_PINS_D5        11
  #define LCD_PINS_D6        12
  #define LCD_PINS_D7        13
  #define BTN_EN1            38
  #define BTN_EN2            39
  #define BTN_ENC            40
#endif
