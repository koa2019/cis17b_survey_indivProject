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
 * Changed Questions class I made it 4 strings instead of an array of strings.
 •	Question: getSurvey() reads a text file and saves it to a static array of Question objects.
•	Added Votes structure and aggregated an instance of it in Questions class.
•	getSurvey() prints one question and its three possible answers, gets the user’s input, and saves their answers to an instance of a Votes object.

 * 
 * 
 To Do: 
 
 * Make Survey class create an array of Votes, then write to files. Print chart.
 * 
 * Figure out how to pass Questions array to other functions with its cpp page.
 
 * When User is logged in write Votes array to their record.
 
 * Make getAllUsr() print outside of its function
  
 * Destroy double ptr in Yahtzee class & in Admin class?
 
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
//#include "Survey.h"
#include "Question.h"


//Global Constants not Variables
//Math/Physics/Science/Conversions/Dimensions

//Function Prototypes
void getMenu();


//Code Begins Execution Here with function main
int main(int argc, char** argv) {
    
    //Set random number seed once here
    srand(static_cast<unsigned int>(time(0)));
    //rand()%90+10;//2 digit numbers
    
    getMenu();
  
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
        cin>>choice;
        cin.ignore();
        
        switch(choice){
            case 1: // Admin login
            {
                Admin admin;
                admin.adminLogin();
                break;
            } 
            case 2: // User sign up for new account
            {
                User user1;
                user1.signUp();                 
                //user1.printUsr();
                break;
            }
            case 3:  // User login. If successful, then play game          
            {       
                Admin admin1;
                if(admin1.isUsrLogin()){
                    
                    cout<<"\n\nUser login was successful.\n"; 
                    //cout<<"\n inside main()";
                    //admin.printAdUsr();                    
                    
                    
                    // Create new User & copy admin values to user
                    User user2;
                    admin1.copy2Usr(user2);    
                    cout << "\nWelcome " << user2.getName();
                    user2.printUsr(); 
                    
                                                                     
                }
                break;
            }             
            case 4: // Play Yahtzee as a guest
            {          
                User guest("Guest"); 
                
                Question q1; // Calls default constructor
                //q1.prntQA();
                q1.getSurvey();

                //Question q2(3);
                break;
            }
            case 5: // Read inputs to fill User binary with records
            {
                User user5;
                user5.readInputFile(); 
                break;
            }
            default: 
            {
                cout<<"\nGood Bye.\n";                
                exit(0);
            }
        }
}