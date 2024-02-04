//this program gets number from a file. Makes sure the numbers are correct and find the
//average of the numbers that are valid. The valid numbers can range from 1 to 150
//if some numbers in a file are not valid then they will be put in a seperate file 

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

int main()
{
    //defining and initializing variables

    ifstream inputfile;
    ofstream outputFile;
    string filename;
    double number , total = 0, average;
    int validnumcount = 0, badnumcount = 0 , numcount = 0;

    // ask for the file the user want to use 
    cout << "Enter the input file name.\n";
    cin >> filename;

    //open the file 

    inputfile.open(filename);

    if(inputfile)//if the file is opened successfully 
    {
        //open a file to get ready for bad values 

        outputFile.open("badvalues.txt");

        while (inputfile >> number)//read the number in the file
        {
            //total amount of numbers read 

            numcount++; 

            if(number >= 1 && number <= 150)//if the numbers are good values
            {
                //total amount of good numbers

                validnumcount++;

                //find the total 

                total+=number;
            }
            else 
            {
                //total amount of bad numbers 

                badnumcount++;

                //create precision

                outputFile << fixed << showpoint << setprecision(3);

                //print the bad numbers in the output file 

                outputFile << number << endl;
            }
        }

        //close the files 

        inputfile.close();
        outputFile.close();

        //print out analysis

        cout << endl;
        cout << "Total number of values read: " << numcount << endl;
        cout << "Valid values read: " << validnumcount << endl;
        cout << "Invalid values read: " << badnumcount << endl;

        //find the average 

        average = total/validnumcount;

        if(validnumcount > 0)//if there are any valid numbers
        {
            //create precision 

            cout << fixed << showpoint << setprecision(2);

            //print 

            cout << "The average of the valid numbers read = " << average << endl;
        }
        else//if the file did not open properly
        {
            cout << "The file did not contain any valid values.\n";
        }


    }
    else 
    {
        cout << "The file \"" << filename << "\" could not be opened.\n";
    }

    return 0;
}