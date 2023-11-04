/* IRremoteESP8266: IRsendDemo - demonstrates sending IR codes with IRsend.
 *
 * Version 1.1 January, 2019
 * Based on Ken Shirriff's IrsendDemo Version 0.1 July, 2009,
 * Copyright 2009 Ken Shirriff, http://arcfn.com
 *
 * An IR LED circuit *MUST* be connected to the ESP8266 on a pin
 * as specified by kIrLed below.
 *
 * TL;DR: The IR LED needs to be driven by a transistor for a good result.
 *
 * Suggested circuit:
 *     https://github.com/crankyoldgit/IRremoteESP8266/wiki#ir-sending
 *
 * Common mistakes & tips:
 *   * Don't just connect the IR LED directly to the pin, it won't
 *     have enough current to drive the IR LED effectively.
 *   * Make sure you have the IR LED polarity correct.
 *     See: https://learn.sparkfun.com/tutorials/polarity/diode-and-led-polarity
 *   * Typical digital camera/phones can be used to see if the IR LED is flashed.
 *     Replace the IR LED with a normal LED if you don't have a digital camera
 *     when debugging.
 *   * Avoid using the following pins unless you really know what you are doing:
 *     * Pin 0/D3: Can interfere with the boot/program mode & support circuits.
 *     * Pin 1/TX/TXD0: Any serial transmissions from the ESP8266 will interfere.
 *     * Pin 3/RX/RXD0: Any serial transmissions to the ESP8266 will interfere.
 *   * ESP-01 modules are tricky. We suggest you use a module with more GPIOs
 *     for your first time. e.g. ESP-12 etc.
 */

#include <Arduino.h>
#include <IRremoteESP8266.h>
#include <IRsend.h>

const uint16_t kIrLed = 4;  // ESP8266 GPIO pin to use. Recommended: 4 (D2).

IRsend irsend(kIrLed);  // Set the GPIO to be used to sending the message.

// Example of data captured by IRrecvDumpV2.ino
uint16_t rawData[139] = {9052, 4454,  664, 570,  636, 568,  636, 568,  
                         636, 1672,  636, 568,  638, 568,  636, 568,  
                         636, 570,  636, 568,  662, 544,  638, 568,  
                         638, 1668,  636, 568,  638, 568,  636, 568,  
                         662, 544,  638, 568,  660, 546,  662, 544,  662, 544,  
                         638, 544,  686, 1646,  662, 1644,  662, 516,  688, 518,  
                         688, 516,  688, 518,  688, 518,  686, 1620,  686, 518,  
                         686, 1622,  686, 518,  686, 518,  686, 1624,  686, 518,  
                         688, 19954,  686, 518,  662, 542,  688, 518,  664, 542,  
                         688, 520,  686, 520,  686, 518,  660, 546,  660, 1646,  
                         662, 544,  660, 546,  660, 546,  658, 546,  660, 546,  
                         658, 546,  658, 548,  658, 548,  658, 548,  656, 548,  
                         656, 550,  654, 550,  656, 550,  654, 572,  632, 572,  
                         634, 572,  632, 574,  632, 572,  632, 574,  632, 574,  
                         630, 1676,  630, 574,  630, 1678,  628};  // GREE
// Example Samsung A/C state captured from IRrecvDumpV2.ino
uint8_t state[8] = {0x08, 0x08, 0x60, 0x50, 
                    0x00, 0x01, 0x00, 0xA0};

void setup() {
  irsend.begin();
#if ESP8266
  Serial.begin(115200, SERIAL_8N1, SERIAL_TX_ONLY);
#else  // ESP8266
  Serial.begin(115200, SERIAL_8N1);
#endif  // ESP8266
}

void loop() {
  Serial.println("NEC");
  irsend.sendNEC(0x00FFE01FUL);
  delay(2000);
  Serial.println("Sony");
  irsend.sendSony(0xa90, 12, 2);  // 12 bits & 2 repeats
  delay(2000);
  Serial.println("a rawData capture from IRrecvDumpV2");
  irsend.sendRaw(rawData, 67, 38);  // Send a raw data capture at 38kHz.
  delay(2000);
  Serial.println("a Samsung A/C state from IRrecvDumpV2");
  irsend.sendSamsungAC(state);
  delay(2000);
}
