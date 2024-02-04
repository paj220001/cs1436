#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    unsigned long int numeric_values;
    ifstream phrase_to_ascii;
    string filename;
    string phrase;

    cout << "Enter the name of the output file.\n";
    getline(cin,filename);

    phrase_to_ascii.open(filename);

    if(phrase_to_ascii)
    {
        do 
        {
            cout << "Enter a word or phrase [enter 123 to end input]: ";
            cin >> phrase;
            
        }while(phrase != "123");

    }
    else 
    {
        cout << "Error unable to open output file.\n";
    }
}