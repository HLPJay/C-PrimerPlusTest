/*************************************
Persion 

*************************************/

#include <iostream>
#include <cstring>
#include "ex14_04_Persion.h"

const int SIZE = 10;

int main()
{
	using namespace std;
    int ct, i;
    Persion * gang[SIZE];

    for(ct = 0; ct < SIZE; ct++)
    {
        char choice;
        cout << "Enter the gang category: \n"
             << "o: ordinary person  g: gunslinger  "
             << "p: pokerplayer  b: bad dude  q: quit \n";
        cin >> choice;
        while(strchr("ogpbq", choice) == NULL)
        {
            cout << "Please enter an o, g, p, b, or q: ";
            cin >> choice;
        }

        if (choice == 'q')
            break;

        switch(choice)
        {
            case 'o': gang[ct] = new Persion("Han","DaPeng");
                      break;
            case 'g': gang[ct] = new Cunslinger("Han","DaPeng",7,8);
                      break;
            case 'p': gang[ct] = new PokerPlayer;
                      break;
            case 'b': gang[ct] = new BadDude;
                      break;
        }

        cin.get();
    }

    cout << "\nHere is your gang: \n";
    for (i = 0; i < ct; i++)
    {
        cout << endl;
        gang[i]->Show();
    }
    for (i = 0; i < ct; i++)
        delete gang[i];
    cout << "Bye" << endl;

    return 0;
}