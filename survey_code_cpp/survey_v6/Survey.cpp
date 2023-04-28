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
    }
    
    // Print this user's voting results
    //user.votes.prntVotes();
    
    for(int i=0; i < NUMQQ; i++){
        if(user.votes.getVote(i) == 0){ 
            isTrue = false;             // set flag 
            cout<<"\n\nSurvey was not completed!\n"; 
            return isTrue; 
        }
    }

    isTrue = true;
    return isTrue; // return true and Admin will confirm files were rewritten   
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