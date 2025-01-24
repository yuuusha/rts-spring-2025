int N = 5;
int leds[] = {3, 5, 6, 9, 10};
double intervals[] = {10, 1, 0.5, 0.1, 0.05};
int prev[] = {0, 0, 0, 0, 0};
int states[] = {0, 0, 0, 0, 0};

void setup() {
  for (int i = 0; i < N; i++) {
    pinMode(leds[i], OUTPUT);
  }
}

void loop() {
  for (int i = 0; i < N; i++) {
      unsigned long currentMillis = millis();

    if (currentMillis - prev[i] >= intervals[i]) {
      prev[i] = currentMillis;

      if (states[i] == 0) {
        states[i] = 1;
      } else {
        states[i] = 0;
      }

      digitalWrite(leds[i], states[i]);
    }
  }
}
