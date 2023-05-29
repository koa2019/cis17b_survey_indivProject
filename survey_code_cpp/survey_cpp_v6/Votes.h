/* File:   Votes.h
 * Author: DanYell
 * Created on April 14, 2023, 1:30 AM
*/

#ifndef VOTES_H
#define VOTES_H
#include <iostream>  // cout
#include <iomanip>  // setw()
using namespace std;

const int NUMQQ = 3;
const int VOTESIZE = NUMQQ+1;

class Votes {    

    public:
    int votes[NUMQQ]; // Array holds how many votes each option received
    int numVote;    
    
    Votes();// Default constructor
    
    // Mutators
    void setVoteIndx(int i, int value);
    void setVoteArr();            // Sets votes elements to random #'s
    void setVoteArr(int,int,int); // sets votes elements to these integers
    void increNumVote(){ numVote++; }
    void increVote(int i){ votes[i]++; }    
    
    // Accessors
    int getVote(int i) const { return votes[i]; }
    int getNumVote() const { return numVote; }  
    void prntVotes() const;
};
#endif /* VOTES_H */

