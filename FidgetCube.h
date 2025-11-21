//
// Created by Administrator on 2025/11/20.
//

#ifndef W8_PROJECT_FIDGETCUBE_H
#define W8_PROJECT_FIDGETCUBE_H
#include <cstdint>


class CubeSide;

class FidgetCube {
public:
    CubeSide *getSide(uint8_t sideNo) const;
    bool addSide(CubeSide *newSide);
protected:
    CubeSide *sides[6];
    uint8_t lastSide = 0;
};


#endif //W8_PROJECT_FIDGETCUBE_H