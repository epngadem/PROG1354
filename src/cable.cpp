#include "Cable.h"
#include <Arduino.h>

Cable::Cable() {
    // Définir les broches d'entrée et de sortie
    int inputPins[8] = {15, 2, 4, 5, 18, 19, 21, 22};
    int outputPins[8] = {13, 14, 27, 26, 25, 33, 32, 12};

    // Copier les broches d'entrée et de sortie dans les tableaux de la classe
    for (int i = 0; i < 8; i++) {
        pinsInput[i] = inputPins[i];
        pinsOutput[i] = outputPins[i];
    }
}

void Cable::begin() {
    Serial.begin(9600);
    // Initialiser les broches
    for (int i = 0; i < 8; i++) {
        pinMode(pinsInput[i], INPUT);
        pinMode(pinsOutput[i], OUTPUT);
    }
}