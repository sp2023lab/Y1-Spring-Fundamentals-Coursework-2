/// SortCard.cpp : This file contains the 'main' function. Program execution begins and ends there.
// RJM 6/2/24

#include "cardlib.h"
#include <string>
#include <vector>
#include <iostream>

using namespace std;

//Task 5: Change the maxCard to 20 from the original
const int maxCard = 20; //Sets the maximum number of cards to 20

aCard thePack[maxCard]; //Assigns a value from thePack with index maxCard to aCard

// Task 2 - printPack (done)
void printPack(std::string mess) {
    cout << mess << " : "; //Outputs mess with a colon
    for (int i = 0; i < maxCard; i++) { //Parses through maxCard, using integer i as a scope
        cout << cardToStr(thePack[i]); //Outputs the card
        if (i < maxCard - 1) { //Checks if i is less than the maximum number of cards minus 1. There is minus 1 because i starts at 0.
            cout << ", "; //Adds a comma after the card
        }
    }
    cout << endl; //Ends here
}

//Task 6: Add a swap card counter and a bubble sort counter (done)
//Task 7: Count the swaps and bubble sorts made (done)
int comparisonCounter = 0; //Sets the number of comparisons to 0
int swapCardsCounter = 0; //Sets the number of swaps to 0
int maxRecursionLevel = 0; //Sets the maximum recursion level to 0

//Task 4: Swap Cards (done)
void swapCards(int n1, int n2) { //swapCards is a function which doesn't return a value with both integers n1 and n2 used as parameters
    if (n1 >= 0 and n1 < maxCard and n2 >= 0 and n2 < maxCard) { //Checks if both integers n1 and n2 are both less than maxCard and greater than or equal to 0
        std::swap(thePack[n1], thePack[n2]); //Swaps the 2 cards by using n1 and n2 as indices 
        swapCardsCounter++; //Adds the number of swaps by 1
    }
    else {
        std::cerr << "Error: Invalid indices for swapCards" << std::endl; //Outputs a message saying that there are invalid indicies for maxCard
    }
}

//Task 5: Bubble Sort (done)
void bubbleSort() { //bubbleSort is a function which doesn't return a value
    for (int i = 0; i < maxCard - 1; i++) { //Parses through the number of maxCards minus 1 using integer i as a scope
        for (int j = 0; j < maxCard - i - 1; j++) { //Parses through the number of maxCards minus i minus 1 using j as a scope
            //We can say maxCard - i - 1 because of the fact some of the elements in the array would have already been sorted
            if (compareCards(thePack[j], thePack[j + 1]) == 1) { //Checks if the first element is greater than the second element in thePack
                swapCards(j, j + 1); //Swaps the cards with each other
            }
            comparisonCounter++; //Adds the number of comparisons by 1
        }
    }
}

//Task 8: QuickSort (done)
void qSort(int lndx, int hndx, int recursionLevel) {
    //qsort is a function which doesn't return a value which uses parameters which are all integers for lower index, higher index and recursionLevel
    maxRecursionLevel = max(maxRecursionLevel, recursionLevel); //Gets the maxRecursionLevel
    if (lndx < hndx) { //Checks if the lower index is less than the higher index
        aCard pivot = thePack[(lndx + hndx) / 2]; // Calculate pivot (in the middle)
        int i = lndx, j = hndx; //Defines both integers as i being equal to the lower index and j being equal to the higher index
        do {
            while (compareCards(thePack[i], pivot) < 0) {
                //Checks if the first element (which is the lower index in thePack) is greater than the second element (which is the pivot)
                i++; // Increase i while the element at i is less than the pivot
                comparisonCounter++; //Adds the number of comparisons by 1
            }
            while (compareCards(thePack[j], pivot) > 0) {
                //Checks if the first element (which is the higher element in thePack) is less than the second element (which is the pivot)
                j--; // Decrease j while the element at j is greater than the pivot
                comparisonCounter++; //Adds the number of comparisons by 1
            }
            if (i <= j) { //Checks if i is less than or equal to j
                // Swap cards at i and j if necessary
                if (i < j) { //Checks if i is less than j
                    swapCards(i, j); //Swaps i and j
                }
                i++; //Adds i by 1
                j--; //Minuses j by 1
            }
        } while (i <= j); //Checks if i is less than or equal to j. This is needed because this checks if i has crossed over with j in the quicksort
        // Recursively sort the two partitions
        if (lndx < j) //Checks if the lower index is less than j
            qSort(lndx, j, recursionLevel + 1); //Uses recursion by calling qSort with parameters lower index, with j and recursion level plus 1
        if (i < hndx) //Checks if i is less than the lower index
            qSort(i, hndx, recursionLevel + 1); //Uses recursion by calling qSort with parameters i, with the higher index and recursion level plus 1
    }
}

//Task 9: Get the program to sort the data 10 times from different 'seeds' using both algorithms (done)
int getRandomSeed() { //getRandomSeed is a function which returns the random seed
    return rand() % 1000; //Returns the random seed which is done through a calculation
}

void performBubbleSort() {
    printf("Bubble Sort:"); //Outputs a message saying bubble sort
    for (int iteration = 1; iteration <= 10; iteration++) { //Loops through the number of iterations using integer iteration as a scope with a max value of 10
        for (int ct = 0; ct < maxCard; ct++) //Parses through the number of maxCards using integer ct as a scope
            thePack[ct] = getCard("32010160"); //thePack with index ct is assigned a card value by using getCard with parameter student ID
        //Reset counters to 0
        comparisonCounter = 0; //The number of comparisons is set to 0
        swapCardsCounter = 0; //The number of swaps is set to 0
        //Task 5: To output the messages (done)
        printPack("Unsorted"); //Outputs a message saying unsorted with the cards unsorted
        bubbleSort(); //Performs bubble sort
        printPack("Sorted"); //Outputs a message saying sorted with the cards sorted
        //Task 6: Output a message for the number of comparisons and swaps (done)
        cout << "This is the number of iterations so far: " << iteration << endl; //Outputs the number of iterations
        cout << "There have been these number of sorts in the quick sort algorithm: " << comparisonCounter << endl; //Outputs the number of comparisons
        cout << "There have been these number of card swaps: " << swapCardsCounter << endl; //Outputs the number of swaps
        cout << "\n\n" << endl; //Outputs 2 line spaces
    }
}

void performQuickSort() {
    printf("Quick Sort:"); //Outputs a message saying quick sort
    for (int iteration = 1; iteration <= 10; iteration++) { //Loops through the number of iterations using integer iteration as a scope with a max value of 10
        int seed = getRandomSeed(); //Sets seed to integer using getRandomSeed as the value
        srand(seed); //Uses command srand to generate a random number using seed
        for (int ct = 0; ct < maxCard; ct++) //Parses through the number of maxCards using integer ct as a scope
            thePack[ct] = getCard("32010160"); //thePack with index ct is assigned a card value by using getCard with parameter student ID
        //Reset counters to 0
        comparisonCounter = 0; //The number of comparisons is set to 0
        swapCardsCounter = 0; //The number of swaps is set to 0
        //Task 5: To output the messages (done)
        printPack("Unsorted"); //Outputs a message saying unsorted with the cards unsorted
        qSort(0, maxCard - 1, 0); //Performs quick sort with 0 set as the lower index, maxCard-1 set as the higher index and 0 set as higher recursion level
        printPack("Sorted"); //Outputs a message saying sorted with the cards sorted
        //Task 6: Output a message for the number of comparisons and swaps (done)
        cout << "This is the number of iterations so far: " << iteration << endl; //Outputs the number of iterations
        cout << "There have been these number of sorts in the quick sort algorithm: " << comparisonCounter << endl; //Outputs the number of comparisons
        cout << "There have been these number of card swaps: " << swapCardsCounter << endl; //Outputs the number of swaps
        cout << "\n\n" << endl; //Outputs 2 line spaces
    }
}

int main() { //Runs through the main program
    cout << "Card Sorting!\n"; //Title
    cout << "\n\n" << endl; //Skip 2 lines
    performBubbleSort(); //Calls performBubbleSort()
    performQuickSort(); //Calls performQuickSort()
    return 0; //0 is returned
}
