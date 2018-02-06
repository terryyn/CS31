//
//  Player.cpp
//  Bunco
//
//  Created by Howard Stahl on 1/27/17.
//  Copyright © 2017 Howard Stahl. All rights reserved.
//

#include "Player.h"



namespace cs31
{
    
    Player::Player() : mDie( 6 ), mScore( 0 ), mRound( 0 )
    {
        
    }
    

    int Player::roll( int amount )
    {
		int rolledValue = 0;
		if (amount == 0) {
			mDie.roll();
			rolledValue = mDie.getValue();  // default=0
		}
		else {
			rolledValue = amount; // cheat code for testing purpose   
		}

		if (mRound == rolledValue) {      
			mScore++;
		} 
        return rolledValue;
    }
    
   
    void Player::setRound( int round )
    {
		mRound = round;
		mScore = 0;   //have to set 0 because every round will count new score

    }
    
 
    int  Player::getScore( ) const
    {
        return mScore;
    }
    
    
}