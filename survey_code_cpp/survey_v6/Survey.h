/* File:   Votes.h
 * Author: DanYell
 * Created on April 14, 2023, 1:30 AM
*/

#ifndef SURVEY_H
#define SURVEY_H
#include <string>
#include <iostream> // cout
#include <fstream> // fstream
#include <iomanip> // setw()
#include "Question.h"
#include "Votes.h"
#include "User.h"
using namespace std;

class Survey {
    
protected:    
    bool isTrue;

public:
    
    Question question[NUMQQ];
    Survey(); // Default Constructor
    //~Survey(); // Destructor

    // Mutators
    bool start(User &, const long); 
    void readQAFile();
};
#endif /* SURVEY_H */

