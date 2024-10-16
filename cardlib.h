#pragma once

// header file for cardlib
// RJM 06/01/24
//cardlib.h

#include <iostream>
#include <string>

enum Suit { hearts, clubs, diamonds, spades }; // define suits

struct aCard { // defines a card
    int cardVal; // number 1 to 13
    Suit cardSuit; // suit
};

// declare function to represent a card as a two character string

//Task 1: carsToStr (done)
std::string cardToStr(aCard c); // Calls std::string cardToStr with parameter c assigned to aCard

// declares function to get a card from stdno string
aCard getCard(std::string stdno); // Calls getCard with aCard with parameter std::string stdno

//Task 3: compareCards (done)
int compareCards(aCard c1, aCard c2); //Calls function compareCards with parameters c1 and c2 assigned to aCard
