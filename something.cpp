#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    int array[] = {6, 2, 13, 11, 10, 20};
    int sum = 0;

    for(int num : array)
    {
        if((num % 2) == 0)
        {
            cout << num << ' ';
        }
        else 
        {
            sum += num;
        }
        
    }

    cout << sum << endl;

}