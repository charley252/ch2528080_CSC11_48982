//Han, Charley - CSC11 - Div/Mod Shift

#include <cstdlib>
#include <iostream>
#include <bitset>
using namespace std;



int main(int argc, char** argv)
{
    int R1 = 45; //dividend
    int R2 = 6; //divisor
    int R4 = 6; //original divisor for use
    
    int R5 = 0; //keep track of subtraction
    int R3 = 0; //keep track of bit shift and arithmetics
    
    //shift divisor to the left
    do
    {
        R3++;
        R2 <<= 1;
    
    }while(R2 < R1);
    
    if(R2>R1)
    {
        R2 >>= 1;
    }
    cout << R2 << endl;
    
    //subtract result from dividend
    do
    {
        R3++;
        R5 = R1-R2;
        
    }while(R5<=R2);
    
    
    //shift initial subtraction result back to original divisor
    do
    {
        R3++;
        R5 >>= 1;
    }while(R5<R4);
    
        
    cout << "Quotient  = " << R3 << endl;
    
    
    

    return 0;
}

