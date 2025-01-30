struct Pin {
  volatile uint8_t* port_type;
  uint8_t offset;
};

int N = 5;

Pin leds[] = {
  { &PORTD, (1 << PD3) },
  { &PORTD, (1 << PD5) },
  { &PORTD, (1 << PD6) },
  { &PORTB, (1 << PD1) },
  { &PORTB, (1 << PD2) },
};

double intervals[] = {10000, 1000, 500, 100, 50};
int prev[] = {0, 0, 0, 0, 0};
int states[] = {0, 0, 0, 0, 0};

void setup() {
  for (int i = 0; i < N; i++) {
    volatile uint8_t* ddr = (volatile uint8_t*)(leds[i].port_type - 1);
    *ddr |= leds[i].offset;
  }
}

void loop() {
  for (int i = 0; i < N; i++) {
      unsigned long currentMicros = micros();

    if (currentMicros - prev[i] >= intervals[i]) {


      if (states[i]) {
        *leds[i].port_type &= ~leds[i].offset;
      } else {
        *leds[i].port_type |= leds[i].offset;
      }

      states[i] ^= 1;
      prev[i] = currentMicros;
    }
  }
}
