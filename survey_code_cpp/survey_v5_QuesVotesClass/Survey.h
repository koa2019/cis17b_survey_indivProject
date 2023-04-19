/* File:   Votes.h
 * Author: DanYell
 * Created on April 14, 2023, 1:30 AM
 */

#ifndef SURVEY_H
#define SURVEY_H
#include <string>
#include <array>
#include "Question.h"
#include "Votes.h"
#include "User.h"
using namespace std;

//const int NUMQQ = 3;

class Survey {
    
protected:
    
    bool isTrue;
    Question question[NUMQQ];

public:
    
    Survey(); // Default Constructor
    //~Survey(); // Destructor

    // Accessor
    bool start(User &, const long);    
    void pause(char ch='c');

};
#endif /* SURVEY_H */

