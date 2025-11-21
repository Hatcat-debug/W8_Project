//
// Created by Administrator on 2025/11/20.
//

#include "FidgetCube.h"

bool FidgetCube::addSide(CubeSide *newSide) {
    if (lastSide < 6) {
        sides[lastSide] = newSide;
        lastSide++;
        return true;
    }
    return false;
}

CubeSide *FidgetCube::getSide(uint8_t sideNo) const {
    return sides[sideNo];
}