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
    //isTrue = false;
    ques = "";
    op1  = "";
    op2  = "";
    op3  = "";
}

//*********************************************************
//                   Constructor #2
//*********************************************************
Question::Question(int numQus){ 

}


//*********************************************************
//                   Constructor #3
//*********************************************************
Question::Question(string q, string a, string b, string c){ 
    
    //cout<<"\n Hit Question Constructor #3\n";
    ques = q;
    op1  = a;
    op2  = b;
    op3  = c;    
}


//*********************************************************
//              Destructor
//*********************************************************
//Question::~Question(){
//     cout << "\n******Change Question Destructor*****\n";
//}


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
//
//*********************************************************
void Question::prnt1QA(){    
    
    cout<< "\n\n\t"
        << ques << "\n\t"
        << "1: " << op1 << "\n\t"
        << "2: " << op2 << "\n\t"
        << "3: " << op3 << "\n\t"
        <<"Enter a number:  ";
}


//*********************************************************
//
//*********************************************************

