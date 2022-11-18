#include "../include/credits.h"

Credits::Credits(/* args */){


}

Credits::~Credits(){


}

void Credits::enter(){

    cout<<"Entered Credits State"<<endl;
    cout<<endl;

}

void Credits::update(){

     while (true)
    {
        cout<<"Brad"<<endl;
        cout<<"Josh"<<endl;
        cout<<"Ricardo"<<endl;
        cout<<"Rishabh"<<endl;

        cout<<endl;
        cout<<endl;

        cout<<"********************"<<endl;
        cout<<"********************"<<endl;

        cout<<endl;
        cout<<endl;

        cout<<"1. Main Menu"<<endl;
        cout<<"2. Quit"<<endl;

        int num;
        cin >> num;

        switch (num)
        {
        case 1:
            leave();
            currState = mainMenu;
            break;
        case 2:
            leave();
            exit(0); 
        }
    }


}

void Credits::leave(){

    cout<<"Leaving Credits State"<<endl;
    cout<<endl;

}