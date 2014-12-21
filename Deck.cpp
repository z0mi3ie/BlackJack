/*
Kyle Vickers
ID: 9844-18528
CS 515
Assignment 3

Deck Class: Deck definitions for deck in blackjack
Deck.cpp
*/

#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;
#include "cards.h"


//=========================================================================
//Deck()
//Constructor. Constructs a deck and pushes 52 cards onto it.
//=========================================================================
Deck::Deck()
{
  	for (int suit = 0; suit < 4; suit++)
	{
    		for (int rank = 0; rank < 13; rank++)
		{
      			cards.push_back( Card( suit, rank ) );
    		}
  	}
}

//=========================================================================
//getSize()
//Returns the size of the deck()
//=========================================================================
int Deck::getSize()
{
	return cards.size();
}

//=========================================================================
//drawCard()
//Draws a card of the deck.
//=========================================================================
Card Deck::drawCard()
{
	Card drawnCard = cards.back();
	cards.pop_back();
	return drawnCard;
}

//=========================================================================
//shuffle()
//This method shuffles the deck.
//=========================================================================
void Deck::shuffle()
{
    srand ( unsigned ( time (NULL) ) );
    random_shuffle(cards.begin(),cards.end() );
}



