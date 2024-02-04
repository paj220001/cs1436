//This program simulates coin flips, allowing the user to specify the number of flips.
//It calculates and displays statistics such as the percentage of heads and tails, and the longest consecutive sequence.
//The user can keep entering the number of flips until 0 is entered to exit the program.

#include <iostream>
#include <iomanip>
#include <ctime>

using namespace std;

// Function to get the side name (Heads or Tails) based on the flip result

string getSideName(unsigned int flip) 
{
    return (flip == 1) ? "Heads" : "Tails";
}

// Function to perform coin flips and update counters

void performCoinFlips(unsigned int numFlips, unsigned int& maxConsecutiveHeads, unsigned int& maxConsecutiveTails,
unsigned int& headsCount, unsigned int& tailsCount, unsigned int& firstLongestSequence) 
{
    unsigned int consecutiveHeads = 0;
    unsigned int consecutiveTails = 0;

    for (unsigned int i = 1; i <= numFlips; ++i) 
    {
        // Generate a random number to simulate a coin flip (1 for Heads, 2 for Tails)
        
        unsigned int flipResult = rand() % 2 + 1;

        // Display the result of the current flip
        
        cout << "Flip #" << i << " = " << getSideName(flipResult) << endl;

        // Update counters based on the result of the flip
        
        if (flipResult == 1) 
        {
            consecutiveHeads++;
            consecutiveTails = 0;
            headsCount++;

            // Update the maximum consecutive heads if needed
            
            if (consecutiveHeads > maxConsecutiveHeads) 
            {
                maxConsecutiveHeads = consecutiveHeads;

                // If the first longest sequence hasn't been set, update it
                
                if (!firstLongestSequence) 
                {
                    firstLongestSequence = maxConsecutiveHeads;
                }
            }
        } 
        else 
        {
            consecutiveTails++;
            consecutiveHeads = 0;
            tailsCount++;

            // Update the maximum consecutive tails if needed
            
            if (consecutiveTails > maxConsecutiveTails) 
            {
                maxConsecutiveTails = consecutiveTails;

                // If the first longest sequence hasn't been set, update it
                
                if (!firstLongestSequence) 
                {
                    firstLongestSequence = maxConsecutiveTails;
                }
            }
        }
    }
}

// Function to display statistics

void displayStatistics(unsigned int numFlips, unsigned int headsCount, unsigned int tailsCount,
unsigned int maxConsecutiveHeads, unsigned int maxConsecutiveTails)
{
    

    // Check if there were no flips
    if (numFlips == 0) 
    {
        
        return;
    }

    cout << endl;
    
    // Display the percentage of heads and tails
    
    cout << headsCount << " of the " << numFlips << " flips or " << fixed << setprecision(1)
         << (static_cast<double>(headsCount) / numFlips) * 100 << "% were Heads." << endl;

    cout << tailsCount << " of the " << numFlips << " flips or " << fixed << setprecision(1)
         << (static_cast<double>(tailsCount) / numFlips) * 100 << "% were Tails." << endl;

    // Display the longest consecutive sequence of heads or tails
    
    if (maxConsecutiveHeads > 0 || maxConsecutiveTails > 0) 
    {
        cout << "The longest sequence contained ";
        if (maxConsecutiveHeads > maxConsecutiveTails) 
        {
            cout << maxConsecutiveHeads << " Heads." << endl;
        } 
        else 
        {
            cout << maxConsecutiveTails << " Tails." << endl;
        }
    }
}

int main() 
{
    // Seed the random number generator
    
    unsigned int seed;
    //cin >> seed; // Get a seed by calling the time function
    
    seed = time(0);
    
    srand(seed); // Seed the random number generator

    // Get the number of coin flips from the user, ensuring it's greater than 0
    
    unsigned int numFlips;
    do 
    {
        cout << "How many coin flips would you like? ";
        cin >> numFlips;
    } 
    while (numFlips < 0);

    

    // Initialize counters
    
    unsigned int maxConsecutiveHeads = 0;
    unsigned int maxConsecutiveTails = 0;
    unsigned int headsCount = 0;
    unsigned int tailsCount = 0;
    unsigned int firstLongestSequence = 0;

    // Perform coin flips and update counters
    
    performCoinFlips(numFlips, maxConsecutiveHeads, maxConsecutiveTails, headsCount, tailsCount, firstLongestSequence);

    // Display statistics
    
    displayStatistics(numFlips, headsCount, tailsCount, maxConsecutiveHeads, maxConsecutiveTails);

    return 0;
}
