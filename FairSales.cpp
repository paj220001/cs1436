//This program gets the number of Chili dogs, corn dogs, chips
//soft drinks, and water bottles sold in order and displays the 
// taxable items sold at a rate of 6.5 percent, amount of tax
// the dollar amount of non taxable and the total of 3 values
//the user supplies the number of Chili dogs, corn dogs, chips
// soft drinks and water bottles

#include <iostream> 
#include <iomanip>
using namespace std;

//create contants for tax anf the price of items

const double TAX_RATE = 0.065;
const double CHILI_DOG_PRICE = 8.5;
const double CORN_DOG_PRICE = 7.0;
const double CHIPS_PRICE = 2.5;
const double SOFT_DRINK_PRICE = 4.5;
const double WATER_PRICE = 4.0;

int main()
{
    //initialize the amount of items sold

    int corn_dogs_sold , chili_dogs_sold , chips_sold ,
    soft_drinks_sold , water_sold;

    //initialize amounts

    double taxable , tax_amount , non_taxable , total;

    // ask for chili dogs

    cout << "How many chili dogs were sold? ";
    cin >> chili_dogs_sold;

    //ask for corn dogs

    cout << "How many corn dogs were sold? ";
    cin >> corn_dogs_sold;

    // ask for chips sold

    cout << "How many bags of chips were sold? ";
    cin >> chips_sold;

    // ask for soft drinks

    cout << "How many soft drinks were sold? ";
    cin >> soft_drinks_sold;

    // ask for water

    cout << "How many bottles of water were sold? ";
    cin >> water_sold;

    //calculate taxable


    taxable = (chili_dogs_sold * CHILI_DOG_PRICE) + 
    (corn_dogs_sold * CORN_DOG_PRICE) + (chips_sold * CHIPS_PRICE)
    + (soft_drinks_sold * SOFT_DRINK_PRICE);

    //calculate tax amount

    tax_amount = taxable * TAX_RATE;

    //calc non taxable

    non_taxable = water_sold * WATER_PRICE;

    //calculate total

    total = taxable + tax_amount + non_taxable;

    //create precision

    cout << fixed << showpoint << setprecision(2);

    //display taxable 

    cout << endl << left << setw(15) << "Taxable:" << setw(1)
    << "$" << right << setw(10) << taxable << endl;

    // display tax amount

    cout << left << setw(15) << "Tax amount:" << setw(1)
    << "$" << right << setw(10) << tax_amount << endl;

    // display non taxable

    cout << left << setw(15) << "Non-taxable:" << setw(1)
    << "$" << right << setw(10) << non_taxable << endl;

    //display total

    cout << left << setw(15) << "Total:" << setw(1)
    << "$" << right << setw(10) << total << endl;

    return 0;

}