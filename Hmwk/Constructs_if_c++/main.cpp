//Han, Charley - CSC11 - 48982 - if branching

#include <cstdlib>
#include <iostream>

using namespace std;

/* Assembly = CSC11, Intro Programming = CSC5, Intro Concepts = CIS1a
 
 * Given the input, M,T,W,Thur,Fri - 1, 2, 3, 4, 5.
 * 
   Output 11 for M, W
   Output  5 for T, Thur
   Output  1 for Fri
   Output  0 for any other number */

int main(int argc, char** argv) 
{
    int day, day1, day2; //for three different branches
    
    cout << "What day of the week would you like to check?(1-5): ";
    cin >> day;
    cout << endl;
    //----------------------------if branch--------------------------------//
    cout << "If branch: " << endl;
    
    if(day == 1 || day == 3)
    {
        if(day == 1)
        {
            cout << "You have CSC11 on Monday." << endl;
        }
        if(day == 3)
        {
            cout << "You have CSC11 on Wednesday." << endl;
        }
    }
    if(day == 2 || day == 4)
    {
        if(day == 2)
        {
            cout << "You have CSC5 on Tuesday." << endl;
        }
        if(day == 4)
        {
            cout << "You have CSC5 on Thursday." << endl;
        }
    }
    if(day == 5)
    {
        cout << "You have CSC1a on Friday." << endl;
    }
    if(day > 5 || day < 1)
    {
        cout << "You have no class during that day." << endl;
    }
    cout << endl;
    //----------------------------if/else branch--------------------------------//
    cout << "If/else branch: " << endl;
    
    if(day ==1 || day == 3)
        cout << "11." << endl;
    else if(day == 2 || day ==4)
        cout << "5." << endl;
    else if(day == 5)
        cout << "1." << endl;
    else
        cout << "0." << endl;
    cout << endl;
    
    //----------------------------switch branch--------------------------------//
    cout << "Switch branch: " << endl;
    
    switch(day)
    {
        case 1:
        case 3:
            cout << "11." << endl;
            break;
        case 2:
        case 4:
            cout << "5." << endl;
            break;
        case 5:
            cout << "1." << endl;
            break;
        default:
            cout << "0." << endl;
            
    }
    
    return 0;
}

