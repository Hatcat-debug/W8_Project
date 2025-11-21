#include <iostream>
#include <cstdlib>
 
using std::string;
using std::cout;
using std::endl;
 
#include "CubeSide.h"
#include "FidgetCube.h"
 
class  JoystickSide : public CubeSide {
public:
    const char *getName();
    void push(uint16_t value);
protected:
    static constexpr char const *joystickSideName = "Joystick";
};
 
const char * JoystickSide::getName() {
    return JoystickSide::joystickSideName;
}
 
void JoystickSide::push(uint16_t value) {
    cout << "JoystickSide pushed into direction " << value << "." << endl;
}
 
class JoystickCube : public FidgetCube {
public:
    JoystickCube();
};
 
JoystickCube::JoystickCube() : FidgetCube() {
    for (uint8_t x = 0; x<6; x++ ){
        addSide(new JoystickSide());
    }
}
 
 
int main() {
    JoystickCube theJoystickCube;
    cout << theJoystickCube.getSide(0)->getName();
    ((JoystickSide*)theJoystickCube.getSide(0))->push(3);
}
