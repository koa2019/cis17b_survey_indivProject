#include <string>
#include <array>
#include <iostream> // cout
#include <fstream> // fstream
#include <iomanip> // setw()
#include "Question.h"
#include "Votes.h"
#include "User.h"
using namespace std;


//*********************************************************
//              Default Constructor
//*********************************************************
Question::Question(){
    
    //cout<<"\n Hit Question Default Constructor\n";
    isTrue = false;
    ques = "";
    op1  = "";
    op2  = "";
    op3  = "";
}

//*********************************************************
//                   Constructor #2
//*********************************************************
Question::Question(int numQus){ 
    // isTrue = false;
//    //cout<<"\n Hit Question Constructor #2\n";
//    fstream in;
//    in.open("surveyQA.txt", ios::in);
//    if(in.fail()){ cout<<"\nError opening surveyQA.txt\n"; exit(0); }
//
//    //int numQus = 2;
//    int cnt;
//    string str0, str1, str2, str3;
//    Question q3[numQus]; // Calls default constructor    
//        
//    while(!in.eof()){
//
//        cnt = 0;
//        getline(in,str0);
//        getline(in,str1);
//        getline(in,str2);
//        getline(in,str3);
//
//        q3[cnt].setQA(str0,str1,str2,str3); 
//        q3[cnt].getSurvey(); 
//        cnt++;
//    }     
//    in.close();
    
    //getSurvey(&q3);
}


//*********************************************************
//                   Constructor #3
//*********************************************************
Question::Question(string q, string a, string b, string c){ 
    
    //cout<<"\n Hit Question Constructor #3\n";
    isTrue = false;
    ques = q;
    op1  = a;
    op2  = b;
    op3  = c;    
}


//*********************************************************
//              Destructor
//*********************************************************
Question::~Question(){
     cout << "\n******Change Question Destructor*****\n";
}


//*********************************************************
//              Reset each question with this string
//*********************************************************

void Question::setQA(string q, string a, string b, string c){
    setQues(q);
    setOp1(a);
    setOp2(b);
    setOp3(c);
}


//*********************************************************
//          Start survey
//*********************************************************
bool Question::start(User &user, const long recordLoc){
     
    //cout<<"\n Hit Question Constructor #2\n";
    fstream in;
    in.open("surveyQA.txt", ios::in);
    if(in.fail()){ cout<<"\nError opening surveyQA.txt\n"; exit(0); }

    int numQus = 3;
    int cnt=0;
    string str0, str1, str2, str3;
    
    Question q3[numQus]; // Calls default constructor    
        
    while(!in.eof()){

        getline(in,str0);
        getline(in,str1);
        getline(in,str2);
        getline(in,str3);

        q3[cnt].setQA(str0,str1,str2,str3);
        //q3[cnt].prntQA();
        cnt++;
    }     
    in.close();
 
    numQus = cnt > numQus ? cnt : numQus;
    
    int ans = 0, count = 0;
    
    Votes votes;
    
    // Loop through total number of questions
    for(int i=0; i < numQus; i++){
        
        // Validate user input
        do {            
            q3[i].prntQA(); // Ask Questions
            cin >> ans;     // Read answer
            
            if(!( ans >= 1 && ans <= 3 )) { 
                cout<<"Invalid input. Try again...\n"; 
            }
            
        } while (!( ans >= 1 && ans <= 3 ));
        
        // Reset votes object. Each indx represents their answer
        if(i==0){votes.q1 = ans; }
        else if(i==1){ votes.q2 = ans; }
        else if(i==2){ votes.q3 = ans; }
        votes.totalVotes +=1;   // Accumlate total votes for this user           
    }
    
    // Print this user's voting results
    prntVotes(votes);
    
     int randNum = (rand()%(0+101));             // random number between 0-100
              
        
    isTrue = true; // set flag

    // Reset user's hiSCore and update binary & text file            
    user.setHiScore(randNum);
    
    cout << "\n\tNew High Score of " << user.getHiScore() << "!\n";

     if(!isTrue){ // if player 1 is NOT winner
        
        cout<<"\n\nHiScore was NOT updated!\n"; 
        return false; 
    }
    else { 
        
        // rewrite this record in binary & text files  
        user.reWrtBin(recordLoc); 
        cout << "\nUser is updating binary file...."; 
        return isTrue; // return true and Admin will confirm files were rewritten
    }
}


////*********************************************************
////
////*********************************************************
////void prntChart(Question &q){
void Question::prntVotes(Votes votes){    
  
    cout<<"\n\tSurvey Results\n";
    cout << "\nQuestion 1: Voted for option " << votes.q1;
    cout << "\nQuestion 2: Voted for option "  << votes.q2;
    cout << "\nQuestion 3: Voted for option "  << votes.q3<<endl;
    cout<<setw(28)<<"Total votes:"<<setw(2)<< votes.totalVotes <<"\n"; 
}


//*********************************************************
//
//*********************************************************
//void prntChart(Question &q){
void Question::prntQA(){    
    
    cout<<endl
        << ques << "\n"
        << "1: " << op1 << "\n"
        << "2: " << op2 << "\n"
        << "3: " << op3 << "\n"
        <<"Enter a number:  ";

}


//*********************************************************
//
//*********************************************************


//******************************************
//      pause screen before continuing
//******************************************
void Question::pause(char ch) {
    
    string msg = ch=='r' ? "roll" : "continue";    
    cout<<endl<<setw(6)<<' '<<"Press enter to " << msg << ".";   
    cin.get();
}