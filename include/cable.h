#ifndef CABLE_H
#define CABLE_H

class Cable {
private:
    int pinsInput[8];
    int pinsOutput[8];

public:
    Cable();
    void begin();
    void testCable();
};

#endif