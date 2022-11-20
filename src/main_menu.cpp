#include "../include/main_menu.h"

MainMenu::MainMenu(/* args */){


}

MainMenu::~MainMenu(){


}

void MainMenu::enter(){

    cout<<"Entered Main Menu State"<<endl;
    cout<<endl;

}

void MainMenu::update(){

    while (true)
    {
        cout<<"1. play"<<endl;
        cout<<"2. credits"<<endl;
        cout<<"3. help"<<endl;
        cout<<"4. quit"<<endl;

        int num;
        cin >> num;

        switch (num)
        {
        case 1:
            leave();
            currState = playing;
            break;
        case 2:
            leave();
            currState = credits;
            break;
        case 3:
            leave();
            currState = help;
            break;
        case 4:
            leave();
            exit(0);
            break;           
        }
    }
    

}

void MainMenu::leave(){

    cout<<"Leaving Main Menu State"<<endl;
    cout<<endl;

}
