//Han, Charley - CSC11 - 48982 - summation using loops

#include <cstdlib>
#include <iostream>

using namespace std;


int main(int argc, char** argv) 
{
    
    //-----------summation using while loop-------------------//
    int i;
    int n = 1;
    int a, k, x;
    
    cout << "Enter summation number: ";
    cin >> x;
    
    a=k=x;
    
    while(n<=x)
    {
        i+=n;
        n++;
        
    }
    cout << i << endl;
    
    //-----------summation using do-while loop-------------------//
    int j;
    k = 1;
    
    do
    {
        j+=k;
        k++;
    }while(k<=x);
    cout << j << endl;
    
    //-----------summation using for-loop-------------------//
    int b;
    
    for(a = 1; a<=x; a++)
    {
        b+=a;
    }
    cout << b << endl;
    
    
    

    return 0;
}

