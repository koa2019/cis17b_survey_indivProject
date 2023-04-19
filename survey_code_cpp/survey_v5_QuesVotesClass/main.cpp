/* 
 * File:    main.cpp
 * Author:  Danielle F
 * Created: 04-13-23 @8PM
 * Purpose:  survey project v4
 * 
 * v1:
 * Admin inherits User
 * Added admin readBin(), wrtAdminTxt() & wrtAdminBin()
 * Fixed bug: Admin is crashing. Added a cout inside ~Admin().
 * Added 3 constructors for User. 
 * Added recSize & begnFile variables to Admin so it could  
 * hold their info when handling a binary record.
 * Admin can rewrite the value for hiScore in userData.dat when 
 * it uses findByEmail() to set records size & beginning file location.
 * Admin can rewrite one full binary record instead of just hiScoore.
 * Copied this folder to yahtzee_v15
 * Added getMenu() so I can focus on my survey.
 *  Rewrites 1 record in usrdata.txt after it rewrites binary.
 * 
 * 
 v2:
 * I copied my Admin & User classes from yahtzee_v21 to here.
 * Created string array with 1 question and 3 possible answers.
 * Created a loop to mimic 5 people answering this 1 question
 * Created counters for each question's possible answer and
   reassigned int votes[] with the the counters some answered the question.
 * Passed the questions and answers arrays to a print function.
 * Created prntChart() that displays the voting results as well as a histogram 
   with stars to represent each vote.
 * 
 * 
 v3: 
 * Moved qusAns[] and votes[] to a structure in main(). It won't work in Question.h
 * Created 1 instance of Question structure and made sure it still ran correctly.
 * Changed prntChart() to accept a structure instead of 2 difference types of arrays
 * 
 * 
 v4: 
 * Had to create Survey class and move Questions to it because i skipped a step.
 * In Questions class I made it 4 strings instead of an array of strings.
 * Questions reads its questions and possible answers from a text file.
 * In Questions getSurve() I created an array of questions, prompted User,
   and saved their answers to an instance of Votes.
 * Added Votes structure and aggregated an instance of it in Questions class.
 * In main() menu case 4 allows you to take a survey as a guest and doesn't save
 * its results to any files.
 * 
 * 
 v5:
 * Update this version with store_v1.4's User and Admin Classes.
 * Moving start() from Question.cpp to Survey.cpp
 * Survey class creates array of Question and aggregates instance
   of Votes, then rewrites hiScore in start().
 * Moved Votes class to User class public members.
  Printed votes[] in User:wrtVotes(); Created
 * 
 * 
 To Do: 
 * When User is logged in write Votes array to their record. 
 * Make readInput() read inputs from file again 
 * Add a bool variable to Admin as a flag for deleted records?
 
 * DRY. Clean up repetitive code.
 */

//System Libraries
#include <iostream>  //Input/Output Library
#include <iomanip> // setw()
#include <cstdlib> // rand()
#include <ctime>   // time()
#include <string> //string
#include <cstring> //c-strings
#include <cctype>  // toupper()
#include <fstream> // fstream
using namespace std;  //STD Name-space where Library is compiled

//User Libraries
#include "User.h"
#include "Admin.h"
#include "Survey.h"


//Global Constants not Variables
//Math/Physics/Science/Conversions/Dimensions

//Function Prototypes
void getMenu();


//Code Begins Execution Here with function main
int main(int argc, char** argv) {
    
    //Set random number seed once here
    srand(static_cast<unsigned int>(time(0)));

    int choice = 0;
    Admin admin;
    User user; 
    
    
    cout<<"\n\n\tMenu\n"
        <<"1: Admin Login\n"
        <<"2: Sign Up\n"
        <<"3: User Login\n"
        <<"4: Take Survey as a guest\n"
        <<"5: Reset binary & text files\n"
        <<"9: Exit\n"
        <<"Enter a number: ";
        cin>>choice;
        cin.ignore();
        
        switch(choice){
            
            case 1: // Admin login
            {               
                admin.adminLogin();
                break;
            } 
            case 2: // User sign up for new account
            {
               
                user.signUp();
                //cout<<"\ninside main() after signUp() object looks like: ";
                //user.printUsr();
                break;
            }
            case 3:  // User login. If successful, then play game          
            {       
                int indx = admin.isUsrLogin();
                if(!(indx == -66)){
                    
                    cout<<"\nUser login was successful.\n"; 
                    //cout<<"\ninside main() admin1 object looks like: ";
                    //admin.printAdUsr(indx);                    
                    
                    
                    // Create new User & copy admin values to user                    
                    admin.copy2Usr(user,indx);    
                    cout << "\nWelcome " << user.getName();
                    user.printUsr(); 
                    
                    // Create new instance of NewClass class
                    Survey survey;
                                 
                    long recordLoc = admin.getBegnFile(indx);
                    
                    if(recordLoc<0){ cout << "\nError finding record location\n"; break; }
                    
                    // if user is winner & has new hiScore, then print their update record
                    if(survey.start(user, recordLoc)) {                         
                        
                        //cout<<"\n\ninside main() user object looks like: ";
                        //user.printUsr();                       
                          
                        admin.readAllUsrs();
                        //cout << "\nAdmin is reading updated binary file....\n";
                        //admin.printAdUsr(user.getNumRec());   
                    }                                                    
                }
                break;
            }             
            case 4: // Play NewClass as a guest
            {          
                User guest("Guest"); 
                //cout<<"\ninside main() guest user object looks like: ";
                guest.printUsr();
                Survey survey2; // Calls default constructor
                //survey2.prntQA();
                survey2.start(guest,0); 
                break;
            }
            case 5:   // Reset files by erasing binary & text file, then creates records in 
            {        // User binary with records. Use after testing & altering records.    
                user.readInputFile(); 
                break;
            }
            default: 
            {
                cout<<"\nGood Bye.\n";                
                exit(0);
            }
        }      
    return 0;
}


//*********************************************************
//              Function Definitions
//*********************************************************

void getMenu(){
    
    int choice = 0;
    
    cout<<"\n\n\tMenu\n"
        <<"1: Admin Login\n"
        <<"2: Sign Up\n"
        <<"3: User Login\n"
        <<"4: Take Survey as a guest\n"
        <<"5: ReadInputFile()\n"
        <<"9: Exit\n"
        <<"Enter a number: ";
               
       
}