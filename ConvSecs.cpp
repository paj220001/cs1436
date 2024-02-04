//this program gets the number of seconds and converts the seconds to the 
//total days, hours, minutes, and the remaining seconds
// the user provides the number of seconds 

#include <iostream>
using namespace std;

//create constants for the amount of seconds in each day, hour, minute  

const int SECONDS_DAY = 86400;
const int SECONDS_HOUR = 3600;
const int SECONDS_MINUTE = 60;

int main()
{
    //initialize the variables
    
    long long int time, day , hour , minutes, seconds;

    //ask the user for the amount of seconds 

    cout << "Please enter a number of seconds: ";
    cin >> time;

    if(time > 0) //if time is greater than 0
    {
        //do math to find the amount and the remaining
        
        day = time / SECONDS_DAY;
        hour =  (time % SECONDS_DAY) / SECONDS_HOUR; // the remainder of seconds after days is in the ()
        minutes = (time % SECONDS_HOUR) / SECONDS_MINUTE;//remainder of seconds after hours is in the ()
        seconds = (time % SECONDS_MINUTE);//remaining seconds afer minutes

        cout << time << " seconds is:" << endl;

        if(day > 0) // if amount of days is greater than 0
        {
            cout << "\t" << day << " days." << endl;
        }
        if(hour > 0) // if amount of hours is greater than 0
        {
            cout << "\t" << hour << " hours." << endl; 
        }
        if(minutes > 0) // if amount of minutes is greater than 0
        {
            cout << "\t" << minutes << " minutes." << endl;
        }
        if(seconds > 0) // if amount of seconds is greater than 0
        {
            cout << "\t" << seconds << " seconds." << endl;
        }
    }
    else
    {
        cout << "seconds must be greater than zero" << endl;
    }
}