#pragma once

#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>
#include <bitset>
#include <array>



class Component;
class Entity;


using ComponentID = std::size_t;

inline ComponentID  getComponentTypeID(){
    static ComponentID lastID = 0;
    return lastID++;
}

template <typename  T> inline ComponentID getComponentTypeID() noexcept{
    static ComponentID typeID = getComponentTypeID();
    return typeID;
}

constexpr std::size_t maxComponents = 32;

using ComponentBitSet = std::bitset<maxComponents>;
using ComponentArray = std::array<Component*,maxComponents>;

class Component{
public:
    Entity* owner;

    virtual void init(){}
    virtual void update(){}
    virtual void draw(){}

    virtual ~Component(){}
};

class Entity{
private:
    bool active = true;
    std::vector<std::unique_ptr<Component>> components;

    ComponentArray componentArray;
    ComponentBitSet componentBitSet;
public:
    void update(){
        for (const auto &item: components){
            item->update();
        }
        for (const auto &item: components){
            item->draw();
        }
    }
    void draw(){}
    bool isActive() const {return active;}
    void destroy() {active = false;}

    template<typename T > bool hasComponent() const{
        return componentBitSet[getComponentTypeID<T>()];
    }

    template<typename T,typename... TArgs> T& addComponent(TArgs&&... mArgs){
        T* c(new T(std::forward<TArgs>(mArgs)...));
        c->owner = this;
        std::unique_ptr<Component> uniquePtr{c};
        components.emplace_back(std::move(uniquePtr));

        componentArray[getComponentTypeID<T>()] = c;
        componentBitSet[getComponentTypeID<T>()] = true;

        c->init();
        return *c;
    }

    template<typename T> T& getComponent() const{
        auto ptr(componentArray[getComponentTypeID<T>()]);
        return *static_cast<T*>(ptr);
    }
};

class Manager{
private:
    std::vector<std::unique_ptr<Entity>> entities;
public:
    void update(){
        for (const auto &item: entities){
            item->update();
        }
    }
    void draw(){
        for (const auto &item: entities){
            item->draw();
        }
    }

    void refresh(){
        entities.erase(std::remove_if(std::begin(entities),std::end(entities),[](const std::unique_ptr<Entity> &entity){
            return !entity->isActive();
        }),
        std::end(entities));
    }

    Entity& addEntity(){
        Entity* entity = new Entity();
        std::unique_ptr<Entity> uniquePtr{entity};
        entities.emplace_back(std::move(uniquePtr));
        return *entity;
    }

};

