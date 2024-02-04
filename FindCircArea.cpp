/*A program that calculates and displays the area of a circle
  the user supplies the radius of the circle in inches
*/
#include <iostream>
#include <cmath>
using namespace std;

const double PI = acos(-1);

int main()
{
    double area, radius;
    
    //get the radius of the circle from the user
    
    //cout << "PI = " << PI << endl; //debug
    
    cout << "Please enter the radius of a circle in inches: ";
    cin >> radius;
    
    //calculate the area of the circle by squaring the radius and multiplying by pi
    
    area = radius * radius * PI;
    
    //Display the area of the circle 
    
    cout << "\nA circle with a radius of " << radius
         << " inches has an area of " << area << " square inches." << endl;
         
    return 0;
}