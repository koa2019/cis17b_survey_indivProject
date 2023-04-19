#include <string>
#include <array>
#include <iostream> // cout
#include <fstream> // fstream
#include <iomanip> // setw()
#include "Survey.h"
#include "Question.h"
#include "Votes.h" 
using namespace std;


//*********************************************************
//              Default Constructor
//*********************************************************
Survey::Survey(){
    
    cout<<"\n Hit Survey Default Constructor\n";
    isTrue = false;
    
}

//*********************************************************
//              Destructor
//*********************************************************
//Survey::~Survey(){
//     cout << "\n******Change Survey Destructor*****\n";
//    //delete [] qusAns;
//    //delete [] votes;
//}

//*********************************************************
//          Start survey
//*********************************************************
bool Survey::start(User &user, const long recordLoc){
     
    //cout<<"\n Hit Question Constructor #2\n";
    fstream in;
    in.open("surveyQA.txt", ios::in);
    if(in.fail()){ cout<<"\nError opening surveyQA.txt\n"; exit(0); }


    int i = 0;
    string str0 = "", str1 = "", str2 = "", str3 = "";
     
    // Reset question class object    
    while(!in.eof()){        
        
        getline(in,str0);
        getline(in,str1);
        getline(in,str2);
        getline(in,str3);

        question[i].setQA(str0,str1,str2,str3);
        //question[i].prntQA();
        i++;
    }     
    in.close();

    
    int ans = 0, count = 0;
    //cout<<"\n\tgetVoteIndx=" << votes.getVoteIndx(3) << endl;
    
    // Loop through total number of questions
    for(int i=0; i < NUMQQ; i++){
        
       
        do {  // Validate user input
            
            question[i].prnt1QA(); // Ask Questions
            cin >> ans;           // Read answer
            
            if(!( ans >= 1 && ans <= 3 )) { 
                cout<<"Invalid input. Try again...\n"; 
            }
            
        } while (!( ans >= 1 && ans <= 3 ));
        
        // Reset votes object. Each indx represents their answer
        user.votes.setVoteIndx(i,ans);
        user.votes.increNumVote();   // Accumulate total votes for this user   
        //cout<<"\n\tgetVoteIndx=" << votes.getVoteIndx(3) << endl;
    }
    
    // Print this user's voting results
    user.votes.prntVotes();
    user.wrtVotes();
    
    isTrue = true; // set flag

    // Reset user's hiSCore and update binary & text file            
    user.setHiScore(NUMQQ);
    
    //cout << "\n\tNew High Score of " << user.getHiScore() << "!\n";

     if(!isTrue){ // if player 1 is NOT winner
        
        cout<<"\n\nHiScore was NOT updated!\n"; 
        return false; 
    }
    else { 
        
        // rewrite this record in binary & text files  
        //user.reWrtBin(recordLoc); 
        //cout << "\nUser is updating binary file...."; 
        return isTrue; // return true and Admin will confirm files were rewritten
    }
}

//*********************************************************
//
//*********************************************************


//*********************************************************
//
//*********************************************************

//******************************************
//      pause screen before continuing
//******************************************
void Survey::pause(char ch) {
    
    string msg = ch=='r' ? "roll" : "continue";    
    cout<<endl<<setw(6)<<' '<<"Press enter to " << msg << ".";   
    cin.get();
}