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

void Cable::testCable() {
    bool straight = true;
    bool crossed = true;

    // Tester chaque paire de broches
    for (int i = 0; i < 8; i++) {
        digitalWrite(pinsOutput[i], HIGH);
        delay(10);
        if (digitalRead(pinsInput[i]) != HIGH) {
            straight = false;
        }
        digitalWrite(pinsOutput[i], LOW);
        delay(10);
        if (digitalRead(pinsInput[i]) != LOW) {
            crossed = false;
        }
    }

    // Afficher le résultat du test
    if (straight) {
        Serial.println("Le câble est droit.");
    } else if (crossed) {
        Serial.println("Le câble est croisé.");
    } else {
        Serial.println("Le câble est défectueux, DOMMAGE");
    }
}