//This code gets a coin a flips it a certain amount of times and posts the result of the flip.
//This code has 3 functions a main, getsidename which returns the words heads or tails depending 
//on the flip. flipAmounts which gets the amount of times the coin will be flipped. topdisplay 
//which print which flip we are one and the result of the flip. Lastly bottomdisplay prints the
//results after printing all the flips

#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <iomanip>
using namespace std;

//creating prototype for the functions

string getSideName(unsigned int);

unsigned int flipAmounts(bool&);

void topdisplay (string , int);

void bottomdisplay(unsigned int ,unsigned int , int , int , unsigned int);

int main()
{
    //defining and initializing variables 

    unsigned int flips;
    unsigned int head_counter = 0 , tail_counter = 0 , counter = 0 , flipresult;
    int headcurrentstreak = 0 , headlongstreak = 0 , tailcurrentstreak = 0 , taillongstreak = 0;
    int longeststreak = 0;
    bool goodNum;
    string sidename;

    unsigned int seed;
    cin >> seed;
    //seed = time(0); // Get a seed by calling the time function    
    srand(seed); // Seed the random number generator
    
    //assigning value for the amount of flips that will occur and will pass by true if the
    //flipamounts are greater than 0

    flips = flipAmounts(goodNum);

    if(goodNum)//if the flip amounts are greater than 0
    {
        //this loop will iterate for how many flips the user want to do 

        for(unsigned int flips_counter = 1; flips_counter <= flips; flips_counter++)
        {
            //getting a random number between 1 and 2

            flipresult = rand() % 2 + 1;

            //assign the strings "heads" or "tails" depending on if the random number is 1 or 3

            sidename = getSideName(flipresult);

            if(flipresult == 1)//if the result is heads
            {
                //increment values for the head counters 

                headcurrentstreak++;
                head_counter++;

                //if it is a head then the tails streak ends 

                tailcurrentstreak = 0;

                if(headcurrentstreak > headlongstreak)//if the current streak is longer than the old streak
                {
                    //the longest streak is now the current streak

                    headlongstreak = headcurrentstreak;

                    if(!longeststreak)//if it is not the longest streak
                    {
                        //longest streak equals the heads longest streak

                        longeststreak = headlongstreak;
                    }
                }

            }

            if(flipresult == 2)//if the result is tails
            {
                //increment values for the head counters

                tailcurrentstreak++;
                tail_counter++;

                //if it is a tails then the heads streak ends 

                headcurrentstreak = 0;
                if(tailcurrentstreak > taillongstreak)//if the current streak is longer than the old streak
                {
                    //the longest streak is now the current streak

                    taillongstreak = tailcurrentstreak;

                    if(!longeststreak)//if it is not the longest streak
                    {
                         //longest streak equals the heads longest streak

                        longeststreak = taillongstreak;
                    }
                }
            }
            //increment the amount of flips counter

            counter++;

            //print out the flips and the result of the flip

            topdisplay(sidename , counter);
            
        }

        //print out the analysis of how many of each flip occured and the longest streak

        bottomdisplay(head_counter , tail_counter , headlongstreak , taillongstreak , counter);
    }
}

//this function asks the user how many flips they want to do 
//the function returns an unsigned int for how many flips there are
//and it passes by a bool value whether the flips are greater than 0

unsigned int flipAmounts(bool& goodNumber)
{   
    //define variable 

    unsigned int flips;

    //ask fo the amount of flips 
    cout << "How many coin flips would you like? ";
    cin >> flips;

    if(flips > 0 )//if the flips are positive
    {
        //the number is good

        goodNumber = true;
    }
    else 
    {
        //the number is bad

        goodNumber = false;
    }

    cout << endl;

    //return the amount of flips 

    return flips;
}

//this function converts the values of 1 and 2 to the strings "Heads" and "tails"
//the function takes in a value for what the flip result is either 1 and 2
//the function returns a string for the the name of the flip


string getSideName(unsigned int turn_number)
{
    //define variable 

    string side_name;

    if(turn_number == 1)//if flip is 1
    {
        //assign heads

        side_name = "Heads";
    }
    else if(turn_number == 2)//if flip is 2
    {
        //assign tails 

        side_name = "Tails";
    }

    //return the name 

    return side_name;
}


//this function prints out the flips the code is on and the result of the flip
//the function takes in the name of the result and the counter so you know what flip you are on
//it does not return anything

void topdisplay(string sidename, int counter)
{
    //print out the results

    cout << "Flip #" << counter << " = " << sidename << endl;
}


//this function prints out the analysis of the analysis of how much of each flip occured
//and the the longest streak. The function takes in the total amounts of heads and tails 
//and their highest streaks they had. And the counter to see how many flips occured
//the function does not print anything
void bottomdisplay(unsigned int head_counter,unsigned int tail_counter , int headstreak , int tailstreak, unsigned int counter)
{

    //initialize the total flips 

    int total = head_counter + tail_counter;

    //define variables for percentage

    double headpercentage , tailpercentage;

    //do math to find percentage

    headpercentage = (static_cast<double>(head_counter) / total) * 100;
    tailpercentage = (static_cast<double>(tail_counter) / total) * 100;

    

    if(counter > 0)//if there are more than 0 flips 
    {
        //create precision

        cout << endl << fixed << showpoint << setprecision(1);

        //print out the percentages 
        
        cout << head_counter << " of the " << total << " flips or "
            << headpercentage << "% were Heads.\n";

        cout << tail_counter << " of the " << total << " flips or "
            << tailpercentage << "% were Tails.\n";

        if(headstreak > tailstreak)//if heads has a bigger streak than tails 
        {
            //print longest sequence

            cout << "The longest sequence contained " << headstreak << " Heads.\n";
        }
        else
        {
            // print longest sequence 
            
            cout << "The longest sequence contained " << tailstreak << " Tails.\n";
        }
    }
}
