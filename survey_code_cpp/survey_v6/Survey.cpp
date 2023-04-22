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
    //cout<<"\n Hit Survey Default Constructor\n";
    isTrue = false;  
    readQAFile();
}

//*********************************************************
//              Destructor
//*********************************************************
//Survey::~Survey(){
//     cout << "\n******Change Survey Destructor*****\n";
//    delete [] question;
//    //delete [] votes;
//}


//*********************************************************
//          Start survey
//*********************************************************
bool Survey::start(User &user, const long recordLoc){
         
    int ans = 0, count = 0;
    //cout<<"\n\tgetVote=" << votes.getVote(3) << endl;
    
//    readQAFile();
    
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
        //user.votes.increNumVote();  
        //cout<<"\n\t getVote=" << votes.getVote(3) << endl;
    }
    
    // Print this user's voting results
    //user.votes.prntVotes();
    //user.wrtVotes();
    
    isTrue = true; // set flag


    if(!isTrue){ // if player 1 is NOT winner
        
        cout<<"\n\nSurvey was not completed!\n"; 
        return false; 
    }
    else {       
        return isTrue; // return true and Admin will confirm files were rewritten
    }
}


//*********************************************************
//
//*********************************************************
void Survey::readQAFile(){
    
    //cout<<"\n Hit Question::readQAFile()\n";
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
}


//******************************************
//      pause screen before continuing
//******************************************
void Survey::pause(char ch) {
    
    string msg = ch=='r' ? "roll" : "continue";    
    cout<<endl<<setw(6)<<' '<<"Press enter to " << msg << ".";   
    cin.get();
}