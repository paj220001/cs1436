//This program is a multifunction program which displays the order of copper wires 
// The program ask the user how many copper wires they want to be ordered, 
// whether there is a discount, whether the customer receives custom shipping, and if
// so how much is that custom shipping and lastly how may copper wire the user has in stock
// based on how many copper wires are in stock the program will calculate how much it is based on 
// if there is any discount or if there is any custom shipping amount  

#include <iostream>
#include <iomanip>
using namespace std;

//creating prototypes for each of the functions

bool getOrder(int& , double& , char& , double&);

bool spoolinStock(int& , int& , int& , int);

double calculateSpoolCharges(int , double);

void orderSummary(double , double , double , int , int);

int main()
{
    //defining variables 

    int spool_amnt, spool_stock , spool_backorder , spool_rdy_ship;
    double discount , shippingcharge , spool_charge;
    char custom_ship;

    //calling getOrder to see what the user wants 

    bool accurate_data = getOrder(spool_amnt, discount, custom_ship, shippingcharge);

    if(accurate_data == true)// if the data is fits all the requirements
    {
        // calling positiveStock to see how many wires are in stock 

        bool positiveStock = spoolinStock(spool_stock , spool_backorder, spool_rdy_ship , spool_amnt);

        if(positiveStock == true)//if there is stock 
        {
            // calling calculateSpoolCharges to find how total will be 

            spool_charge = calculateSpoolCharges(spool_rdy_ship, discount);

            // calling orderSummary to print out the order summary 

            orderSummary(spool_charge , shippingcharge , discount , spool_backorder , spool_rdy_ship);

        }


    }

    cout << "\nThank you, please shop again.\n";

    return 0;
}

//This function gets the order from the user by asking for the number of spools, discount, if it has custom
// shipping and handling the function reads and stores the values and when the data is correct
// it will return true and if not it will return false

bool getOrder(int& spool_amnt_ref, double& discountref, char& custom_ship_ref, double& shippingchargeref)
{
    //defining and initializing to variable that makes sure data is correct

    bool accuratedata = false;

    //ask for amount of spools ordered

    cout << "Please enter the number of spools ordered: ";
    cin >> spool_amnt_ref;

    if (spool_amnt_ref > 0)//if amounts of spools is greater than 0
    {
        //ask for discount

        cout << "Enter the discount percentage for the customer: ";
        cin >> discountref;

        if(discountref < 0)//if discount is less than 0
        {
            cout << "Error.The percentage cannot be negative.\n";
        }
        else 
        {
            // ask if the order includes custom shipping and handling charge

            cout << "Does the order include custom shipping and handling charges? "
                 << "[Enter Y for Yes or N for No]: ";
            cin >> custom_ship_ref;

                //ask for shipping amount 
                if(custom_ship_ref == 'Y' || custom_ship_ref =='y')// if char is either upper or lowercase y
                {
                    // ask for shipping charge 
                    cout << "Enter the shipping and handling charge: ";
                    cin >> shippingchargeref;

                    if(shippingchargeref < 0)//if shipping charge is negative
                    {
                        cout << "Error. Shipping and handling cannot be negative.\n";
                    }
                    else 
                    {
                        accuratedata = true;
                    }
                }
                else if(custom_ship_ref == 'N' || custom_ship_ref == 'n')//if char is N or n
                {
                    shippingchargeref = 15.0;
                    accuratedata = true;

                }
             else 
            {
                cout << "Error.The response should be Y for Yes or N for No.\n";
            }
        }



    }
    else 
    {
        cout << "Error.Spools must be at least one.\n";
    }

return accuratedata;
}

//this function gets the number of spools in stock and if there is not enough stock it will calculate 
// the backorder to find how many spools are able to be purchased and store and read these values
// and return true if the data is correct and false if not 

bool spoolinStock(int& spoolStockRef , int& spoolBackOrderRef , int& spoolsRdyShipRef , int spoolRequest)
{
    //defining and initializing to variable that makes sure data is correct

    bool positiveStock = false;

    //ask for how many spools are in stock

    cout << "Enter the number of spools in stock: ";
    cin >> spoolStockRef;

    if(spoolStockRef >= 0)//if spool stock is positive 
    {
        //calculate back order 

        spoolBackOrderRef = spoolStockRef - spoolRequest;
        positiveStock = true;

        if (spoolStockRef >= spoolRequest)//is there is at least enough stock for the request 
        {
            spoolsRdyShipRef = spoolRequest;
        }
        else 
        {
            spoolsRdyShipRef = spoolStockRef;
        }
    }
    else 
    {
        cout << "Error. The number of spools cannot be negative.\n";
    }

    return positiveStock;
}

//this function calculates the spool charge based on the how many spool can be shippd
// and the discount and will then return that amount 

double calculateSpoolCharges(int spoolrdyship, double discount)
{
    //defining variables 

    double spool_charge, spool_price;

    if(discount == 0)//if there is no discount
    {
        spool_price = 134.95;
    }
    else //if there is a discount it will calculate the new price
    {
        spool_price = 134.95 * ((100 - discount) / 100);
    }

    //calculates the total charge for the spools

    spool_charge = spoolrdyship * spool_price;

    //return the total

    return spool_charge;
}

//This function simply prints out the order summary after all the charges are calculated

void orderSummary(double spoolCharge , double shippingCharge , double discount , int backOrder , int readyShip)
{
    //defining total

    double total;

    //calculating the total

    total = spoolCharge + shippingCharge * readyShip;

    //making sure the decimal is shown and printing the order summary

    cout << fixed << showpoint
         << "\n\t\tOrder Summary"
         << "\n==============================\n";
         if(backOrder < 0)
         {
            cout << backOrder * -1 << " spools are on back order.\n";
         }
         cout << readyShip << " spools are ready to ship.\n";
         if(discount == 0)
         {
            cout << setprecision(2);
            cout << "The charges for " << readyShip << " spools : $" << spoolCharge << endl;
         }
         else
         {
             cout << "The charges for " << readyShip << " spools (including a " << setprecision(1) << discount
                  << "% discount): $" << setprecision(2) << spoolCharge << endl;
         }
         cout << "Shipping and handling for " << readyShip << " spools: $" << shippingCharge * readyShip 
              << "\nThe total charges (incl. shipping & handling): $" << total << endl;
         
}