// This program gets the date from the user in MM-DD-YYYY form 
//The program converts this into the month_name day, YYYY form
//The program will be able to tell whether there is a leap year 
// and make sure the user enters valid numbes for the months and the days 

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

//creating prototypes for the functions

string getMonthName (int);

bool isLeapYear (int);

bool getValidDate(int& , int& , int&);

void summary ();

int main()
{
    // calling summary to print the results 
   summary();
   
   return 0;
}








//this function converts the months number to the associated month name
//the function takes int the integer value of the month as its only argument 
//from getValidDate and associates it with the word of the month and returns
//that string

string getMonthName(int month)
{
    // intitializing the variable 
    string month_name;

    switch (month)
    {
        //this switch statement creates cases for each month of the year

        case 1:// if month is 1
            month_name = "January";
            break;
        case 2://if month is 2
            month_name = "February";
            break;
        case 3://if month is 3
            month_name = "March";
            break;
        case 4://if month is 4
            month_name = "April";
            break;
        case 5://if month is 5
            month_name = "May";
            break;
        case 6://if month is 6
            month_name = "June";
            break;
        case 7://if month is 7
            month_name = "July";
            break;
        case 8://i month is 8
            month_name = "August";
            break;
        case 9://if month is 9
            month_name = "September";
            break;
        case 10://if month is 10
            month_name = "October";
            break;
        case 11://if month is 11
            month_name = "November";
            break;
        case 12://if month is 12
            month_name = "December";
            break;
    }

    return month_name;
}

//this function gets the date from the user and make sure it is correct
//based on the month and the year. If it is wrong it will print error 
//the function does not take in any arguments but reads the month, date
// and the year. And returns true if all the values are correct 

bool getValidDate(int& month, int& date, int & year)
{
    // initializing and defining variables
    bool validDate = true;
    bool validMonth = true;
    bool validDay = true;
    bool validYear = true; 
    bool validDayAmount = true;
    bool february = true;
    bool leapyear;
    string month_name;
    

    // ask for date 

    cout << "Enter a date [MM-DD-YYYY]: ";
    cin >> month;
    cin.ignore();
    cin >> date;
    cin.ignore();
    cin >> year;

    //makes sure if the their is any gaps in the width it fills those gaps
    //with 0's

    cout << endl << setfill('0');

    if(month < 1 || month > 12)//if the user enters a month less than 1 or greater than 12
    {
        validMonth = false;
    }

    if(date < 1 || date > 31)//if the user enters a date less than 1 or greater than 31
    {
        validDayAmount = false;
    }
    
    
    if(year < 0)//if the user enters a negative date
    {
        validYear = false;
    }

    switch(month)
    {
        case 1://if the user enters more or less days than there are in month 1
            if(date < 1 || date > 31)
            {
                validDay = false;
            }
            break;
        case 2://if the user enters more or less days than there are in month 2
            leapyear = isLeapYear(year);

            //this also incorporates the fact that in a leap year month 2 has 29 days

            if((leapyear == true && date < 1 || date > 29) || 
                (leapyear == false && date < 1 || date > 28))
            {
                validDay = false;
            }
            break;
        case 3://if the user enters more or less days than there are in month 3
            if(date < 1 || date > 31)
            {
                validDay = false;
            }
            break;
        case 4://if the user enters more or less days than there are in month 4
           if(date < 1 || date > 30)
            {
                validDay = false;
            }
            break;
        case 5://if the user enters more or less days than there are in month 5
            if(date < 1 || date > 31)
            {

                validDay = false;
            }
            break;
        case 6://if the user enters more or less days than there are in month 6
            if(date < 1 || date > 30)
            {
                validDay = false;
            }
            break;
        case 7://if the user enters more or less days than there are in month 7
           if(date < 1 || date > 31)
            {
                validDay = false;
            }
            break;
        case 8://if the user enters more or less days than there are in month 8
            if(date < 1 || date > 31)
            {
                validDay = false;
            }
            break;
        case 9://if the user enters more or less days than there are in month 9
            if(date < 1 || date > 30)
            {
                validDay = false;
            }
            break;
        case 10://if the user enters more or less days than there are in month 10
            if(date < 1 || date > 31)
            {
                validDay = false;
            }
            break;
        case 11://if the user enters more or less days than there are in month 11
            if(date < 1 || date > 30)
            {
                validDay = false;
            };
            break;
        case 12://if the user enters more or less days than there are in month 12
            if(date < 1 || date > 31)
            {
                validDay = false;
            };
            break;
    }

    //gets the string name for the month

    month_name = getMonthName(month);

    if(validDay == false || validMonth == false || validYear == false || 
      validDayAmount == false)//if any of the values entered are not correct
    {
       validDate = false;//the whole date is incorrect
       if(validDate == false)//if the whole date is incorrect
       {
            cout << "Error: " << setw(2) << month << "-" << setw(2)
                << date << "-" << setw(4) << year
                << " is not a valid date.\n"; 
       }
       if(validMonth == false)//if they enter a nonexistent month
       {
            cout << month << " is not a valid month.\n"; 
       }
       if(validDayAmount == false)//if they enter a nonexistent amount of days
       {
            cout << date << " is not a valid day.\n";
       }
       if(validDay == false && validDayAmount == true && month != 2)
       //if they enter a date that a month doesnt have that isnt february
       {
            cout << month_name << " does not have a day " 
                 << date << ".\n";
       }
       if(validDay == false && validDayAmount == true && month == 2)
       //if they enter a nonexistent date in february
       {
            cout << month_name << " " << year << "does not have a day "
                 << date << ".\n";
       }
       if(validYear == false)//if they enter a negative year
       {
            cout << year << " is not a valid year.\n";
       }
    }

    //sends whether or not the date is correct

    return validDate;
}

//this functions calculates whether or not a specific year is a leap 
//year and returns true if it is
//this function takes in the year as its only argument 

bool isLeapYear (int year)
{
    //define variable

    bool leapyear = false;

    if((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0))
    //a year is a leap year if is a multiple of 400 or 4 but not 100
    {
        leapyear = true;
    }
    
    //if it is a leap year it send true back 

    return leapyear;
}

void summary ()
{
    //defining varibles

    int month , date , year;
    string month_name;
    char dash = '-';

    // calling getValidDate to get the date and so it passes month date and year

    bool validDate = getValidDate(month, date , year);

    //calling getMonthName to get the string equivalent and giving month as the argument

    month_name = getMonthName(month);

    if(validDate == true)//if all the numbers are correct
    {
        //fills any gap in the width with a 0
        
        cout << setfill('0');
        cout <<  setw(2) << month << dash << setw(2) << date <<
            dash <<  setw(4) << year
            << " is " << month_name << " " << date << ", " << setw(4) << year << endl; 
    }
}

