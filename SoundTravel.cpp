//This code is a menu driven program that determines how fast sound travels
// a specified distance through wood, steel, water, or air
// the user provideds through what medium sound travels through and the distance 

#include <iostream>
#include <iomanip>
using namespace std;

//creating constanst for speed

const double WOOD_SPEED = 12631.23;
const double STEEL_SPEED = 10614.81;
const double WATER_SPEED = 4714.57;
const double AIR_SPEED = 1125.33;

//create constants for menu choices

const unsigned int WOOD_CHOICE = 1;
const unsigned int STEEL_CHOICE = 2;
const unsigned int WATER_CHOICE = 3;
const unsigned int AIR_CHOICE = 4;

int main()
{
    //create varaible for choice
    
    unsigned int element;

    //display menu

    cout << "\tTime for Sound to Travel through a Medium given Distance\n";
    cout << "\n1 - Wood\n";
    cout << "2 - Steel\n";
    cout << "3 - Water\n";
    cout << "4 - Air\n";

    //ask for choice

    cout << "\nEnter the number of the medium: ";
    cin >> element;

    //create constants for the choices

    const unsigned int WOOD_CHOICE = 1;
    const unsigned int STEEL_CHOICE = 2;
    const unsigned int WATER_CHOICE = 3;
    const unsigned int AIR_CHOICE = 4;
                   
    if(element >= 1 && element <= 4) //if they put a number between 1 and 4
    {
        // create variable for distance and time

        double distance , time;
        
        //ask for distance

        cout << "\nEnter the distance to travel (in feet): \n";
        cin >> distance;

        if(distance > 0) //makes sure user enters a positive number
        {
        
            //switch statment 

            switch(element)
            {
                case WOOD_CHOICE: // if they chose 1
                        cout << fixed << showpoint;
                        time = distance / WOOD_SPEED;
                        cout << "In wood it will take " << setprecision(4) 
                        << time 
                        << " seconds to travel " << setprecision(2) 
                        << distance << " feet.\n";
                        break; 
                case STEEL_CHOICE://if they chose 2
                        cout << fixed << showpoint;
                        time = distance / STEEL_SPEED;
                        cout << "In steel it will take " << setprecision(4)
                        << time  << " seconds to travel " << setprecision(2) 
                        << distance << " feet.\n";
                        break;  
                case WATER_CHOICE://if they chose 3
                        cout << fixed << showpoint;
                        time = distance / WATER_SPEED;
                        cout << "In water it will take " << setprecision(4)
                        << time << " seconds to travel " << setprecision(2) 
                        << distance << setprecision(2) << " feet.\n";
                        break; 
                case AIR_CHOICE://if they chose 4
                        cout << fixed << showpoint;
                        time = distance / AIR_SPEED;
                        cout << "In air it will take " << setprecision(4)
                        << time << " seconds to travel " <<setprecision(2)
                         << distance << " feet.\n";
                        break; 

            }
        }
        else 
        {
            cout << "Error the distance must be greater than zero.\n";
        }
    }
    else 
    {
        cout << "Error Please run the program again.\n";
    }

    return 0;
}