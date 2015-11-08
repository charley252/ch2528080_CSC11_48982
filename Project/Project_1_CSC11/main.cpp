//Han, Charley - Project 1 - CSC11 - 48982

#include <cstdlib>
#include <iostream>
#include <ctime>
using namespace std;


//function prototype
void levelOne(string [], int &, int &);
void levelTwo(string [], int &, int &);
void levelThree(string [], int &, int &);

int main(int argc, char** argv) 
{
    srand(time(0));
    const int SIZE = 4;
    
    //representing 3 difficulty levels to pull from
    string level1[SIZE] = {"array", "stack", "assembly", "gpio"};
    string level2[SIZE] = {"function", "library", "makefile", "raspberry"};
    string level3[SIZE] = {"raspbian", "processing", "directives", "debugging"};
    
    //loop of menu
    char play; //to hold user response to continue playing
    do
    {
    cout << "Welcome to Hangman!" << endl;
    cout << endl;
    cout << "Here are the rules: words are from the assembly class." << endl;
    cout << "1). There are three levels to choose from." << endl;
    cout << "2). You get 4 letter calls and 2 guesses." << endl;
    cout << "3). More points for quicker guesses." << endl;
    cout << "4). 1st call and correct guess = 5 points." << endl;
    cout << "    2nd call and correct guess = 4 points." << endl;
    cout << "    3rd call and correct guess = 3 points." << endl;
    cout << "    4th call and correct guess = 1 point." << endl;
    cout << endl;
    
    int level = 0;
    cout << "Let's start! Choose your level(1-3): ";
    cin >> level;
    
    //to keep track of array index used
    static int track1 = 0;
    static int track2 = 0;
    static int track3 = 0;

    static int points = 0; //to accumulate user points
    
    switch(level)
    {
        case 1:
            //to loop back to beginning of array
            if(track1>=SIZE)
            {
                track1 = 0;
            }
            levelOne(level1, track1, points);
            track1++; //increment through array
            break;
        case 2:
            //to loop back to beginning of array
            if(track2>=SIZE)
            {
                track2 = 0;
            }
            levelTwo(level2, track2, points);
            track2++;
            break;
        case 3:
            //to loop back to beginning of array
            if(track3>=SIZE)
            {
                track3 = 0;
            }
            levelThree(level3, track3, points);
            track3++;
            break;
        default:
            break;
    }
    
    cout << "Your points so far: " << points << endl;
 
    cout << "Would you like to continue?(y/n): ";
    cin >> play;
    }while(play != 'n');
    

    return 0;
}

/******************Function Definition******************/

void levelOne(string level1[], int &track1, int &points)
{
    
    string one = level1[track1];
   
    //create an array to hold user progress of correct guesses
    char arr[one.size()];
    cout << "********( ";
    for(int i = 0; i<one.size(); i++)
    {
        arr[i] = '_';
        cout << arr[i];
    }
    cout << " )********";
    
    
    char choose; //to hold user response to guess or call letter
    char letter; //to hold user input of letter call
    string answer; //to hold user guess at the whole word
    
    int calls = 0; //to track user attempt at letter call
    int guesses = 0; //to track number of user guesses
    int count = 0; //to track count against array size
    
    //game loop
    do
    {
        cout << endl;
        cout << "Guesses left: " << 2-guesses << " " << "Calls left: " << 4-calls << endl;
        cout << endl;
        cout << "Would you like to guess or pick a letter?(g/l): ";
        cin >> choose;
        if(choose == 'g')
        {
            ++guesses;
            cout << "Take a guess: ";
            cin >> answer;
            
            if(answer == one)
            {
                cout << "Correct!" << endl;
                //decide how many points the player gets
                if(calls<2)
                {
                    points += 5;
                }else if(calls==2)
                {
                    points += 4;
                }else if(calls == 3)
                {
                    points += 3;
                }else if(calls = 4)
                {
                    points += 1;
                }
            
                return;
            }else if(answer != one)
            {
                cout << "Incorrect!" << endl;
            }
        }else if(choose == 'l')
        {
            ++calls;
            cout << "Enter letter: ";
            cin >> letter;
        }
        cout << "********( ";
        
        //loop through array to see if user letter call exists
        for(int i = 0; i<one.size(); i++)
        {
            if(letter == one[i])
            {
                cout << one[i];
                arr[i] = one[i];
                count++;
                
            }else
            {
                cout << arr[i];
            }
        }
        cout << " )********";
        
    }while(count != one.size() && calls < 4 && guesses < 2);
    
    cout << endl;
    cout << "You ran out of guesses and calls. The end." << endl;
    cout << endl;
    
    return;
    
}

void levelTwo(string level2[], int &track2, int &points)
{
    
    string one = level2[track2];
   
    char arr[one.size()];
    cout << "********( ";
    for(int i = 0; i<one.size(); i++)
    {
        arr[i] = '_';
        cout << arr[i];
    }
    cout << " )********";
    
    
    char choose;
    char letter;
    string answer;
    
    int calls = 0;
    int guesses = 0;
    int count = 0;
    do
    {
        cout << endl;
        cout << "Guesses left: " << 2-guesses << " " << "Calls left: " << 4-calls << endl;
        cout << endl;
        cout << "Would you like to guess or pick a letter?(g/l): ";
        cin >> choose;
        if(choose == 'g')
        {
            ++guesses;
            cout << "Take a guess: ";
            cin >> answer;
            
            if(answer == one)
            {
                cout << "Correct!" << endl;
                if(calls<2)
                {
                    points += 5;
                }else if(calls==2)
                {
                    points += 4;
                }else if(calls == 3)
                {
                    points += 3;
                }else if(calls = 4)
                {
                    points += 1;
                }
            
                return;
            }else if(answer != one)
            {
                cout << "Incorrect!" << endl;
            }
        }else if(choose == 'l')
        {
            ++calls;
            cout << "Enter letter: ";
            cin >> letter;
        }
        cout << "********( ";
        
        for(int i = 0; i<one.size(); i++)
        {
            if(letter == one[i])
            {
                cout << one[i];
                arr[i] = one[i];
                count++;
                
            }else
            {
                cout << arr[i];
            }
        }
        cout << " )********";
        
    }while(count != one.size() && calls < 4 && guesses < 2);
    
    cout << endl;
    cout << "You ran out of guesses and calls. The end." << endl;
    cout << endl;
    
    return;
    
}

void levelThree(string level3[], int &track3, int &points)
{
    
    string one = level3[track3];
   
    char arr[one.size()];
    cout << "********( ";
    for(int i = 0; i<one.size(); i++)
    {
        arr[i] = '_';
        cout << arr[i];
    }
    cout << " )********";
    
    
    char choose;
    char letter;
    string answer;
    
    int calls = 0;
    int guesses = 0;
    int count = 0;
    do
    {
        cout << endl;
        cout << "Guesses left: " << 2-guesses << " " << "Calls left: " << 4-calls << endl;
        cout << endl;
        cout << "Would you like to guess or pick a letter?(g/l): ";
        cin >> choose;
        if(choose == 'g')
        {
            ++guesses;
            cout << "Take a guess: ";
            cin >> answer;
            
            if(answer == one)
            {
                cout << "Correct!" << endl;
                if(calls<2)
                {
                    points += 5;
                }else if(calls==2)
                {
                    points += 4;
                }else if(calls == 3)
                {
                    points += 3;
                }else if(calls = 4)
                {
                    points += 1;
                }
            
                return;
            }else if(answer != one)
            {
                cout << "Incorrect!" << endl;
            }
        }else if(choose == 'l')
        {
            ++calls;
            cout << "Enter letter: ";
            cin >> letter;
        }
        cout << "********( ";
        
        for(int i = 0; i<one.size(); i++)
        {
            if(letter == one[i])
            {
                cout << one[i];
                arr[i] = one[i];
                count++;
                
            }else
            {
                cout << arr[i];
            }
        }
        cout << " )********";
        
    }while(count != one.size() && calls < 4 && guesses < 2);
    
    cout << endl;
    cout << "You ran out of guesses and calls. The end." << endl;
    cout << endl;
    
    return;
    
}

