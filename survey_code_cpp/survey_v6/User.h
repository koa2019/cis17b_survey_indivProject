/* File:   User.h
 * Author: DanYell
 * Created: 04-18-23, 12 PM
 * Purpose:  template_adminUserClass_aggregates. v1.4
*/

#ifndef USER_H
#define USER_H
#include <string> 
#include<iostream>
#include "Votes.h"
using namespace std;  //STD Name-space where Library is compiled

class User {
    
protected:
 
    int numRec;
    unsigned short namSiz;  // length of name string
    string name;            // name 
    unsigned short emaiSiz; // length of email string
    string email;           // email
    unsigned short pwrdSiz; // length of password string
    string password;        // password 
    int voteSiz;            // player's highest score
    
public:
    
    Votes votes; // Holds user's answer for each question    
    
    User();   // Default constructor
    User(int); // Constructor 2
    User(string); // Constructor #3
    User(string,string,string); // Constructor #4
    User(string,string,string,int,int,int); // Constructor #5
    User(int,string,string,string);
    //~User(){cout<<"\nHit User Destructor()."; }
    
    // Call Votes class functions
    void wrtVotes();
    
    // numRec functions
    void readNumRec();   // Read total number of records from file & set numRec
    void addNumRec(){ numRec++; } // increment total records by 1
    void setNumRec(int num) { numRec = num; }
    void wrtNumRec();    // Write the total number of records in UsrData.bin
    int  getNumRec() const { return numRec;}    
    
    // Mutators
    void setNamSiz(int size){  namSiz = size; }
    void setEmaiSiz(int size){ emaiSiz = size; }
    void setPwrdSiz(int size){ pwrdSiz = size; }
    void setName(string str){  name = str; namSiz = name.size(); }
    void setEmail(string str){ email = str; emaiSiz = email.size(); }
    void setPwrd(string str){  password = str; pwrdSiz = password.size();}
    void setVoteSiz(int s) { voteSiz = s; }    
    
    // Create new User 
    void signUp();  // Calls functions to create 1 or more profiles
    void readInputFile();  // Reads 27 records from a file    
    
    // Helper functions for validating member variables      
    bool isName();
    bool isEmail();
    bool isPwrd();
    bool isVoteSiz(int);
    bool isMinSize(string, int size = 2);
    bool isStrEqual(string, string);
    bool hasSpecialChars(string);
    bool confrmEmail(string);
    string toLowerCase(string);
    
    // Write to files
    void wrtTxt();
    void wrtBin();
    void reWrtTxt(long);  // Rewrite 1 record in User's text file
    void reWrtBin(long);  // Rewrite 1 record in User's binary file    
    
    // Accessors 
    int getVoteSiz() const {return voteSiz;}
    unsigned short getNamSiz() const {return namSiz; }
    unsigned short getEmaiSiz() const { return emaiSiz; }
    unsigned short getPwrdSiz() const {return pwrdSiz;}
    string getName() const {return name;}
    string getEmail() const {return email;}
    string getPwrd() const { return password; }   
    void printUsr() const;  // User friendly print out
    void printUsrRec() const;  // prints each string's size    
};
#endif /* USER_H */