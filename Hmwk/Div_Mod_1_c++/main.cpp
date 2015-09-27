//Han, Charley - Div/Mod #1 - CSC11 - 48982


#include <cstdlib>
#include <iostream>

using namespace std;

//function prototype
void divide(int, int);
void mod(int, int);

void divide_manual(int, int, int&);
void mod_manual(int, int);



int main(int argc, char** argv) 
{
    //get user input
    int x;
    int y;
    
    cout << "Enter dividend: ";
    cin >> x;
    cout << "Enter divisor: ";
    cin >> y;
    cout << endl;
    
    //-----------------using built in arithmetic operators---------------------//

    cout << "Using built in arithmetic operators:" << endl;
    divide(x,y);    
    mod(x,y);
        
    //-----------------manual divide and mod---------------------//
    cout << "Manual Divide and Mod - using subtraction method:" << endl;
    
    int count = 0;  
    divide_manual(x,y,count);
    mod_manual(x,y);
    cout << endl;
    
    
    return 0;
}


//function definitions:
void divide(int a, int b)
{
    int x;
    x = a/b;
    
    cout << a << " divided by " << b << " = " << x << endl;
}

void mod(int a, int b)
{
    int x;
    x = a%b;
    
    cout << a << " mod by " << b << " = " << x << endl;
}


void divide_manual(int a, int b, int &count)
{
    int x = a;
    int y = b;
    
    while(a-b >= 0)
    {
        a -= b;
        count++;   
    }
    cout << x << " divided by " << y << " = " << count << endl;
}

void mod_manual(int a, int b)
{
    int x = a;
    int y = b;
    
    while(a >= b)
    {
        a -= b;
    }  
    cout << x << " mod by " << y << " = " << a << endl;
}