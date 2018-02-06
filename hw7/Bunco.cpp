//
//  Bunco.cpp
//  Bunco
//
//  Created by Howard Stahl on 1/27/17.
//  Copyright © 2017 Howard Stahl. All rights reserved.
//

#include "Bunco.h"
#include <iostream>

namespace cs31
{
    Bunco::Bunco() : mRound( 0 )
    {
        
    }
    
    std::string Bunco::display( std::string msg ) const
    {
        using namespace std;
        std::string s = mBoard.display();
        s = s + msg;
        
        if (gameIsOver())
        {
            if (determineGameOutcome() == TIEDGAME)
            {
                s = s + "\n\t\tBunco wound up tied!\n";
            }
            else if (determineGameOutcome() == HUMANWONGAME)
            {
                s = s + "\n\t\tyou won Bunco!\n";
            }
            else
            {
                s = s + "\n\t\tyou lost Bunco!\n";
            }
        }
        return( s );
    }
    
    void Bunco::setRound( int round )
    {
        mRound = round;
        mBoard.setCurrentRound( round );
        mHuman.setRound(round);
        mComputer.setRound(round);
    }
    
    int Bunco::humanPlay( int amount )
    {
        // stubbed out for now...
        int amountrolled = 0;
		amountrolled = mHuman.roll(amount);
        return amountrolled ;
    }
    
    int Bunco::computerPlay( int amount )
    {
        // stubbed out for now...
        int amountrolled = 0;
		amountrolled = mComputer.roll(amount);
        return amountrolled ;
    }
  
    Bunco::ROUNDOUTCOME Bunco::determineRoundOutcome( ) 
    {
		ROUNDOUTCOME result = ROUNDOUTCOME::NOTDECIDED;
		if (mHuman.getScore() < mComputer.getScore()) {
			result = ROUNDOUTCOME::COMPUTERWON;
			mBoard.markComputerAsWinner();
		}
		else if (mHuman.getScore() > mComputer.getScore()) {
			result = ROUNDOUTCOME::HUMANWON;
			mBoard.markHumanAsWinner();
		}
 
        
        return( result );
    }
    
    Bunco::GAMEOUTCOME  Bunco::determineGameOutcome( ) const
    {
        GAMEOUTCOME result = GAMEOUTCOME::GAMENOTOVER;
		if (mBoard.countUpComputerRoundWins() + mBoard.countUpHumanRoundWins() < 6)
			return result;   // in case call in the middle before game ends
		if (mBoard.countUpHumanRoundWins() > mBoard.countUpComputerRoundWins())
			result = GAMEOUTCOME::HUMANWONGAME;
		else if (mBoard.countUpHumanRoundWins() == mBoard.countUpComputerRoundWins())
			result = GAMEOUTCOME::TIEDGAME;
		else
			result = GAMEOUTCOME::COMPUTERWONGAME;
		return result;
    }
    
    bool Bunco::gameIsOver() const
    {
        GAMEOUTCOME result = determineGameOutcome();
        return( result != GAMENOTOVER );
    }

}