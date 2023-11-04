//// Power OFF
//
void _grausOff(uint8_t graus){
  // Arduino => c++
  switch (graus) {
    case 16: {
      // 16 Graus - 0FF
      uint8_t state[8] = {0x00, 0x00, 0x20, 0x50, 0x00, 0x03, 0x00, 0xA0};
      irsend.sendGree(state);
      Serial.println("Air off in 16 Celsius");
      delay(500);
      break;
    }
    case 17: {
      // 17 Graus - 0FF
      uint8_t state[8] = {0x00, 0x01, 0x20, 0x50, 0x00, 0x03, 0x00, 0xB0};
      irsend.sendGree(state);
      Serial.println("Air off in 17 Celsius");
      delay(500);
      break;
    }
    case 18: {
      // 18 Graus - 0FF
      uint8_t state[8] = {0x00, 0x02, 0x20, 0x50, 0x00, 0x03, 0x00, 0xC0};
      irsend.sendGree(state);
      Serial.println("Air off in 18 Celsius");
      delay(500);
      break;
    }
    case 19: {
      // 19 Graus - 0FF
      uint8_t state[8] = {0x00, 0x03, 0x20, 0x50, 0x00, 0x03, 0x00, 0xD0};
      irsend.sendGree(state);
      Serial.println("Air off in 19 Celsius");
      delay(500);
      break;
    }
    case 20: {
      // 20 Graus - 0FF
      uint8_t state[8] = {0x00, 0x04, 0x20, 0x50, 0x00, 0x03, 0x00, 0xE0};
      irsend.sendGree(state);
      Serial.println("Air off in 20 Celsius");
      delay(500);
      break;
    }
    case 21: {
      // 21 Graus - 0FF
      uint8_t state[8] = {0x00, 0x05, 0x20, 0x50, 0x00, 0x03, 0x00, 0xF0};
      irsend.sendGree(state);
      Serial.println("Air off in 21 Celsius");
      delay(500);
      break;
    }
    case 22: {
      // 22 Graus - 0FF
      uint8_t state[8] = {0x00, 0x06, 0x20, 0x50, 0x00, 0x03, 0x00, 0x00};
      irsend.sendGree(state);
      Serial.println("Air off in 22 Celsius");
      delay(500);
      break;
    }
    case 23: {
      // 23 Graus - 0FF
      uint8_t state[8] = {0x00, 0x07, 0x20, 0x50, 0x00, 0x03, 0x00, 0x10};
      irsend.sendGree(state);
      Serial.println("Air off in 23 Celsius");
      delay(500);
      break;
    }
    case 24: {
      // 24 Graus - 0FF
      uint8_t state[8] = {0x00, 0x08, 0x20, 0x50, 0x00, 0x03, 0x00, 0x20};
      irsend.sendGree(state, 8,3);
      Serial.println("Air off in 24 Celsius");
      delay(500);
      break;
    }
    case 25: {
      // 25 Graus - 0FF
      uint8_t state[8] = {0x00, 0x09, 0x20, 0x50, 0x00, 0x03, 0x00, 0x30};
      irsend.sendGree(state);
      Serial.println("Air off in 25 Celsius");
      delay(500);
      break;
    }
    case 26: {
      // 26 Graus - 0FF
      uint8_t state[8] = {0x00, 0x0A, 0x20, 0x50, 0x00, 0x03, 0x00, 0x40};
      irsend.sendGree(state);
      Serial.println("Air off in 26 Celsius");
      delay(500);
      break;
    }
    case 27: {
      // 27 Graus - 0FF
      uint8_t state[8] = {0x00, 0x0B, 0x20, 0x50, 0x00, 0x03, 0x00, 0x50};
      irsend.sendGree(state);
      Serial.println("Air off in 27 Celsius");
      delay(500);
      break;
    }
    case 28: {
      // 28 Graus - 0FF
      uint8_t state[8] = {0x00, 0x0C, 0x20, 0x50, 0x00, 0x03, 0x00, 0x60};
      irsend.sendGree(state);
      Serial.println("Air off in 28 Celsius");
      delay(500);
      break;
    }
    case 29: {
      // 29 Graus - 0FF
      uint8_t state[8] = {0x00, 0x0D, 0x20, 0x50, 0x00, 0x03, 0x00, 0x70};
      irsend.sendGree(state);
      Serial.println("Air off in 29 Celsius");
      delay(500);
      break;
    }
    case 30: {
      // 30 Graus - 0FF
      uint8_t state[8] = {0x00, 0x0E, 0x20, 0x50, 0x00, 0x03, 0x00, 0x80};
      irsend.sendGree(state);
      Serial.println("Air off in 30 Celsius");
      delay(500);
      break;
    }
  }
}
//
//// Power ON
//

void _grausOn(uint8_t graus){
  // Arduino => c++
  switch (graus) {
    case 16: {
      // 16 Graus - 0N
      uint8_t state[8] = {0x08, 0x00, 0x60, 0x50, 0x00, 0x01, 0x00, 0x20};
      irsend.sendGree(state);
      Serial.println("Air on in 16 Celsius");
      delay(500);
      break;
    }
    case 17: {
      // 17 Graus - 0N
      uint8_t state[8] = {0x08, 0x01, 0x60, 0x50, 0x00, 0x01, 0x00, 0x30};
      irsend.sendGree(state);
      Serial.println("Air on in 17 Celsius");
      delay(500);
      break;
    }
    case 18: {
      // 18 Graus - 0N
      uint8_t state[8] = {0x08, 0x02, 0x60, 0x50, 0x00, 0x01, 0x00, 0x40};
      irsend.sendGree(state);
      Serial.println("Air on in 18 Celsius");
      delay(500);
      break;
    }
    case 19: {
      // 19 Graus - 0N
      uint8_t state[8] = {0x08, 0x03, 0x60, 0x50, 0x00, 0x01, 0x00, 0x50};
      irsend.sendGree(state);
      Serial.println("Air on in 19 Celsius");
      delay(500);
      break;
    }
    case 20: {
      // 20 Graus - 0N
      uint8_t state[8] = {0x08, 0x04, 0x60, 0x50, 0x00, 0x01, 0x00, 0x60};
      irsend.sendGree(state);
      Serial.println("Air on in 20 Celsius");
      delay(500);
      break;
    }
    case 21: {
      // 21 Graus - 0N
      uint8_t state[8] = {0x08, 0x05, 0x60, 0x50, 0x00, 0x01, 0x00, 0x70};
      irsend.sendGree(state);
      Serial.println("Air on in 21 Celsius");
      delay(500);
      break;
    }
    case 22: {
      // 22 Graus - 0N
      uint8_t state[8] = {0x08, 0x06, 0x60, 0x50, 0x00, 0x01, 0x00, 0x80};
      irsend.sendGree(state);
      Serial.println("Air on in 22 Celsius");
      delay(500);
      break;
    }
    case 23: {
      // 23 Graus - 0N
      uint8_t state[8] = {0x08, 0x07, 0x60, 0x50, 0x00, 0x01, 0x00, 0x90};
      irsend.sendGree(state);
      Serial.println("Air on in 23 Celsius");
      delay(500);
      break;
    }
    case 24: {
      // 24 Graus - 0N
      uint8_t state[8] = {0x08, 0x08, 0x60, 0x50, 0x00, 0x01, 0x00, 0xA0};
      irsend.sendGree(state, 8,3);
      Serial.println("Air on in 24 Celsius");
      delay(500);
      break;
    }
    case 25: {
      // 25 Graus - 0N
      uint8_t state[8] = {0x08, 0x09, 0x60, 0x50, 0x00, 0x01, 0x00, 0xB0};
      irsend.sendGree(state);
      Serial.println("Air on in 25 Celsius");
      delay(500);
      break;
    }
    case 26: {
      // 26 Graus - 0N
      uint8_t state[8] = {0x08, 0x0A, 0x60, 0x50, 0x00, 0x01, 0x00, 0xC0};
      irsend.sendGree(state);
      Serial.println("Air on in 26 Celsius");
      delay(500);
      break;
    }
    case 27: {
      // 27 Graus - 0N
      uint8_t state[8] = {0x08, 0x0B, 0x60, 0x50, 0x00, 0x01, 0x00, 0xD0};
      irsend.sendGree(state);
      Serial.println("Air on in 27 Celsius");
      delay(500);
      break;
    }
    case 28: {
      // 28 Graus - ON
      uint8_t state[8] = {0x08, 0x0C, 0x60, 0x50, 0x00, 0x01, 0x00, 0xE0};
      irsend.sendGree(state);
      Serial.println("Air on in 28 Celsius");
      delay(500);
      break;
    }
    case 29: {
      // 29 Graus - ON
      uint8_t state[8] = {0x08, 0x0D, 0x60, 0x50, 0x00, 0x01, 0x00, 0xF0};
      irsend.sendGree(state);
      Serial.println("Air on in 29 Celsius");
      delay(500);
      break;
    }
    case 30: {
      // 30 Graus - ON
      uint8_t state[8] = {0x08, 0x0E, 0x60, 0x50, 0x00, 0x01, 0x00, 0x00};
      irsend.sendGree(state);
      Serial.println("Air on in 30 Celsius");
      delay(500);
      break;
    }
  }
}
