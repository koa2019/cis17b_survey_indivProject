// Votes Variables
var SIZE = 3;

// Constructor #2. Called in Yahtzee.js
function User(i){   
    //this.readNumRec(); 
    this.id = i;
    this.name="Guest "+i;
    this.email="email@email.com";
    this.password="password"; 
    this.votesSize=SIZE;
    
    // Aggregate instance of Votes class in User class
    this.votes = new Array();
    this.votes = new Votes();
    this.votes.consoleVotes();
    //console.log("Hit User constructor #2");
}


//*****************************************************
//                      Mutators
//*****************************************************
            
//      REWRITE 1 Record Database     
User.prototype.reWrtRecord=function(){
    console.log("Hit reWrtRecord()");
};

User.prototype.setNumRec=function(num) { 
    this.id = num; 
};

User.prototype.setName=function(str){
    this.name = str;
};

User.prototype.setEmail=function(str){
    this.email = str;
};

User.prototype.setPwrd=function(str){
    this.password = str;
};

User.prototype.setVoteSize=function(s) {
    this.votesSize = s; 
};


//*****************************************************
//                      Accessors
//*****************************************************

//To String function of the ScoreCard Class
User.prototype.printUser=function(){
    console.log("id  = " + this.getNumRec()
    + "\nname = " + this.getName()
    + "\nemail = " + this.getEmail()
    + "\npassword = " + this.getPassword()
    + "\nvotesSize = " + this.getVotesSize());
    this.votes.consoleVotes();
};

User.prototype.getNumRec=function(){
    return this.id;
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

User.prototype.getVotesSize=function(){
    return this.votesSize;
};