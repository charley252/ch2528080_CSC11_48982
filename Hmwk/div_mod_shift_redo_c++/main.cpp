//Han, Charley - CIS17C - 48982 - division by bit shift redo

#include <cstdlib>
#include <iostream>


using namespace std;

int main(int argc, char** argv) 
{
    unsigned int numerator; //for reference and comparison
    unsigned int denominator; //for reference and comparison
    unsigned int tempdenominator; //to alter as we go
    
    unsigned int quotient = 0;
    
    //user input
    cout << "Enter dividend: ";
    cin >> numerator;
    
    cout << "Enter divisor: ";
    cin >> denominator;
    cout << endl;
    
    while(denominator == 0)
    {
        cout << "Can't divide by 0, please enter again: ";
        cin >> denominator;
    }
    
    //-----------------------shift left------------------------------------//
    
    
    //assignment to setup calculations and alterations to temp
    tempdenominator = denominator;
    
    //shift counters - not the count of number of shifts itself, but the binary multiple or value thereof.
    int leftshift = 1;
    int rightshift = 0;
    
    //left shift denominator and 'leftshift' counter
    do
    {
        tempdenominator <<= 1;
        leftshift <<= 1;
    }while(numerator > tempdenominator);
    
    //shift back one(to the right) to get value less than denominator
    tempdenominator >>= 1;
    leftshift >>= 1;
    
    
    //make rightshift starting point the same as leftshift - to 'count' shift back
    rightshift = leftshift;
        
    
    //-------------------------calculation execution-------------------------//
    
    int x = 0;
    //shift back while temp-denominator equals original denominator, in other words going back to the beginning
    while(numerator >= tempdenominator) //both numerator and tempdenominator is decreasing and only when 
                                        //numerator>=tempdenominator,
                                        //the x is incremented or added to the previous value.
    {
        x += rightshift;
        numerator -= tempdenominator; //numerator gets decremented here

        while(tempdenominator != denominator)
        {
            tempdenominator >>= 1; //tempdenominator gets decremented here
            rightshift >>= 1; //this is the 'shift-back'!!
        } 
    }
        
    
    //-----------------------output----------------------------------------//
    
    cout << "ANSWER: " << endl;
    cout << "Quotient = " << x << endl;
    cout << "Remainder = " << numerator << endl;
    
    cout << endl;
    
  
    return 0;
}


