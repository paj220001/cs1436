/*This program gets a string of charachters from the user. For
strings with 2 charachters or less the program displays the input
without modification. if the string is greater than 2 charachters then 
it will dislay either A line containing the first character and the second 
character separated by a space, when the first character of the entered string 
is less than its second character. A line containing the first character and 
the last character separated by a space, when the first character is not less 
than the second, but the first character is less than the last character of the 
entered string. A line containing a new string that begins with the second 
character of the input string, followed by the characters of the input string 
and a period if the input string did not end with a period, whenever the first character 
is not less than either the second character or the last character.
*/

#include <iostream>
#include <string>
using namespace std;

int main()
{
    //define a variable for the string the user will enter 
    string sentence;

    
    //ask user for a string 

    cout << "Please enter a string of characters: \n";
    getline(cin, sentence);


    if(sentence.length() > 2) //if string is longer than 2
    {
        //define variables for the first and second charachter
    
        char ch_1 = sentence.at(0);
        char ch_2 = sentence.at(1);
        char ch_last = sentence.at(sentence.length() - 1);
        
        if(ch_1 < ch_2) // if the first charachter is less than second
        {
            // display 1st charachter and second charachter

            cout << ch_1 << " " << ch_2 << endl;      
        }
        else if(ch_1 < ch_last) // else if first charachter is less than last
        {
            // display 1st charachter and last charachter

            cout << ch_1 << " " << ch_last << endl;
        }
        else // if first charachter is none of these
        {
            // display second characher infront of whole string
            cout << ch_2 << sentence + "." << endl;
        }
    }
    else // if string is 2 or less
    {
        cout << sentence << endl;
    }

    return 0;
}