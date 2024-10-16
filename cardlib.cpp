// RJM's file for getting a random card
// 6/2/24
//cardlib.cpp

#include "cardlib.h"

using namespace std;

//Task 1: cardToStr (done)
string cardToStr(aCard c) { //Function cardToStr returns a value with paramters c assigned to aCard
    string result; //result is assigned as a string
    // Convert the card value to a character
    char s1; //s1 is assigned as a character
    if (c.cardVal >= 1 && c.cardVal <= 9) { //Checks if the value is between 1 and 9 (inclusive)
        s1 = '0' + c.cardVal; //A numerical value between 1 and 9 (inclusive) is represented as a numerical value
    }
    else if (c.cardVal == 10) { //Checks if the value is 10
        s1 = 'T'; //10 is represented as T
    }
    else if (c.cardVal == 11) { //Checks if the value is 11
        s1 = 'J'; //11 is represented as J
    }
    else if (c.cardVal == 12) { //Checks if the value is 12
        s1 = 'Q'; //12 is represented as Q
    }
    else if (c.cardVal == 13) { //Checks if the value is 13
        s1 = 'K'; //13 is represented as K
    }
    else if (c.cardVal == 1) { //Checks if the value is 1
        s1 = 'A'; //1 is represented as A
    }
    else {
        s1 = '?'; //Any other value is represented as ?
    }
    char s2; //s2 is assigned as a character
    switch (c.cardSuit) { //We now need to assign a value for cardSuit. This could be either Hearts, Clubs, Diamonds or Spades
    case hearts: //Checks if cardSuit is hearts
        s2 = 'H'; //Assigns s2 to H
        break;
    case clubs: //Checks if cardSuit is clubs
        s2 = 'C'; //Assigns s2 to C
        break;
    case diamonds: //Checks if cardSuit is diamonds
        s2 = 'D'; //Assigns s2 to D
        break;
    case spades: //Checks if cardSuit is spades
        s2 = 'S'; //Assigns s2 to S
        break;
    default: //Checks if cardSuit is any other value
        s2 = '?'; //Any other value for s2 is represented as ?
        break;
    }
    result += s1; //Adds s1 to result
    result += s2; //Adds s2 to result
    return result; //returns the result
}

aCard getCard(string stdno) { //Function returns a card  - using student number stdno (8 numerical chars)
    aCard ans{}; //Assigns ans with aCard initialized
    string rcardstr = stdno.substr(rand() % 8, 1) + stdno.substr(rand() % 8, 1); //Two random characters from stdno
    int rcard = stoi(rcardstr) % 52; //Get integer in range 0..51
    string res = "  ";
    ans.cardVal = 1 + rcard % 13; //Give cardVal 1..13 
    ans.cardSuit = static_cast<Suit>(rcard / 13); //And for suit
    return ans; //Returns ans
}

//Task 3: compareCards (done)
int compareCards(aCard c1, aCard c2) { //Function compareCards returns a value with paramters c1 and c2 assigned to aCard 
    if (c1.cardVal > c2.cardVal) { //Checks if the value of c1 is greater than the value of c2
        return 1; //Returns 1
    }
    else if (c1.cardVal == c2.cardVal) { //Checks if the value of c1 is equal to the value of c2
        return 0; //Returns 0
    }
    else if (c1.cardVal < c2.cardVal) { //Checks if the value of c1 is less than the value of c2
        return -1; //Returns -1
    }
};
