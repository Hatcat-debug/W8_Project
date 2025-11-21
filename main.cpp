#include <cstdint>
#include <iostream>
#include <cstdlib>
#include <unistd.h>

#include "CubeSide.h"
#include "FidgetCube.h"

using std::string;
using std::cout;
using std::endl;

class DialSide : public CubeSide {
public:
    const char *getName();
    void setDial(uint16_t value);
protected:
    uint16_t dialValue = 0;
    static constexpr char const *dialSideName = "Dial";
};

const char *DialSide::getName() {
    return DialSide::dialSideName;
}

void DialSide::setDial(uint16_t value) {
    if (dialValue <= 10) {
        dialValue = value;
        cout << "A dial was set to " << dialValue << "." << endl;
    }
}

class DialCube : public FidgetCube {
public:
    DialCube();
};

DialCube::DialCube() : FidgetCube() {
    for (uint8_t x = 0; x<6; x++ ){
        addSide(new DialSide());
    }
}


int main() {
    DialCube theDialCube;
    cout << theDialCube.getSide(0)->getName();
    ((DialSide*)theDialCube.getSide(0))->setDial(5);

    sleep(10);
}
