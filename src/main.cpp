#include <Arduino.h>
#include "Cable.h"

Cable cable;

void setup() {
    cable.begin();
}

void loop() {
    cable.testCable();
    delay(5000); // Attendre 5 secondes entre chaque test
}