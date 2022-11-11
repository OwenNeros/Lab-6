/*
 Owen Neros
 Lab 6
 Binary number to decimal equivalent outputs
 This goal of this lab is to make a code that is able to input binary numbers from a file, translate it over to decimal equivalent, and output both numbers to a screen.
 */

#include <iostream>
#include <fstream>

using namespace std;

string inputFileName = "/Users/owenneros/Desktop/HelloWorld/C++/Lab-6/Lab-6/Lab6Input";
string readin;

void getnumber();


int main() {
    cout << setw(20) << "Binary Number"; // format
    cout << setw(30) << "Decimal Equivalent" << endl;//  format
    getnumber(); // calll function

    return 0;
}

void getnumber(){
    ifstream inFile;
    inFile.open(inputFileName); // open file
    
    int x = 0; // integer value for mathh
    char bi; // character of input
    bool w = false;
    bool bad = false;
    int c =0; // character count
    
    inFile.get(bi); // get characters
    
    while(inFile)
    {
        while (bi != '\n' && inFile){
            if (!w && (bi == '1' || bi == '0') || w && (bi == '1' || bi =='0')){ // lot of logic to make sure the code can grab a valid binary number even with a 0 or a ' ' before it
                c++; // add to digit count
                w = true;
        cout << bi;// outut binary
        x *= 2;// convert to decimal
        
        if (bi == '1'){ // math only matters if character is a 1
            x++;
        }
            }
            else if(bi != ' ' || ( bi == ' ' && w)){ // if a non 1 or 0 character is inside binary number then output bad digit on input
                for(int i = 0; i < c; i++)
                    cout << '\b'; // delete characters before for formatting
                
                cout << "Bad digit on input" << endl;
                bad = true;
                inFile.ignore(256, '\n');
                break;
            }
        inFile.get(bi);
        }
        if (!bad){ // outputting decimal equivalent if the input is valid
    cout << setw(35) << x << endl;
        }
        w = false;
        c = 0;
        bad = false;
        inFile.get(bi);
        x = 0;
    }// resetting all variables before re run while loop
}

