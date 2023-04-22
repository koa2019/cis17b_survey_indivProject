/* File:   Question.h
 * Author: DanYell
 * Created on April 13, 2023, 6:55 PM
*/

#ifndef QUESTION_H
#define QUESTION_H
#include <string>
#include <array>
using namespace std;

const int QSIZE = 4;

class Question {    
protected: 
    int numQA;
    string question[QSIZE]; //[question, ans1,ans2,ans3]
    
public:
    Question(); // Default Constructor
    //~Question(){ delete [] question; }  // Destructor
    
    // Mutator
    void setQIndx(int i, string str){ question[i] = str; }
    void setQA(string,string,string,string);   
    
    // Accessors
    string getQIndx(int i){ return question[i]; }
    void prnt1QA();
};
#endif /* QUESTION_H */

