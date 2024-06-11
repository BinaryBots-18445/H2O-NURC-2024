#include <LiquidCrystalFast.h>
#include "USBHost_t36.h"
#define LCD_RS 5
#define LCD_RW 6
#define LCD_E 7
#define LCD_D4 24
#define LCD_D5 25
#define LCD_D6 26
#define LCD_D7 27
USBHost myusb;
USBHub hub1(myusb);
USBHIDParser hid1(myusb);
#define COUNT_JOYSTICKS 4
JoystickController joystick[COUNT_JOYSTICKS] = {
  JoystickController(myusb), JoystickController(myusb), JoystickController(myusb), JoystickController(myusb)
};
// int user_axis[64];
// uint32_t buttons_prev = 0;
char namebuf[100] = {0};
USBDriver *drivers[] = {&hub1, &joystick[0], &joystick[1], &joystick[2], &joystick[3], &hid1};
// #define CNT_DEVICES (sizeof(drivers)/sizeof(hiddrivers[0]))
// const char * hid_driver_names[CNT_DEVICES] = {"joystick[0H]", "joystick[1H]", "joystick[2H]", "joystick[3H]"};
// bool driver_active[CNT_DEVICES] = {false, false, false, false};
USBHIDInput *hiddrivers[] = {&joystick[0], &joystick[1], &joystick[2], &joystick[3]};
#define CNT_HIDDEVICES (sizeof(hiddrivers))
extern "C" uint32_t set_arm_clock(uint32_t frequency);
LiquidCrystalFast lcd(LCD_RS, LCD_RW, LCD_E, LCD_D4, LCD_D5, LCD_D6, LCD_D7);
void setup() {
  Serial.begin(9600);
  if (F_CPU_ACTUAL >= 100'000'000)
    set_arm_clock(100'000'000);
  lcd.begin(20, 4);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print(" Teensy 4.1 Display ");
  lcd.setCursor(0,1);
  myusb.begin();
}
void loop() {
  myusb.Task();
  for (int i=0; i < COUNT_JOYSTICKS; i++) {
    if (joystick[i].available()) {
      Serial.print("Joystick");
      Serial.print(i);
      Serial.print(" Connected with ID: ");
      Serial.println(joystick[i].idVendor(),HEX);
      Serial.print("Product ID:");
      Serial.println(joystick[i].idProduct(),HEX);
    }
  }
}