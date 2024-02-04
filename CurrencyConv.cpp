//This program perfroms currency conversion from US dollars 
// to to display candian dollars, Mexican pesos, and euros
// while displaying the currencys right justified in tab
//seperated fields twelve charachters wide rounded exactly
// two digits to the right of the decimal
// the user supplies the amount of US dollars

#include <iostream>
#include <iomanip>
using namespace std;

//creating constants for conversions 

const double CONV_CAD = 1.35;
const double CONV_PESOS = 17.19;
const double CONV_EUROS = 0.94;

int main()
{
    //initializing the variables for the different currencys
    
    double usd , cad , pesos , euro;

    //asking for us dollars

    cout << "Enter an amount in US dollars: ";
    cin >> usd;

    //making gap

    cout << endl;

    //doing conversion for CAD currecy

    cad = usd * CONV_CAD;

    //doing conversion for pesos

    pesos = usd * CONV_PESOS;

    //doing coversion for euros

    euro = usd * CONV_EUROS;

    //creating precision

    cout << fixed << setprecision(2) << showpoint;

    // printing names for currencys 

    cout << right << setw(12) << "Dollars" << "\t" << right
        << setw(12) << "CAD" << "\t" << right << setw(12)
        << "Pesos" << "\t" << right << setw(12) << "EUROS" << endl;

    // printing the actual values for the currencys 

    cout << right << setw(12) << usd << "\t" << right
        << setw(12) << cad << "\t" << right << setw(12) 
        << pesos << "\t" << right << setw(12) << euro
        << endl;


    return 0;

}