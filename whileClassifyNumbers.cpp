//This program uses while loop to get however many whole numbers 
//the program display the amount of numbers wheter they are positive, 
//negative, or zero , the sum for the positive numbers and the product 
//for the negative numbers. The user determines how many numbers they enter
//by entering 0 if they want to stop entering numbers 
// the user provides the whole numbers and 
#include <iostream>
using namespace std;

int main()
{
    //defining variables
    int number =0;
    int amnt_negative = 0;
    int amnt_positive = 0;
    int sum = 0;
    int product = 1;

    //asking for a whole number 

    cout << "Enter a whole number [enter 0 to end input]: ";
    cin >> number;

    while(number != 0)//this loop will keep happening until the user enters 0
    {
        if(number >= 1)//if the number is positive
        {
            //calculating the sum

            sum += number;

            //everytime the user enters a + this increases so that you know the total # of +'s
            amnt_positive++;
        }
        else if (number <= -1)//if the number is negative
        {
            //calculating the product

            product *= number;

            //everytime the user enters a + this increases so that you know the total # of +'s

            amnt_negative++;
        }

        //asking if the user wants to enter another number if not they can enter 0

        cout << "Enter another whole number [enter 0 to end input]: ";
        cin >> number;
    }

    cout << endl;
    
    if(amnt_positive > 1)//if more than 1 + is entered
    {
        //print sum 

         cout << amnt_positive << " positive numbers were entered. "; 
         cout << "Their sum was " << sum << "." << endl << endl;
    }
    else if(amnt_positive == 1)//if only 1 + was entered
    {
        // print the +

         cout << amnt_positive << " positive number was entered. "; 
         cout << "It was a " << sum << "." << endl << endl;
    }
    else//if no + were entered
    {
        cout << "No positive numbers were entered." << endl << endl;
    }
    
    
   if(amnt_negative > 1)//if more than 1 - is entered
    {
        //print the product

         cout << amnt_negative << " negative numbers were entered. "; 
         cout << "Their product was " << product << "." << endl;
    }
    else if(amnt_negative == 1)//if only 1 - was entered
    {
        // print the -

         cout  << amnt_negative << " negative number was entered. "; 
         cout << "It was a " << product << "."  << endl;
    }
    else//if no - were entered
    {
        cout << "No negative numbers were entered." << endl;
    }
    
}