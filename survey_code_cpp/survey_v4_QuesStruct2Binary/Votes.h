/* File:   Votes.h
 * Author: DanYell
 * Created on April 14, 2023, 1:30 AM
*/

#ifndef VOTES_H
#define VOTES_H

class Votes {
    
//protected:
    public:
    int q1;      // Array holds how many votes each option received
    int q2;             // for this question & total sum of all votes for this question
    int q3;
    int sum;
    

    Votes(){
        q1=0;
        q2=0;
        q3=0;
        sum=0;
    }
};


#endif /* VOTES_H */

