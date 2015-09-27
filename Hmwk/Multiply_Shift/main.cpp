//Han, Charley - CSC11 - Multiply Shift

#include <cstdlib>
#include <iostream>
#include <bitset>
#include <iomanip>
#include <cmath>

using namespace std;

const float PI = 3.14;
const float YEARCONVS = 1.0f/12.0f;

int main(int argc, char** argv) 
{
    //problem #1 - convert months to years
    cout << "----- Problem #1 Converting Months To Years-----" << endl;
    unsigned char month = 88; //month stored in 1 Byte
    float years = month*YEARCONVS; //result stored in 4 Byte
    cout << "Normal base 10 calculation: " << static_cast<int>(month) << " months" << " = " << years << " years" << " rounded off to 1 Byte integer = " << static_cast<int>(years) << " years." << endl;
    
    //conversion to binary/hex before calculation
    unsigned int R1 = 0b01011000; //BP0 WD8 - months stored in 1 Byte
    unsigned int R2 = 0x155556; //BP-24 WD8 - conversion ratio stored in 3 Bytes
    unsigned int R0 = R1*R2; //result in 1 Byte
    R0 >>= 24; //shift bit/radix point
    
    cout << "--Conversion to 3 Bytes binary and hex-- " << endl;
    cout << "Months: 01011000 - BP0 WD8" << endl;
    cout << "Ratio:  0x155556 - BP-24 WD24" << endl;
    cout << "Binary result cast to integer: " << static_cast<int>(R1) << " times " << hex << R2 << "(hex)" << dec << " = " << static_cast<int>(R0) << " years." << endl;
    
    cout << endl;
    
    //problem #2 - find radius^2 given the area
    cout << "-----Problem #2 Find Radius^2 Given The Area-----" << endl;
    unsigned char area = 110; //area stored in 1 Byte
    float radius = sqrt(area/PI); //result stored in 4 Bytes
    cout << "Normal base 10 calculation: given the area " << static_cast<int>(area) << ", radius = " << radius << " and radius^2 = " << radius*radius << "." << endl;
    
    //conversion to binary/hex before calculation
    unsigned int R3 = 0b01101110; //BP0 WD8 - area stored in 1 Byte
    unsigned int R4 = 0x51745D; //BP-24 WD24 - 1/PI ratio stored in 3 Bytes
    unsigned int R5 = R3*R4; //BP-24 WD32 - result radius^2 stored in 3 Bytes but shifted 24 resulting in 1 Byte
    R5 >>= 24;
    
    cout << "--Conversion to 3 Bytes binary and hex-- " << endl;
    cout << "Area: 01101110 - BP0 WD24" << endl;
    cout << "1/PI: 0x51745D - BP-24 WD24" << endl;
    cout << "Binary result cast to integer: " << static_cast<int>(R3) << " times " << hex << R4 << "(hex)" << dec << " = " << static_cast<int>(R5) << " radius^2." << endl;
  
    cout << endl;
    
    //problem #3 - find radius^2 given the area
    cout << "-----Problem #3 Find Radius^2 Given The Area-----" << endl;
    float area1 = 113.4; //area stored in 4 Bytes
    float radius1 = sqrt(area1/PI); //result stored in 4 Bytes
    cout << "Normal base 10 calculation: given the area " << area1 << ", radius = " << radius1 << " and radius^2 = " << radius1*radius1 << "." << endl;
    
    //conversion to binary/hex before calculation
    float R6 = 113.4; //BP0 WD8 - area stored in 2 Byte
    unsigned int R7 = 0x51745D; //BP-24 WD24 - 1/PI ratio stored in 3 Bytes
    unsigned int R8 = R6*R7; //BP-24 WD32 - result radius^2 stored in 3 Bytes but shifted 24 resulting in 1 Byte
    R8 >>= 24;
    
    cout << "--Conversion to 3 Bytes binary and hex-- " << endl;
    cout << "Area: 113.4 -  base10" << endl;
    cout << "1/PI: 0x51745D - BP-24 WD24" << endl;
    cout << "Binary result cast to integer: " << R6 << " times " << hex << R7 << "(hex)" << dec << " = " << static_cast<int>(R8) << " radius^2." << endl;
  
    cout << endl;
    
    //problem #4 - find area given the radius
    cout << "-----Problem #4 Find Area Given The Radius-----" << endl;
    unsigned char radius2 = 6; //radius stored in 1 Byte
    float area2 = PI*(radius2*radius2); //result stored in 4 Bytes
    cout << "Normal base 10 calculation: given the radius " << static_cast<int>(radius2) << ", area = " << area2 << "." << endl;
    
    //conversion to binary/hex before calculation
    unsigned char R9 = 6; //BP0 WD8 - area stored in 1 Byte
    unsigned int R10 = 0x323D70A; //BP-24 WD24 - 1/PI ratio stored in 3 Bytes
    //unsigned int R10 = 0b000000000000001100100011; //binary form of PI?
    unsigned int R11 = R10*(R9*R9); //BP-24 WD32 - result radius^2 stored in 3 Bytes but shifted 24 resulting in 1 Byte
    //R11 >>= 8; //use when using binary for R10?
    R11 >>= 24; //use when using hex for R10?
    
    cout << "--Conversion to 3 Bytes binary and hex--" << endl;
    cout << "Radius: 6 -  base10" << endl;
    cout << "Binary: 000000000000001100100011 - BP-8 WD24" << endl;
    cout << "Hex: 0x323D70A - BP-24 WD24" << endl;

    cout << "Binary result cast to integer: " << static_cast<int>(R9) << " squared, times " << hex << R10 << dec << " = " << static_cast<int>(R11) << "." << endl;
  
    cout << endl;
    
    //problem #5 - find area given the radius
    cout << "-----Problem #5 Find Area Given The Radius-----" << endl;
    float radius3 = 6.5; //radius stored in 4 Byte
    float area3 = PI*(radius3*radius3); //result stored in 4 Bytes
    cout << "Normal base 10 calculation: given the radius " << radius3 << ", area = " << area3 << "." << endl;
    
    //conversion to binary/hex before calculation
    float R12 = 6.5; //BP0 WD8 - area stored in 4 Byte
    unsigned int R13 = 0x323D70A; //BP-24 WD24 - 1/PI ratio stored in 3 Bytes
    //unsigned int R13 = 0b000000000000001100100011; //binary form of PI?
    unsigned int R14 = R13*(R12*R12); //BP-24 WD32 - result radius^2 stored in 3 Bytes but shifted 24 resulting in 1 Byte
    //R14 >>= 8; //use when using binary for R13?
    R14 >>= 24; //use when using hex for R13?
    
    cout << "--Conversion to 3 Bytes binary and hex--" << endl;
    cout << "Radius: 6.5 -  base10" << endl;
    cout << "Binary: 000000000000001100100011 - BP-8 WD24" << endl;
    cout << "Hex: 0x323D70A - BP-24 WD24" << endl;
    cout << "Binary result cast to integer: " << R12 << " squared, times " << hex << R13 << dec << " = " << static_cast<int>(R14) << "." << endl;
  
    cout << endl;
  
    
    
    return 0;
}

