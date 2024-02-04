/*This program finds the cosine, sine, and tangent of an angle
  the user supplies the angle in degrees*/
  
#include <iostream>
#include <cmath>
using namespace std;

// create and find const for pi

const double PI = acos(-1);

int main()
{
    //intitialize the variables for the angle
    
    double angle_in_radians , angle_in_degrees;

    //ask user for the angle in degrees

    cout << "Enter the angle in degrees: ";
    cin >> angle_in_degrees;
    
    //convert the angle in degrees to radian

    angle_in_radians = angle_in_degrees * (PI / 180);
    
    // print the angle in radians and degrees in cosine
    
    cout << "The cosine of " << angle_in_radians << " radians, " << 
    angle_in_degrees << " degrees, is approximately " << cos(angle_in_radians)
    << "." << endl;
    
    // print the angle in radians and degrees in sine
    
    cout << "The sine of " << angle_in_radians << " radians, " << 
    angle_in_degrees << " degrees, is approximately " << sin(angle_in_radians)
    << "." << endl;
    
    // print the angle in radians and degrees in tangent
    
    cout << "The tangent of " << angle_in_radians << " radians, " << 
    angle_in_degrees << " degrees, is approximately " << tan(angle_in_radians)
    << "." << endl;
    
    return 0;
}