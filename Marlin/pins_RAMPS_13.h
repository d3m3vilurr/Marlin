/**
 * Arduino Mega with RAMPS v1.3 pin assignments
 *
 * Applies to the following boards:
 *
 *  RAMPS_13_EFB (Extruder, Fan, Bed)
 *  RAMPS_13_EEB (Extruder, Extruder, Bed)
 *  RAMPS_13_EFF (Extruder, Fan, Fan)
 *  RAMPS_13_EEF (Extruder, Extruder, Fan)
 *  RAMPS_13_SF  (Spindle, Controller Fan)
 *
 *  Other pins_MYBOARD.h files may override these defaults
 */

#if !defined(__AVR_ATmega1280__) && !defined(__AVR_ATmega2560__)
  #error Oops!  Make sure you have 'Arduino Mega' selected from the 'Tools -> Boards' menu.
#endif

#define LARGE_FLASH true

#define X_STEP_PIN         54
#define X_DIR_PIN          55
#define X_ENABLE_PIN       38
#define X_MIN_PIN           3
#define X_MAX_PIN           2

#define Y_STEP_PIN         60
#define Y_DIR_PIN          61
#define Y_ENABLE_PIN       56
#define Y_MIN_PIN          14
#define Y_MAX_PIN          15

#define Z_STEP_PIN         46
#define Z_DIR_PIN          48
#define Z_ENABLE_PIN       62
#define Z_MIN_PIN          18
#define Z_MAX_PIN          19
#define Z_PROBE_PIN        -1

#define Y2_STEP_PIN        36
#define Y2_DIR_PIN         34
#define Y2_ENABLE_PIN      30

#undef Z2_STEP_PIN
#undef Z2_DIR_PIN
#undef Z2_ENABLE_PIN

#define Z2_STEP_PIN        36
#define Z2_DIR_PIN         34
#define Z2_ENABLE_PIN      30

#define E0_STEP_PIN        26
#define E0_DIR_PIN         28
#define E0_ENABLE_PIN      24

#define E1_STEP_PIN        36
#define E1_DIR_PIN         34
#define E1_ENABLE_PIN      30

#define SDPOWER            -1
#define SDSS               53
#define LED_PIN            13

#if MB(RAMPS_13_EEB) && ENABLED(FILAMENT_SENSOR)  // FMM added for Filament Extruder
  // define analog pin for the filament width sensor input
  // Use the RAMPS 1.4 Analog input 5 on the AUX2 connector
  #define FILWIDTH_PIN        5
#endif

#if ENABLED(Z_PROBE_ENDSTOP)
  // Define a pin to use as the signal pin on Arduino for the Z_PROBE endstop.
  #define Z_PROBE_PIN 32
#endif

#if ENABLED(FILAMENT_RUNOUT_SENSOR)
  // define digital pin 4 for the filament runout sensor. Use the RAMPS 1.4 digital input 4 on the servos connector
  #define FILRUNOUT_PIN        4
#endif

#if MB(RAMPS_13_EFF) || ENABLED(IS_RAMPS_EFB)
  #define FAN_PIN            9 // (Sprinter config)
  #if MB(RAMPS_13_EFF)
    #define CONTROLLERFAN_PIN  -1 // Pin used for the fan to cool controller
  #endif
#elif MB(RAMPS_13_EEF) || MB(RAMPS_13_SF)
  #define FAN_PIN            8
#else
  #define FAN_PIN            4 // IO pin. Buffer needed
#endif

#define PS_ON_PIN          12

#if ENABLED(REPRAP_DISCOUNT_SMART_CONTROLLER) || ENABLED(G3D_PANEL)
  #define KILL_PIN           41
#else
  #define KILL_PIN           -1
#endif

#if MB(RAMPS_13_EFF)
  #define HEATER_0_PIN       8
#else
  #define HEATER_0_PIN       10   // EXTRUDER 1
#endif

#if MB(RAMPS_13_SF) || ENABLED(IS_RAMPS_EFB)
  #define HEATER_1_PIN       -1
#else
  #define HEATER_1_PIN       9    // EXTRUDER 2 (FAN On Sprinter)
#endif

#define HEATER_2_PIN       -1

#define TEMP_0_PIN         13   // ANALOG NUMBERING
#define TEMP_1_PIN         15   // ANALOG NUMBERING
#define TEMP_2_PIN         -1   // ANALOG NUMBERING

#if MB(RAMPS_13_EFF) || MB(RAMPS_13_EEF) || MB(RAMPS_13_SF)
  #define HEATER_BED_PIN     -1    // NO BED
#else
  #define HEATER_BED_PIN     8    // BED
#endif

#define TEMP_BED_PIN       14   // ANALOG NUMBERING

#if HAS_SERVOS
  #define SERVO0_PIN         11
  #if NUM_SERVOS > 1
    #define SERVO1_PIN        6
    #if NUM_SERVOS > 2
      #define SERVO2_PIN      5
      #if NUM_SERVOS > 3
        #define SERVO3_PIN    4
      #endif
    #endif
  #endif
#endif

#if ENABLED(Z_PROBE_SLED)
  #define SLED_PIN         -1
#endif

#if ENABLED(ULTRA_LCD)

  #if ENABLED(NEWPANEL)
    #if ENABLED(PANEL_ONE)
      #define LCD_PINS_RS 40
      #define LCD_PINS_ENABLE 42
      #define LCD_PINS_D4 65
      #define LCD_PINS_D5 66
      #define LCD_PINS_D6 44
      #define LCD_PINS_D7 64
    #else
      #define LCD_PINS_RS 16
      #define LCD_PINS_ENABLE 17
      #define LCD_PINS_D4 23
      #define LCD_PINS_D5 25
      #define LCD_PINS_D6 27
      #define LCD_PINS_D7 29
    #endif

    #if ENABLED(REPRAP_DISCOUNT_SMART_CONTROLLER)
      #define BEEPER_PIN 37

      #define BTN_EN1 31
      #define BTN_EN2 33
      #define BTN_ENC 35

      #define SDCARDDETECT 49
    #elif ENABLED(LCD_I2C_PANELOLU2)
      #define BTN_EN1 47  // reverse if the encoder turns the wrong way.
      #define BTN_EN2 43
      #define BTN_ENC 32
      #define LCD_SDSS 53
      #define SDCARDDETECT -1
      #define KILL_PIN 41
    #elif ENABLED(LCD_I2C_VIKI)
      #define BTN_EN1 22  // reverse if the encoder turns the wrong way.
      #define BTN_EN2 7
      #define BTN_ENC -1
      #define LCD_SDSS 53
      #define SDCARDDETECT 49
    #elif ENABLED(ELB_FULL_GRAPHIC_CONTROLLER)
      #define BTN_EN1 35  // reverse if the encoder turns the wrong way.
      #define BTN_EN2 37
      #define BTN_ENC 31
      #define SDCARDDETECT 49
      #define LCD_SDSS 53
      #define KILL_PIN 41
      #define BEEPER_PIN 23
      #define DOGLCD_CS 29
      #define DOGLCD_A0 27
      #define LCD_PIN_BL 33
    #elif defined(MINIPANEL)
       #define BEEPER_PIN 42
       // Pins for DOGM SPI LCD Support
       #define DOGLCD_A0  44
       #define DOGLCD_CS  66
       #define LCD_PIN_BL	65	// backlight LED on A11/D65
       #define SDSS   53
       
       #define KILL_PIN 64
       // GLCD features
       //#define LCD_CONTRAST 190
       // Uncomment screen orientation
         // #define LCD_SCREEN_ROT_90
         // #define LCD_SCREEN_ROT_180
         // #define LCD_SCREEN_ROT_270
       //The encoder and click button
       #define BTN_EN1 40
       #define BTN_EN2 63
       #define BTN_ENC 59  //the click switch
       //not connected to a pin
       #define SDCARDDETECT 49

    #else

      #define BEEPER_PIN 33  // Beeper on AUX-4

      // buttons are directly attached using AUX-2
      #if ENABLED(REPRAPWORLD_KEYPAD)
        #define BTN_EN1 64 // encoder
        #define BTN_EN2 59 // encoder
        #define BTN_ENC 63 // enter button
        #define SHIFT_OUT 40 // shift register
        #define SHIFT_CLK 44 // shift register
        #define SHIFT_LD 42 // shift register
      #elif ENABLED(PANEL_ONE)
        #define BTN_EN1 59 // AUX2 PIN 3
        #define BTN_EN2 63 // AUX2 PIN 4
        #define BTN_ENC 49 // AUX3 PIN 7
      #else
        #define BTN_EN1 37
        #define BTN_EN2 35
        #define BTN_ENC 31  // the click
      #endif

      #if ENABLED(G3D_PANEL)
        #define SDCARDDETECT 49
      #else
        #define SDCARDDETECT -1  // Ramps does not use this port
      #endif

    #endif
  #else // !NEWPANEL (Old-style panel with shift register)

    #define BEEPER_PIN 33   // No Beeper added

    // Buttons are attached to a shift register
    // Not wired yet
    // #define SHIFT_CLK 38
    // #define SHIFT_LD 42
    // #define SHIFT_OUT 40
    // #define SHIFT_EN 17

    #define LCD_PINS_RS 16
    #define LCD_PINS_ENABLE 17
    #define LCD_PINS_D4 23
    #define LCD_PINS_D5 25
    #define LCD_PINS_D6 27
    #define LCD_PINS_D7 29

  #endif // !NEWPANEL

#endif // ULTRA_LCD

// SPI for Max6675 Thermocouple
#if DISABLED(SDSUPPORT)
  #define MAX6675_SS       66 // Do not use pin 53 if there is even the remote possibility of using Display/SD card
#else
  #define MAX6675_SS       66 // Do not use pin 49 as this is tied to the switch inside the SD card socket to detect if there is an SD card present
#endif

#if DISABLED(SDSUPPORT)
  // these pins are defined in the SD library if building with SD support
  #define SCK_PIN          52
  #define MISO_PIN         50
  #define MOSI_PIN         51
#endif
