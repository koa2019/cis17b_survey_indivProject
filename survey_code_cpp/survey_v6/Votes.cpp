#include <iostream>
#include <iomanip>
#include <array>
#include "Votes.h"
using namespace std;

//*********************************************************
//
//*********************************************************
void Votes::setVoteIndx(int i, int value){ 
    votes[i] = value; 
    increNumVote();
}


//*********************************************************
//
//*********************************************************
void Votes::setVoteArr(int a, int b, int c){
    //cout<<"\n\tHit setVotArr()\n";
    votes[0] = a;
    votes[1] = b;
    votes[2] = c;
    increNumVote();
    increNumVote();
    increNumVote();
}

 
//*********************************************************
//              Sets votes[] elements to random numbers
//*********************************************************
void Votes::setVoteArr(){
    int num = 0;
    for(int i=0; i < NUMQQ; i++){
        num = (rand()%3)+1;
        votes[i] = num;
        increNumVote();                           
    }
}


//*********************************************************
//
//*********************************************************  
void Votes::prntVotes()const{       
    for(int i=0; i < NUMQQ; i++){
        cout <<  votes[i] << " ";
    }
    cout << "]";
    //cout << setw(2)<< numVote << " total votes."; 
}

