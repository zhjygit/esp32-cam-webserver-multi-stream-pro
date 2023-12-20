# esp32-cam-webserver-multi-stream-pro
## Taken from the ESP examples, and expanded
This sketch is a extension/expansion/rework of the 'official' ESP32 Camera example sketch from Espressif:

https://github.com/easytarget/esp32-cam-webserver

The test board is timer-camera-F form m5stack, as to CAMERA_MODEL_M5STACK_PSRAM in camera_pins.h

But expanded with:
* support working without usb plugged or supplied
	added battery.h(#include "battery.h") and battery.c,with bat_init() and bat_hold_output();also you can print voltage via vol=bat_get_voltage();
* support hidden ssid scan and connect
* delete persist connect in loop()
* support led on/off for CAMERA_MODEL_M5STACK_PSRAM
