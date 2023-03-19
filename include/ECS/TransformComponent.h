#pragma once
#include "Component.h"
class TransformComponent : public Component{
private:
    int xPos = 0;
    int yPos = 0;

public:
    TransformComponent(){
        xPos = 0;
        yPos = 0;
    }
    TransformComponent(int x,int y){
        xPos = x;
        yPos = y;
    }
    int x() const {
        return xPos;
    }

    void setX(int x) {
        xPos = x;
    }

    int y() const {
        return yPos;
    }

    void setY(int y) {
        TransformComponent::yPos = y;
    }

    void update() override{
        yPos++;
        xPos++;
    }
};