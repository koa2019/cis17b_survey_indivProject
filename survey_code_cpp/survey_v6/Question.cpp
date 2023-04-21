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
    
    numQA = 3;
        
    for(int i = 0; i < QSIZE; i ++){
        question[i]  = "";        
    }
}


//*********************************************************
//
//*********************************************************
//void Question::readQAFile(){
//    
//    //cout<<"\n Hit Question::readQAFile()\n";
//    fstream in;
//    in.open("surveyQA.txt", ios::in);
//    if(in.fail()){ cout<<"\nError opening surveyQA.txt\n"; exit(0); }
//
//
//    int i = 0;
//    string str0 = "", str1 = "", str2 = "", str3 = "";
//     
//    // Reset question class object    
//    while(!in.eof()){        
//        
//        getline(in,str0);
//        getline(in,str1);
//        getline(in,str2);
//        getline(in,str3);
//
//        question[i].setQA(str0,str1,str2,str3);
//        //question[i].setQA(str0,str1,str2,str3);
//        //question[i].prntQA();
//        i++;
//    }    
//    
//    numQA = (i > numQA) ? i : numQA;
//    in.close();
//}


//*********************************************************
//              Reset each question with this string
//*********************************************************

void Question::setQA(string q, string a, string b, string c){    
    setQIndx(0,q);
    setQIndx(1,a);
    setQIndx(2,b);
    setQIndx(3,c);
}


//*********************************************************
//
//*********************************************************
void Question::prnt1QA(){    
    
    cout<< "\n\n\t" << question[0] << "?\n\t";
    
    for(int i=1; i < QSIZE; i++){
        cout << question[i] << "\n\t";
    }
    cout << "Enter a number:  ";
}
