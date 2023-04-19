#include <iostream>
#include <iomanip>
#include <array>
#include "Votes.h"
using namespace std;

//*********************************************************
//
//*********************************************************
    
void Votes::prntVotes()const{   
    cout<<"\n\tSurvey Results\n";
    cout << "\nQuestion 1: voted for #" << votes[0];
    cout << "\nQuestion 2: voted for #"  << votes[1];
    cout << "\nQuestion 3: voted for #"  << votes[2]<<endl;
    cout<<setw(22)<<"Total votes:"<<setw(2)<< numVote <<"\n"; 
}

