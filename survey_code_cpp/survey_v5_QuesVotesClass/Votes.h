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
    void setVotArr(int a, int b, int c){
        //cout<<"\n\tHit setVotArr()\n";
        votes[0] = a;
        votes[1] = b;
        votes[2] = c;
    }
    void setVoteIndx(int i, int value){ votes[i] = value; } 
    int getVote(int i) const { return votes[i]; }
    int getNumVote() const { return numVote; }
    void increNumVote(){ numVote++; }
    
    
    // Mutator
    void prntVotes() const {
        cout<<"\n\tSurvey Results\n";
        cout << "\nQuestion 1: voted for #"  << votes[0];
        cout << "\nQuestion 2: voted for #"  << votes[1];
        cout << "\nQuestion 3: voted for #"  << votes[2]<<endl;
        cout<<setw(22)<<"Total votes:"<<setw(2)<< numVote <<"\n"; 
    }
};


#endif /* VOTES_H */

