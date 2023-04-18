/* File:   Question.h
 * Author: DanYell
 * Created on April 13, 2023, 6:55 PM
*/

#ifndef QUESTION_H
#define QUESTION_H
#include <string>
#include <array>
#include "Votes.h"
using namespace std;

class Question {
    
protected: 
    string ques; // question
    string op1; // answer 1 option
    string op2; // answer 2 option
    string op3; // answer 3 option
    
public:
    Question(); // Default Constructor
    Question(int); // Constructor #2
    Question(string,string,string,string); // Constructor #3
    
    // Destructor
    //~Question(){cout<<"\n Hit Question Destructor\n"; }
    
    // Mutator
    void setQA(string,string,string,string);
    void setQues(string q){ ques = q; }
    void setOp1(string a){  op1  = a; }
    void setOp2(string b){  op2  = b; }
    void setOp3(string c){  op3  = c; }
    
    // Accessors
    string getQues(){return ques;}
    string getOp1(){return op1;}
    string getOp2(){return op2;}
    string getOp3(){return op3;}
    void prntQA();
    void getSurvey();
    void prntVotes(Votes);
    //void getSurvey(Question []);
    
};




#endif /* QUESTION_H */

