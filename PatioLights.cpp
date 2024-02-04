// This program gets the length of the side of the patio opposite the house 
// and the lenght of the sides of the patio perependicular to the house and 
// calculates the the length of th eruns to be strung using pythagorean theorm
// the user gives the lenght of the side opposite of the house adn the side 
// perpendicular to the house and the 

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std; 

int main()
{
    //initialize the inputs the user will give
    
    double length_opposite, length_perpendicular;
    
    // get length of the opposite side from the user 
    
    cout << "Please enter the length of the side of the patio"
    "opposite the house in feet: ";
    cin >> length_opposite;
    
    // get the length of the perpendicular side from the user
    
    cout << "Please enter the length of the sides of the patio"
    " perpendicular the house" 
    << " in feet: ";
    cin >> length_perpendicular;
    
    //calculate length diagonal using pythagorean theorm
    
    double length_diagonal = sqrt((length_opposite * length_opposite) + 
    (length_perpendicular * length_perpendicular));
    
    
    //initialize and define the total length
    
    double total_length = (length_opposite + (2 * length_perpendicular) + 
    (2 * length_diagonal));
    
    //display total length before sag
    
    cout << "Total length calculated = " << total_length << " feet.\n";
    
    //calculate the length plus sag opposit
    
    length_opposite *= 1.07;
    
    // displag length plus sag opposite 
    
    cout << "The length of the run opposite the house including sag = " <<
    length_opposite << " feet.\n";
    
    //calculate length plus sag for perpendicular
    
    length_perpendicular *= 1.07;
    
    //calculate twice length + sag
    
    double total_length_perpendicular = length_perpendicular * 2;
    
    //display length plus sag perpendicular
    
     cout << "The length of the two perpendicular runs including sag ="
     << " " << length_perpendicular << " feet each.\n";
     
     // calculate length + sag for diagonal
     
     length_diagonal *= 1.07;
     
     //calculate the twice length plus sag diagonal
     
     double total_length_diagonal = length_diagonal * 2;
     
     //display length plus sag diagonal
     
     cout << "The length of the two diagonal runs including sag = " << 
     length_diagonal << " feet each.\n";
     
     //calculating total length with snag
     
     double total_length_with_snag = length_opposite + 
     total_length_perpendicular + total_length_diagonal;
     
     //displaying total length with snag
     
     cout << "The total length of the strands needed including sag = " << 
     total_length_with_snag << " feet.\n";
    
    return 0;
    
    
    
    
}
