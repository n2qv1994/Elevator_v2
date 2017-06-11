#include "controller.h"
#include <iostream>

Controller::Controller()
{

}

Controller::~Controller()
{

}

Controller *Controller::getInstance()
{
    if(_singleton == NULL){
        _singleton = new Controller;
        elevator1 = new Elevator("Elevator1");
        elevator2 = new Elevator("Elevator2");
    }
    return _singleton;
}

void Controller::run()
{
    for(std::list<Passenger*>::iterator it = Passenger::getList()->begin();it != Passenger::getList()->end(); it++) {
        StatePassenger state = (*it)->getState();
        switch(state)
        {
            case INIT:
                if((*it)->getDepartFloor() % 2 == 0)
                {
                    elevator2->addPassenger(*it);
                    (*it)->setElevator(elevator2);
                    (*it)->setState(WAIT);
                }
                else
                {
                    elevator1->addPassenger(*it);
                    (*it)->setElevator(elevator1);
                    (*it)->setState(WAIT);
                }
                break;
            case GO:
                break;
            case DONE:
                break;
            case WAIT:
                break;
        }

    }
}

Controller *Controller::_singleton = NULL;
Elevator *Controller::elevator1 = NULL;
Elevator *Controller::elevator2 = NULL;
