#include <SmartSensorFilter.h>

SmartSensorFilter filter(10);

void setup() {
  Serial.begin(9600);
  filter.begin();
}

void loop() {

  int rawData = random(50, 80);

  int cleanData = filter.update(rawData);

  Serial.print("Raw:");
  Serial.print(rawData);
  Serial.print(",");
  Serial.print("Filtered:");
  Serial.println(cleanData);

  delay(100);
}
