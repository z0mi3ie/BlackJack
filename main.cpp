/*
Kyle Vickers
ID: 9844-18528
CS 515
Assignment 3

main.cpp

Blackjack - Assignment 3

main.cpp: This is the driver file for a multiclass blackjack game.
The game asks the user for how many games they want to play and then
continualy loops through until all the games are played, tallying up
the final win-lose ratio.
*/


#include "cards.h"
#include "hands.h"
#include <iostream>
using namespace std;

void DealInitCards( DealerHand&, PlayerHand&, Deck& );
int Play( DealerHand&, PlayerHand&, Deck& );
int checkWin( int );
int computerTurn( DealerHand&, PlayerHand&, Deck& );

//=========================================================================
//DealInitCards( DealerHand, PlayerHand, Deck )
//This shuffles and deals the initial cards of a game. One of the dealers
//cards is shown and the player's cards are printed.
//=========================================================================

void DealInitCards( DealerHand &dealer, PlayerHand &player, Deck &deck )
{
	deck.shuffle();

	cout << "Dealing first four cards:" << endl;

	Card uncovered = deck.drawCard();
	dealer.giveCard( uncovered );
	player.giveCard( deck.drawCard() );
    dealer.giveCard( deck.drawCard() );
	player.giveCard( deck.drawCard() );

    cout << "Dealer's up card: " << endl;
    cout << uncovered.face << " of " << uncovered.getSuit() << endl;
    cout << "In Our Hand: " << endl;
    player.printCards();
    cout << endl;
}
//=========================================================================
//Play(DealerHand, PlayerHand, Deck)
//This is the driving force behind a round of blackjack. The player goes
//first, either deciding to get another card or stay. When the player is
//done the computer continues getting cards until a value of 17 is hit
//Then, if neither player has bust or got a black jack, the scores are
//tallied up and whoever has a higher hand value wins. If there is a win,
//the function returns a 1, and a 0 if no win.
//=========================================================================

int Play(DealerHand& dealer, PlayerHand& player, Deck& deck)
{
	char input;
    //===================================================
    // Players turn to draw
    //===================================================
	do
	{
		cout << "Another card?( Y for yes, N for no )";
		int returnValue, computerTurnReturn;
		cin >> input;
		if( input == 'n' )
			break;
		Card newCard = deck.drawCard();
		cout << newCard.face << " of " << newCard.getSuit() << endl;
		player.giveCard( newCard );
		if( player.total() == 21 )
		{
			cout << "WIN! You got blackjack" << endl;
			dealer.printCards();
			player.clear();
			dealer.clear();
			return 1;
		}
		else if( player.total() > 21 )
		{
			cout << "We bust" << endl;
			dealer.printCards();
			player.clear();
			dealer.clear();
			return 0;
		}
	}while(input == 'y');

    cout << endl;
    cout << "Dealer draws more cards now" << endl;

    //===================================================
    // Dealer's turn to draw
    //===================================================

		while( dealer.total() <= 17 )
		{

			Card drawnCard = deck.drawCard();
			dealer.giveCard( drawnCard );
			if( dealer.total() == 21 )
			{
				cout << "LOSS! Dealer got blackjack"  << endl;
				dealer.printCards();
				player.clear();
				dealer.clear();
				return 0;
			}
			else if( dealer.total() > 21 )
			{
				cout << "Dealer bust. You win." << endl;
				dealer.printCards();
				player.clear();
				dealer.clear();

				return 1;
			}
		}


    //===================================================
    // Tally up values and return winner
    //===================================================
	if( player.total() > dealer.total() )
	{
		cout << "WIN! You have more in hand." << endl;
		    dealer.printCards();
			player.clear();
			dealer.clear();
		return 1;
	}
	else if( dealer.total() > player.total() )
	{
		    cout << "LOSS! Dealer has more in hand." << endl;
            dealer.printCards();
			player.clear();
			dealer.clear();
		return 0;
	}
	else if(  ( dealer.total() == player.total() ) && dealer.total() != 0 )
	{
            dealer.printCards();
			player.clear();
			dealer.clear();
            cout << "It was a tie!" << endl;
		    return 0;
	}
}

//=========================================================================
//main()
//This method was supplied to us. It plays the user specified amount of
//rounds and returns the win ratio at the end.
//=========================================================================

	int main()
	{
		Deck d;
		DealerHand dealerHand;
		PlayerHand ourHand;
		int numGames, numWins;
		cout << "How many games?";
		cin >> numGames;
		numWins = 0;
		for ( int i=0; i<numGames; i++)
		{
			cout << "*******************" << endl
			<< "** Game Start **" << endl
			<< "*******************" << endl ;
			DealInitCards(dealerHand, ourHand, d);
			if( dealerHand.total() == 21 )
				cout <<"LOSS! Dealer got blackjack." << endl;
			else if ( ourHand.total() == 21 )
			{
				numWins++;
				cout << "WIN! We got blackjack." << endl;
			}
			else
			{
				numWins += Play(dealerHand, ourHand, d);
			}
			cout << "*******************" << endl
			<< "** Game Over **" << endl
			<< "*******************" << endl << endl ;
		}
			cout << "We won " << numWins << " out of " << numGames << endl;
}

