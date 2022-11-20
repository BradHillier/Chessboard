#include "../include/help.h"

Help::Help(/* args */){


}

Help::~Help(){


}

void Help::enter(){

    cout<<"Entered Help State"<<endl;
    cout<<endl;

}

void Help::update(){

     while (true)
    {
        cout<<"############################"<<endl;
        cout<<"######SOME HELP TEXT########"<<endl;
        cout<<"############################"<<endl;

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

void Help::leave(){

    cout<<"Leaving Help State"<<endl;
    cout<<endl;

}