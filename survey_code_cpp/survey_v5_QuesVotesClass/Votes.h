/* File:   Votes.h
 * Author: DanYell
 * Created on April 14, 2023, 1:30 AM
*/

#ifndef VOTES_H
#define VOTES_H
#include <iostream>
using namespace std;


const int NUMQQ = 3;
const int VOTESIZE = NUMQQ+1;

class Votes {
    
//protected:
    public:
    int votes[NUMQQ]; // Array holds how many votes each option received
    int numVote;
    
        // Default constructor
    Votes(){ 
        numVote = 0;
        for(int i=0; i < NUMQQ; i++){
            votes[i] = 0;
        }
    }
    
    // Accessors
    void setVoteIndx(int i, int value){ 
        
        votes[i] = value; 
    }
    
    //int getVoteIndx() const { return votes[i]; }
    int getVoteIndx(int i) const { return votes[i]; }
    int getNumVote() const { return numVote; }
    void increNumVote(){ numVote++; }
    
    // Mutator
    void prntVotes()const;
};


#endif /* VOTES_H */

