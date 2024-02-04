//This codes is a multifunction program to calculate and display
// the volume and surface area of a sphere. The program will display
// an error if the radius is less than 0. While consisting of 2 
//meaningful functions find volume and findsurfacearea 
// the user provides the radius

#include <iostream>
#include <cmath> 
#include <iomanip>
using namespace std;

//creating constant for pi

const double PI = acos(-1);

//this function calculates and returns the volume of a sphere.
//the function takes the radius of the sphere as its only argument

double findVolume(double radius_sphere)
{
    double volume = (4.0/3.0) * (PI) * pow(radius_sphere, 3);
    return volume;
}

//This function calculates and returns the volume of a sphere.
// The function takes the radius of the sphere as its only argument 

double findSurfaceArea (double radius_sphere)
{
    double surface_area = 4 * PI * pow(radius_sphere, 2);
    return surface_area;
}

int main()
{
    //define the radius 

    double radius;

    //display sphere calculator

    cout << "\t\tSphere Calculator\n\n";

    // ask for the radius 
    cout << "Please enter the radius of a sphere: ";
    cin >> radius;

    if(radius > 0)
    {

        //define and assign values for surface area and volume

        double surface_area = findSurfaceArea(radius);
        double volume = findVolume(radius);

        //setprecision

        cout << fixed << showpoint << setprecision(3);

        //print out the output

        cout << "\nA sphere with a radius of " << radius << " has:\n"
            << "\tVolume = " << volume << " cubic units.\n"
            << "\tSurface area = " << surface_area << " square units.\n";
    }
    else
    {
        cout << "The radius must be greater than 0.\n";
    }
return 0;
}