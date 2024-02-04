//This program calculates the distance an object travels in a certain amount of time
//on the earth and on the moon. Using multiple functions 
// the user provides the time

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

//creating prototype for getseconds

double getSeconds();

//creating prototype for findEarthfall

double findEarthFallDist(double);

//creating prototype for function 2

double findMoonFallDist(double);

// set constants for gravity

const double EARTH_GRAVITY = 9.807;
const double MOON_GRAVITY = 1.625;

int main()
{
    //define seconds 

    double seconds = getSeconds();

    if (seconds >= 0)
    {
        double earth_fall = findEarthFallDist(seconds);
        
        double moon_fall = findMoonFallDist(seconds);
    

    cout << fixed << showpoint << setprecision(1);

    cout << endl << "In " << seconds << " seconds the object traveled:\n"
         << setprecision(2)
         <<"\t" << earth_fall << " meters on Earth.\n"
         <<"\t" << moon_fall << " meters on the Moon.\n";
    

    }
    return 0;


}

//This function prompts the user for the time of the fall in seconds and returns the value


double getSeconds()
{
   //intitalize seconds

   double seconds;
   
    //ask for seconds

    cout << "Please enter the time of the fall (in seconds): ";
    cin >> seconds;

    if(seconds < 0)
    {

        cout << "Error\n"
             << "The time must be at least zero.\n"; 
    }

    return seconds;
}


double findEarthFallDist(double seconds)
{
    // define and intialize the distance on earth

    double earth_distance = 0.5 * EARTH_GRAVITY * pow(seconds , 2.0);

    return earth_distance;
}


double findMoonFallDist(double seconds)
{
    //define and initalize the distance on the moon

    double moon_distance = 0.5 * MOON_GRAVITY * pow(seconds, 2.0);

    return moon_distance;
}