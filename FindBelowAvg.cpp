//this program gets scores between the values 0 and 150 and make adds them all together and averages them
//this program makes sure the the user can only enter 120 values between 0 and 150 inclusive. If not they will get an
//error. The program stores these numbers in a single array. The program gets all the valid numbers, adds them up and gets
//the average. The program uses a loop to keep asking the user to enter a score until the enter -999 to end the entering
//of scores or if the users has entered more than 120 scores
//the user provides the program with the scores

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    //initialize and define variables 

    const int MAX_SCORES = 120;
    int score_array[MAX_SCORES];
    int index = 1 , total = 0, totalNum = 0;
    double average;

    //ask for the first score and store it

    cout << "Enter the first score or -999 to end input: ";
    cin >> score_array[0];

    if(score_array[0] < 0 || score_array[0] > 150)//if the first score is a valid number
    {
        if(score_array[0] != -999)//and if it not a end signal
        {
            cout << "\nError, " << score_array[0] << " is not a valid score.\n"
                 <<"Valid scores are in the range 0 through 150 inclusive.\n";
        }
    }
    else if(score_array[0] != -999)//if it not an end signal
    {
        //add it to the total 

        total = score_array[0];

        //increase everytime a valid number is entered

        totalNum++;
    }
    
    if(score_array[0] != -999)//if the user did not enter the sentinel as the first number
    {
        while(score_array[index] != -999 && index < MAX_SCORES)//this loop will keep running unless the user enters the sentinnel or if they have entered the max scores
        {
            //ask for the next scores and store it
              
            cout << "Enter the next score or -999 to end input: ";
            cin >> score_array[index];

                if(score_array[index] >= 0 && score_array[index] <= 150)//if the enter a valid score 
                {   
                    //add the value to the total

                    total = total + score_array[index];

                    //increment the index and the total amount of valid numbers 

                    index++;
                    totalNum++; 
                }
                else if(score_array[index] != -999)//if the score is not valid and is not the sentinnel
                {
                    //print the error message 

                    cout << "Error, " << score_array[index] << " is not a valid score.\n"
                            <<"Valid scores are in the range 0 through 150 inclusive.\n";
                }
            //caluculate the average

            average = static_cast<double>(total) / (totalNum);


        }

        if(index >= MAX_SCORES)//if the array is filled up
        {
            //print message 

            cout << "Array is full! Ending input.\n";
        }

        //set precision
           
        cout << fixed << showpoint << setprecision(1);

        cout << endl << "The average of the scores is: " << average << "." << endl;

        if(totalNum > 1)//if more than 1 good value is entered
        {
            cout << "The scores below the average were: ";

            for(index = 0; index <= totalNum - 1; index++)//this loop will keep running for how many good values there are 
            {
                if(score_array[index] < average && score_array[index] >= 0)//if the value is less than the average and greater than 0
                {
                    cout << score_array[index] << " ";
                }
            }

            cout << endl;
        }

    }
    else 
    {
        cout << "No valid scores were entered.\n";
    }

}