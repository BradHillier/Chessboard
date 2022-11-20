#include "../include/playing.h"

Playing::Playing(/* args */){


}

Playing::~Playing(){


}

void Playing::enter(){

    cout<<"Entered Playing State"<<endl;
    cout<<endl;

}

void Playing::update(){

     while (true)
    {
        cout<<"############################"<<endl;
        cout<<"PLAYING STATE"<<endl;
        cout<<"GAME PLAYED HERE"<<endl;
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

void Playing::leave(){

    cout<<"Leaving Playing State"<<endl;
    cout<<endl;

}