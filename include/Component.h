#pragma once
#include "ECS.h"

class PositionComponent : public Component{
private:
    int xPos = 0;
    int yPos = 0;

public:
    int getX() const {
        return xPos;
    }

    void setX(int xPos) {
        PositionComponent::xPos = xPos;
    }

    int getY() const {
        return yPos;
    }

    void setY(int yPos) {
        PositionComponent::yPos = yPos;
    }

    void update() override{
        xPos++;
        yPos++;
    }
};