#ifndef PASSENGER_H
#define PASSENGER_H

#include <iostream>
#include <list>
#include "elevator.h"
#include "simulator.h"

enum StatePassenger {INIT = 0, GO, WAIT, DONE};

class Elevator;

class Passenger
{
private:
    int depart_floor;
    int dest_floor;
    int weight;
    int id;
    static std::list<Passenger*> *listPassenger;
    Elevator *elevator;
    StatePassenger state;
public:
    Passenger(int depart_floor, int dest_floor, int weight);
    ~Passenger();

    int getDepartFloor();
    int getDestFloor();
    int getWeight();
    StatePassenger getState();
    void setElevator(Elevator* elevator);
    Elevator *getElevator();
    StatePassenger getStatePassenger();
    void setState(StatePassenger state);
    static std::list<Passenger*> *getList();
    bool goingUp();
};

#endif // PASSENGER_H
