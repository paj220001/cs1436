/* This program finds the weighted course average for a 
   University course using four quizzes, two midterms, 
   and a final exam. the program calculates and displays 
   the weighted contribution of all the grades to the 
   final course average
   the user provides all grades for the assignment
*/



#include <iostream>
#include <iomanip>
using namespace std;

// creating constants for the multipliers

const double QUIZ_WEIGHT = 0.15;
const double MIDTERM_WEIGHT = 0.35;
const double FINAL_WEIGHT = 0.5;


int main()
{
    //initialize and define all the grades the user gives

    double quiz1 , quiz2 , quiz3, quiz4, midterm1, midterm2
    , final , quiz_average , midterm_average, course_average;

    //ask for quiz grades

    cout << "Please enter the score earned on quiz 1: ";
    cin >> quiz1;

    cout << "Please enter the score earned on quiz 2: ";
    cin >> quiz2;

    cout << "Please enter the score earned on quiz 3: ";
    cin >> quiz3;

    cout << "Please enter the score earned on quiz 4: ";
    cin >> quiz4;

    // ask for midterm scores

    cout << "Please enter the score earned for Midterm 1: ";
    cin >> midterm1;

    cout << "Please enter the score earned for Midterm 2: ";
    cin >> midterm2;

    // ask for final 

    cout << "Please enter the score earned on the final: ";
    cin >> final;

    //calculate the average quiz score

    quiz_average = (quiz1 + quiz2 + quiz3 + quiz4) / 4;

    //calculate the midterm average 

    midterm_average = (midterm1 + midterm2) / 2;

    //calculate course average

    course_average = (quiz_average * QUIZ_WEIGHT) + (midterm_average
    * MIDTERM_WEIGHT) + (final * FINAL_WEIGHT);

    //create precision
    
    cout << fixed << showpoint << setprecision(2);

    // display quiz average 

    cout << left << setw(22) << "Quiz average [15%]:" << right <<
    setw(6) << quiz_average << endl;

    // display midterm average

    cout << left << setw(22) << "Midterm average [35%]:" << right <<
    setw(6) << midterm_average << endl;

    //display final

    cout << left << setw(22) << "Final exam [50%]:" << right <<
    setw(6) << final << endl << endl;

    //display course average

    cout << left << setw(22) << "Course average:" << right <<
    setw(6) << course_average << endl;

    return 0;

}