/*
Kyle Vickers
ID: 9844-18528
CS 515
Assignment 3

Hands Class: Class definitions for hands used in blackjack.
Hands.cpp
*/


#include <iostream>
#include <string>
using namespace std;
#include "hands.h"


//=========================================================================
//PlayerHand()
//Constructor and sets the value of the players hand to 0.
//=========================================================================
PlayerHand::PlayerHand( )
{
    playervalue = 0;
}

//=========================================================================
//giveCard()
// gives a card to the players hand and updates the value of the hand.
// This also takes into account the total player hand's value and if the
// card given is an Ace. 1 or 10 value is assigned to the PV depending on
// what would make a better hand.
//=========================================================================
void PlayerHand::giveCard( Card c )
{
    if( ( c.value == 1 ) && ( playervalue + 11 ) <= 21   )
    {
        playervalue += 11;
    }
    else
    {
        playervalue += c.value;
    }

    playercards.push_back( c );
}

//=========================================================================
//void printCards()
//Outputs the cards in the players hand to the screen.
//=========================================================================

void PlayerHand::printCards()
{
     for(std::vector<Card>::iterator it = playercards.begin(); it != playercards.end(); ++it)
     {
       Card current = *it;
       cout << current.face << " of " << current.getSuit() << endl;
     }

}

//=========================================================================
//DealerHand()
//Constructor and sets the value of the dealers hand to 0.
//=========================================================================

DealerHand::DealerHand( )
{
    dealervalue = 0;
}

//=========================================================================
//giveCard()
// gives a card to the players hand and updates the value of the hand.
// This also takes into account the total player hand's value and if the
// card given is an Ace. 1 or 10 value is assigned to the PV depending on
// what would make a better hand.
//=========================================================================
void DealerHand::giveCard( Card c )
{
    if((c.value==1)&&(dealervalue + 11 )<=21)
    {
        dealervalue+=11;
    }
    else
    {
        dealervalue += c.value;
    }
    dealercards.push_back( c );
}

//=========================================================================
//void printCards()
//Outputs the cards in the players hand to the screen.
//=========================================================================
void DealerHand::printCards()
{
     cout << "In Dealer's Hand: " << endl;
     for(std::vector<Card>::iterator it = dealercards.begin(); it != dealercards.end(); ++it)
     {
       Card current = *it;
       cout << current.face << " of " << current.getSuit() << endl;
     }

}



