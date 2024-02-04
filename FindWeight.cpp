//This programs gets the mass of an object in kg and then displays the mass 
// of that object on Venus, Earth, mars, and Jupiter in Newtons and also display 
//"The object is heavy" if it weight over 1500 newtons on earth and "The object is
//light" ig it weight less than 25 newtons on earth

#include <iostream>
#include <iomanip>
using namespace std;

//initializing and defining constants for the acceleration due to gravity for each planet

const double VENUS_ACCELERATION = 8.87;
const double EARTH_ACCELERATION = 9.807;
const double MARS_ACCELERATION = 3.71;
const double JUPITER_ACCELERATION = 24.78;

int main()
{
    //initialize the weight in kg
    
    double weight_kg, venus_weight, earth_weight, mars_weight, jupiter_weight;

    //ask for weight in kg

    cout << "Please enter the mass in Kilograms: ";
    cin >> weight_kg;

    cout << endl;

   if(weight_kg > 0)
   {
        // if mass is greater than 0 calculate the weight in newtons 

        venus_weight = weight_kg * VENUS_ACCELERATION;
        
        earth_weight = weight_kg * EARTH_ACCELERATION;

        mars_weight = weight_kg * MARS_ACCELERATION;

        jupiter_weight = weight_kg * JUPITER_ACCELERATION;

        // create precision

        cout << fixed << setprecision(3) << showpoint;

        //display weights 

        cout << left << setw(10) << "Planet" << "\t" << right << setw(16) << "Weight (N)" << endl
             << endl;

        cout << left << setw(10) << "Venus" << "\t" << right << setw(16) << venus_weight << endl;
        cout << left << setw(10) << "Earth" << "\t" << right << setw(16) << earth_weight;

        // display "Object Heavy" or "Object light"

        if(earth_weight > 1500) // if earth_weight is greater than 1500
        {
            cout << "\tThe object is heavy." << endl;
        }
        else if(earth_weight < 25)// if earth_weight is less than 25
        {
            cout << "\tThe object is light." << endl;
        }
        else
        {
            cout << endl;
        }

        cout << left << setw(10) << "Mars" << "\t" << right << setw(16) << mars_weight << endl;
        cout << left << setw(10) << "Jupiter" << "\t" << right << setw(16) << 
              jupiter_weight << endl;

   }
   else
   {
        cout << "Error mass must be more than zero." << endl;
   }
}