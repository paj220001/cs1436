//this program will read a file that has stores and their respective sales and creates a bar chart to
//represent their sales on seperate file. The program will represent each $5000 wih 1 *. If the stroe number
//is greater than 100 or less than or if the sales are negative then the store will be skipped. if the file can 
//not be opened then the error will be written
//the user provides the file name 

#include <iostream>
#include <fstream>
#include <string>
#include <string>
#include <iomanip>
using namespace std;

int main()
{
    //define and initialize variables 

    ifstream inputFile;
    ofstream outputFile;
    string fileName;
    int storenumber = 0, amount_of_chars = 0;
    long long int sales;
    bool firsttime = true;

    //ask for the file name 

    cout << "Please enter the input file name.\n";
    cin >> fileName;

    //open the file 

    inputFile.open(fileName);

    if(inputFile)//if the file is opened successfully
    {
        //open the output file 

        outputFile.open("saleschart.txt");

            if(outputFile)//if the output file is opened successfuly
            {
                while(inputFile >> storenumber >> sales)//this loop will keep looping until it stops reading from the file
                {
                    if(storenumber >= 1 && storenumber <= 99)//if the store number is positive less than 99
                    {
                        if(sales >= 0)//if sales are positive
                        {
                            if(firsttime == true)//this is so that the it prints the key once
                            {
                                //print the key

                                outputFile << "SALES BAR CHART\n"
                                           << "(Each * equals 5,000 dollars)\n";

                                // change it so that the key wont print again

                                firsttime = false;
                            }

                            //do the math

                            amount_of_chars = sales/5000;

                            //print the store number 

                            outputFile << "Store " << setw(2) << storenumber << ": ";

                            for(int count = 0; count < amount_of_chars; count++)//keep printing stars till it reaches amount of chars
                            {
                                //print the star

                                outputFile <<  "*";
                            }
                            outputFile << endl;
                        }
                        else 
                        {
                            //print the sales is negative 

                            cout << "Error, negative sales found for store number " << storenumber <<"."
                                << "\nSkipping this entry.\n";
                        }
                    }
                    else 
                    {
                        //print if the store number is wrong

                        cout << "Error, invalid store number " << storenumber << " found in file."
                            << "\nSkipping this entry.\n";
                    }

                 }
            }
        
            //close the files 

            inputFile.close();
            outputFile.close();
    }
    else
    {
        //if the input file cant be opened 
        
        cout << endl; 
        cout << "Input file error! \"" << fileName << "\" could not be opened.\n";
    }
}