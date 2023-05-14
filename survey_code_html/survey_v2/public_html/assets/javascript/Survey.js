/*
 * Author:      Danielle
 * Purpose:     Survey class
 */

//----------survey variables----------------
const NUMQQ = 3;
var x;
var xValue;
var correct = 0;
var wrong = 0;
var unanswered = 0;
var userInput;
var optInput; //will reference <inuput>
var optVal; //will reference optValArr[x]
var optValArr = ["a", "b", "c"]; //<input values=" " />

//questions object array. 
var questions = [{
        //1 object with 3 keys & 3 data values
        prompt: "Which series do you like the most?",
        answers: ["Star Wars", "The Simpsons", "Harry Potter"]
    },
    {
        prompt: "What is your favorite holiday?",
        answers: ["Thanksgiving", "Christmas", "Halloween"]
    },
    {
        prompt: "Which dessert is better?",
        answers: ["Apple Pie al Mode", "Red Velvet Cake", "Cheesecake"]
    }
];


window.onload = function () {

    event.preventDefault();
    main();

    function main() {
        console.log("Hit main()");
        //document.getElementById("startDiv").style.visibility = "hidden";
        document.getElementById("signUpDiv").style.visibility = "hidden";
        document.getElementById("surveyDiv").style.visibility = "hidden";
        document.getElementById("signUp1").addEventListener("click", signUp);
    }
};

// ---------------function definitions----------------


// ---------------Start survey -----------------------
//Survey.prototype.start = function (user) {
function start() {

    console.log("Hit start()");
    document.getElementById("startDiv").style.visibility = "hidden";
    document.getElementById("surveyDiv").style.visibility = "visible";
//    var survey = new Array;
//    survey = new Survey(user);
}
;


// Constructor for the Survey
function Survey(user) {

    console.log("Hit Survey() user.name: " + user.name + " votes = "+ user.votes[0]+","+ user.votes[1]+"," + user.votes[2]);
    var isComplete = this.setIsComplete(false);// survey is complete
    //document.getElementById("submitSurvey").addEventListener("click", this.tallySurvey);

}
;

// Set Survey member variable
Survey.prototype.setIsComplete = function (boolean) {
    this.isComplete = boolean;
    //console.log("this.isComplete = " + this.isComplete);
};


Survey.prototype.tallySurvey = function (user) {

    event.preventDefault();
    console.log("Hit tallySurvey()");

    var i = 0,
            ans = 0,
            count = 0;


    for (i = 0; i < NUMQQ; i++) {// Loop through total number of questions

        // Get user's answer from HTML
        var string = "q"+i;
        ans = document.getElementById(string).value;
        console.log(string + "-ans" + i + " = " + ans);
        
       
        // Reset votes object. Each indx represents their answer
        //user.votes.setVoteIndx(i, ans);
        //console.log("user.votes[ " + (i-1) + "] = " + user.votes[i-1]);
    }

    // Print this user's voting results
    //user.votes.prntVotes();

    // for (i = 0; i < NUMQQ; i++) {
//            if (user.votes.getVote(i) === 0) {//if survey not completed
//                
//                alert("Survey was not completed!");
//                console.log("Survey was not completed!");
//                isComplete = false; // set flag 
//                return isComplete;
//            }
    //}

    //isComplete = true;
    //return isComplete; // return true and Admin will confirm files were rewritten   
};



function signUp() {// Move to User.js
    document.getElementById("startDiv").style.visibility = "hidden";
    document.getElementById("signUpDiv").style.visibility = "visible";
}

//function showQuizResults() {
//document.getElementById("resultsDiv").style.visibility = "visible";
//$('#correct').text('Correct: ' + correct);
//$('#wrong').text('Wrong: ' + wrong);
//$('#unanswered').text('Unanswered: ' + unanswered);
//}

function reset() {
    //window.location.reload();
}
