//This program uses a do while loop to get however many whole numbers 
//the program display the amount of numbers wheter they are positive, 
//negative, or zero , the sum for the positive numbers and the product 
//for the negative numbers. The user determines how many numbers they enter
//by entering Y or N after they enter a number 
// the user provides the whole numbers and 

#include <iostream>
using namespace std;

int main()
{
    //define variables
    int number = 0;
    int amnt = 1;
    int amnt_negative = 0;
    int amnt_positive = 0;
    int amnt_zeros = 0;
    int sum = 0;
    int product = 1;
    char again;

    do//This whole loop will run once and then again if the user enters Y
    {
        // ask for first whole number 

        cout << "Enter whole number #" << amnt << ": ";
        cin >> number;

        //this is the amount of numbers entered so that it will change in the 
        //above cout line

        amnt++; 

        if(number >= 1)//if numbers are greater than 0
        {
            // calculate sum

            sum += number;

            //after a positive is entered this increase to display the 
            //total amount of positives displayed

            amnt_positive++;
        }
        else if (number <= -1)//if numbers are less than 0
        {
            //finds the product

            product *= number;

            //after a negative is entered this increase to display the 
            //total amount of negatives displayed

            amnt_negative++;
        }
        else if (number == 0)//if number is 0
        {
            //after a 0 is entered this increase to display the 
            //total amount of 0's displayed

            amnt_zeros++;
        }

        //ask if they want to enter another number 

        cout << "Would you like to enter another number?\n"
             <<"Enter Y for Yes or N for No: ";
        cin >> again;
    }
    while(again == 'Y' || again == 'y');//loop will repeat if it is Y or y

    cout << endl;
    
    if(amnt_positive > 1)// if there are more than 1 positive
    {
         cout << amnt_positive << " positive values were entered. "; 
         cout << "Their sum was " << sum << "." << endl;
    }
    else if(amnt_positive == 1)//if there is only 1 positive
    {
         cout << " One positive value was entered. "; 
         cout << "It was a " << sum << "." << endl;
    }
    else//if there are no positives
    {
        cout << "No positive values were entered." << endl;
    }
    
    
   if(amnt_negative > 1)// if there are more than 1 negatives
    {
         cout << amnt_negative << " negative values were entered. "; 
         cout << "Their product was " << product << "." << endl;
    }
    else if(amnt_negative == 1)//if there is only 1 negative
    {
        cout  << "One negative value was entered. "; 
         cout << "It was a " << product << "."  << endl;
    }
    else//if there are no negatives 
    {
        cout << "No negative values were entered." << endl;
    }
    
    if(amnt_zeros > 1)// if there are more than 1 0
    {
         cout << amnt_zeros << " zeroes were entered." << endl; 
    }
    else if(amnt_zeros == 1)//if there is only 1 0
    {
        cout <<"One zero was entered." << endl; 
    }
    else//if there are no negatives 
    {
        cout << "No zeroes were entered." << endl;
    }

    return 0;
}