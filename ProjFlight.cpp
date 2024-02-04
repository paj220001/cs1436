/*This program calculates and displays the flight time, 
  range, and maximum height acheived for a projectile 
  launched from the ground. It will find these using 
  angle the projectile was launched in degrees and the 
  launch velocity in meters per second
  the user supplies both of these
*/

#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

// creating constants for both PI and GRAVITy

const double PI = acos(-1);
const double GRAVITY = 9.81;

int main()
{
    //initialize angle and velocity

    double angle , velocity;

    //ask user for launch angle and store answer

    cout << "Please enter the launch angle in degrees: ";
    cin >> angle;

    //ask used for launch velocity and store answer

    cout << "Please enter the launch velocity in meters/sec: ";
    cin >> velocity;

    //convert launch angle to radians

    angle = angle * (PI / 180);

    //initialize and define horizontal component

    double hori_component = velocity * cos(angle);

    // initialize and define vertical component

    double vert_component = velocity * sin(angle);

    //initialize and define flight_time

    double flight_time = 2.0 * vert_component / GRAVITY;

    //initialize and define range

    double range = 2.0 * hori_component * vert_component 
    / GRAVITY;

    // initialize and define maximumheight

    double hmax = (vert_component * vert_component) / 
    (2.0 * GRAVITY);

    // create precision

    cout << fixed << showpoint << setprecision(6); 

    //print out flight time 

    cout << "\nThe calculated flight time is: " << flight_time
    << " seconds.\n";

    //print out range 

    cout << "The calculated distance traveled is: " << 
    range << " meters.\n";

    //print out hmax

    cout << "The maximum height achieved should be: " <<
    hmax << " meters.\n";

    return 0;


}