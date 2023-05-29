#include "Votes.h"
using namespace std;

//*********************************************************
//                    Default Constructor
//*********************************************************
Votes::Votes(){ 
    numVote = 0;
    for(int i=0; i < NUMQQ; i++){
        votes[i] = 0;
    }
}


//*********************************************************
//                  Set index in votes array and 
//                  increase numVote by 1
//*********************************************************
void Votes::setVoteIndx(int i, int value){ 
    votes[i] = value; 
    increNumVote();
}


//*********************************************************
//              Set all elements in votes array
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
//                  Print votes array 
//*********************************************************  
void Votes::prntVotes()const{       
    for(int i=0; i < NUMQQ; i++){
        cout <<  votes[i] << " ";
    }
    cout << "]";
    //cout << setw(2)<< numVote << " total votes."; 
}

