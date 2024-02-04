//this code gets a string and converts it into ascii format
//once its is converted into ascii format the code will print the numbers on a seperate
//output text file where you can read it 
//user provides the program with the string

//include necessary libraries
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    //intialize varibles 

    unsigned long int numeric_values;

    //ofstream allows you to ouput something in another file 

    ofstream outputfile;
    string filename;
    string phrase;

    //ask for the file the user wants to use

    cout << "Enter the name of the output file.\n";
    getline(cin,filename);

    //open the file the user want to use

    outputfile.open(filename);

    if(outputfile)//if opening the file was successful
    {
        while(phrase != "123")//this loop will keep running until the user enters 123
        {
            //ask for the strings

            cout << "Enter a word or phrase [enter 123 to end input]: ";
            getline(cin,phrase);

            if(phrase != "123")//the code will only convert strings not 123 to ascii
            {
                //this loop will keep going for the length of whatever string the user enters

                for(int counter = 0 ; counter < phrase.length() ; counter++)
                {
                    //convert the charachters into ascii

                    numeric_values = phrase.at(counter);

                    //send ascii to seperate file

                    outputfile << numeric_values << " ";
                }

                outputfile << '\n';
            }
            
        }

    }
    else 
    {
        cout << "Error unable to open output file.\n";
    }

    return 0; 
}