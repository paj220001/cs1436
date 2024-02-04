#include <iostream>
using namespace std;

int main()
{
    int array[12];
    int highest , lowest, total, average, highest_count, lowest_count;

    for(int count = 0; count < 12; count++)
    {
        cout << "Please enter the total rainfall for month " << (count + 1) << ": ";
        cin >> array[count];
        while(array[count] < 0)
        {
            cout << "Please enter a positive value for the amount of rainfall.\n";
            cout << "Enter the rainfall again: ";
            cin >> array[count];
        }
    }

   highest = array[0];
   lowest = array[0];
   total = array[0];
   average = array[0];
   highest_count = 0;
   lowest_count = 0;



    for(int count = 1; count < 12; count ++)
    {
        if(array[count] > highest)
        {
            highest = array[count];
            highest_count = count;
        }
        
        
        if(array[count] < lowest)
        {
            lowest = array[count];
            lowest_count = count;
        }

        total += array[count];
    }

    average = total / 12;
    
    cout << "Month " << highest_count + 1 << " had the most rainfall at " << highest << endl;
    cout << "Month " << lowest_count + 1 << " had the least rainfall at " << lowest << endl;
    cout << total << " was the total amount of rainfall this year.\n";
    cout << average << " was the average monthly rainfall this year.\n";
}