#ifndef STATE_H
#define STATE_H

#include <iostream>
using namespace std;

class State
{
private:
    /* data */
public:
    State(/* args */) {}

    virtual ~State() {}

    
    virtual void enter() = 0; //initialize
    virtual void update() = 0; // whatever happens in the state and state transitions
    virtual void leave() = 0; //leave state, free memory

    static State* currState;

    static State* mainMenu;
    static State* help;
    static State* credits;
    static State* playing;

};


#endif


/* main.cpp used for testing state machine to be demoed on 19/11

#include "main_menu.h"
#include "help.h"
#include "playing.h"
#include "credits.h"

#include <iostream>

using namespace std;

State * State::mainMenu = new MainMenu();
State * State::help = new Help();
State * State::credits = new Credits();
State * State::playing = new Playing();

State * State::currState = State::mainMenu;

int main(){

    while(true){

        State::currState->enter();
        State::currState->update();


    }

    return 0;
}

*/
