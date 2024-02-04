//this programs reads 2 different files. First it reads the first file and stores up to 100 words from that file
//then it reads the second file and stores all the words from that file. The program then gets the words from the
//first file and see how many times each of those words appear in the second file. the program then prints the findings
//including how many words are in the second file. It also has error statements depending on whether if any of the files
//could not be opened successfully or if the first file is empty
//the user provides the names for the files 


#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
using namespace std;

//creating prototypes for the functions 

bool openSearchFile(ifstream& , string&);

unsigned int getSearchWordList(ifstream&, string [], const unsigned int);

bool openOFile(ifstream& , string&);

void compareWordList (ifstream&, string [], unsigned int , string);

int main()
{
    //initializing and defining functions 

    const unsigned int MAX_VALUE = 100; 
    ifstream inputFile , searchFile;
    string searchfileName , words[MAX_VALUE] , occurenceFileName;
    unsigned int stringAmount;

    if(openSearchFile(inputFile , searchfileName))//if the function returns true if the file can be opened.
    {
       stringAmount = getSearchWordList(inputFile, words, MAX_VALUE);//call the function to find how many words are in the first file 

       if(words[0] != "")//if the first file is not empty
       {

            if(openOFile(searchFile, occurenceFileName))//if the funtion returns true if the second file can be opened
            {
                compareWordList(searchFile, words, stringAmount , occurenceFileName);//compare the 2 files and print the findings

                //close second file 

                searchFile.close();
            }

            //close first file 

            inputFile.close();
       }
       else//if the file is empty 
       {
    
        cout << endl << searchfileName << " was empty.\n";
        
       }
    }
    
}

//this functions asks the user for the name of the file and makes sure if the file can be opened 
//or it will print an error. The function returns a bool for whether the file can be opened or not 
//and it passes by a ifstream value to get the input file and a string for the name of that file

bool openSearchFile(ifstream& inputFile , string& fileName)
{
    //define variables

    bool opened = false;
    string words;

    //ask for the name of the first file and store it 

    cout << "Enter the name of the file containing the search list.\n";
    cin >> fileName;

    //open the file

    inputFile.open(fileName);

    if(inputFile)//if the file could be opened successfully
    {
        //change the bool value 

        opened = true;
    }
    else //if the file cant be opened
    {
        cout << "\nError! Cannot open " << fileName << ".\n";
    }

    //return te bool value 

    return opened;
}

//this function reads all the words in the first file for the words to search for
//This function returns an unsigned int for the number of words that are in the file 
//the function passes by an ifstream for the input file, an array to store all the words
//and a const unsigned int for the max words the array can store

unsigned int  getSearchWordList(ifstream& inputFile , string words[] , const unsigned int MAX_VALUES)
{
    //define variables

    unsigned int index = 0;
    unsigned int stringNumber = 1;
    string hello;

   if(inputFile >> words[0])
   {
        index++;

        while(inputFile >> words[index] && index <= MAX_VALUES)//this loop will keep reading words from the file until the file is finished or if there are to many words
        {
            //increment the values 

            stringNumber++;
            index++;
            
        } 
   }

    //retunr the number of words in the first file 

    return stringNumber;

}

//this functions asks the user for the name of the file and makes sure if the file can be opened 
//or it will print an error. The function returns a bool for whether the file can be opened or not 
//and it passes by a ifstream value to get the input file and a string for the name of that file

bool openOFile(ifstream& searchFile, string& fileName)
{
    //define variable 

    bool opened = false;

    //ask for the name of the file and store it

    cout << "Enter the name of the file to be searched for occurrences of the words.\n";
    cin >> fileName;

    //open the file 

    searchFile.open(fileName);

    if(searchFile)//if the file is opened successfully 
    {
        //change bool value 

        opened = true;
    }
    else //if the file can't be opened 
    {
        cout << "\nError! Cannot open " << fileName << ".\n";
    }

    //return the bool if the file can be opened or not 

    return opened;
}

//this functions reads the second file for the words and stores them in an array then compares them to the first array
//then it print how many words in the files are similar and prints those findings.
//the function does not return anything  
//and it passes by a ifstream value for the input file a string for the words in the first file a unsigned int for the 
//amount of the words and a string for the name of that file

void compareWordList(ifstream& searchFile, string searchwords[] , unsigned int stringAmount , string searchfilename)
{
    //define the variable 

    int count, fileindex = 0, wordcount= 0;
    string words[10000];

    while(searchFile >> words[fileindex])//this loop will continue until the file ends
        {
            //increment values 

            fileindex++;
            wordcount++;
        }

    //print the findings

    cout << endl << searchfilename << " had " << wordcount << " words.\n"
         << "The table below lists the search words and their occurrences in the file.\n\n"
         << left << setw(20) << "Search Words" << "\t" << right << setw(12)  << " Occurrences\n";

    for(unsigned int index = 0; index < stringAmount; index++)//this loop will go through every word in the first file 
    {
        count = 0;
       for(fileindex = 0; fileindex < wordcount; fileindex++)//this loop will go through every word in the second file for every word in the first file 
       {
            if(words[fileindex] == searchwords[index])//if the word int he first file is the same as the one in the second file 
            {
                //increment count

                count++;
            }

       }

       //print findings 

       cout << left << setw(20) << searchwords[index] << "\t" << right << setw(12) << count << endl;
    }

    
}