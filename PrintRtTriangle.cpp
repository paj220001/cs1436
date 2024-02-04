//this program uses nested loops and prints a right triangle.
//the program uses a whole number to get the full length of the triangle
//it also uses a charachter to represent the length 
// the user provides the length and the charachter


#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    //initializing variables 

    unsigned int length;
    char trianglechar;
   
    //ask the user for the length and store it in length

    cout << "Enter the length of one of the legs of the right triangle: ";
    cin >> length; 

    //ask the user what charachter they want to use to represent the lenght

    cout << "Enter the character used to draw the triangle: ";
    cin >> trianglechar;

    cout << endl;

    for(int row = 1; row <= length; ++row)//it will iterate for as what the length is 
    {
        for(int gaps = 1; gaps <= length - row; ++gaps)//this loop decreases the amount of spaces based on the row and lenght 
        {
            //print out spaces
           
            cout << setw(2) << left << ' ';
          
            
        }
        for(int usercharnum = 1; usercharnum <= row; ++usercharnum)//this loop increases the amount of spaces based on the row
        {
            //print out the charachter 

            cout << setw(2)  << left << trianglechar;
        }

        //this will make it go to a new line

        cout << endl;
    }

    return 0;

}
     