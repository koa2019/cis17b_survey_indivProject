/* 
 
*/
// Votes Variables
const SIZE = 3;


// Default constructor  Called in Yahtzee.html
function User(){   
    //this.readNumRec();  
    this.numRec = 0;
    this.name="Guest";
    this.email="email@email.com";
    this.password="password";  
    this.votesSiz=SIZE;
    this.votes = new Array();
    this.votes = new Votes();

//    votes.setVoteIndx(1, 99);
//    votes.consoleVotes();
//    votes.consoleNumVotes();
//    votes.increVoteIndx(1);
//    votes.consoleVotes();
//    votes.consoleNumVotes();
    console.log("Hit User Default constructor");
}


// Constructor #2. Called in Yahtzee.js
function User(i){   
    //this.readNumRec(); 
    this.numRec = 0;
    this.name="Guest "+i;
    this.email="email@email.com";
    this.password="password"; 
    this.votesSiz=SIZE;
    
    this.votes = new Array();
    this.votes = new Votes();

//    votes.setVoteIndx(1, 99);
    this.votes.consoleVotes();
//    votes.consoleNumVotes();
//    votes.increVoteIndx(1);
//    votes.consoleVotes();
//    votes.consoleNumVotes();
    console.log("Hit User constructor #2");
}

//To String function of the ScoreCard Class
User.prototype.printUser=function(){
    console.log("numRec   = " + this.getNumRec());
    console.log("name     = " + this.getName());
    console.log("email    = " + this.getEmail());
    console.log("password = " + this.getPassword());
    console.log("votesSiz = " + this.getVotesSiz());
    this.votes.consoleVotes();
    //console.log(this.votes.callGetVote(0));
};

User.prototype.callGetVote=function(i){
    return this.votes.getVote(i);
};

//*****************************************************
//                      Mutators
//*****************************************************
User.prototype.setNumRec=function(num) { 
    this.numRec = num; 
};

User.prototype.setName=function(str){
    this.name = str;
};

User.prototype.setEmail=function(str){
    this.email = str;
};

User.prototype.setPassword=function(str){
    this.password = str;
};

User.prototype.setVotesSiz=function(s) {
    this.votesSiz = s; 
};


//*****************************************************
//                      Accessors
//*****************************************************
User.prototype.getNumRec=function(){
    return this.numRec;
};

User.prototype.getName=function(){
    return this.name;
};

User.prototype.getEmail=function(){
    return this.email;
};

User.prototype.getPassword=function(){
    return this.name;
};

User.prototype.getVotesSiz=function(){
    return this.votesSiz;
};


/******************************************************************/              
//                  REWRITE 1 RECORD TO BINARY FILE     
/*****************************************************************/

User.prototype.reWrtRecord=function(){
    console.log("Hit reWrtRecord()");
};