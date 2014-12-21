/*
Kyle Vickers
ID: 9844-18528
CS 515
Assignment 3

Card Class: Class definitions for cards used in blackjack.
card.cpp
*/

#include <iostream>
#include <string>
#include <sstream>
using namespace std;
#include "cards.h"


//=========================================================================
//Card::Card constructor. Takes a suit and a value and constructs a card
//=========================================================================
Card::Card( int s, int v )
{
	suit = s;
	initial = v;
	if( initial > 0 && initial < 10 )
	{
       value = initial + 1;
       stringstream conv;
       conv << value;
	   face = conv.str();

	}
   	else if( initial == 0 )
	{
       face = "ace";
   	   value = 1;
	}
	else
	{
	   if( initial == 10 )
		face = "jack";
	   if( initial == 11 )
		face = "queen";
	   if( initial == 12 )
		face = "king";

       value = 10;
	}
}

//=========================================================================
//Card::getSuit()
//Returns a string value of the suit of the card.
//=========================================================================
string Card::getSuit()
{
    if( suit == 0 )
        return "diamonds";
    else if( suit == 1 )
        return "clubs";
    else if( suit == 2 )
        return "spades";
    else
        return "hearts";
}

//=========================================================================
//setAce( int )
//Sets the value of an ace card depending on the playerhands current value.
//=========================================================================
void Card::setAce( int x )
{
	if( ( x + 11 ) <= 21 )
		value = 11;
    //cout << "current total " << x << "set ace vale: " << value;
}




