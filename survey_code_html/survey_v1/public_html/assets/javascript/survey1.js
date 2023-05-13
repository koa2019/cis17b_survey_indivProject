//----------survey variables----------------
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

    document.getElementById("startDiv").style.visibility = "hidden";  
    document.getElementById("signUpDiv").style.visibility = "hidden";
    //document.getElementById("surveyDiv").style.visibility = "hidden";
    document.getElementById("login").addEventListener("click", startGame);
    document.getElementById("signUp1").addEventListener("click", signUp);


// ---------------function definitions----------------
    
    function startGame() {
        document.getElementById("startDiv").style.visibility = "hidden";        
        document.getElementById("surveyDiv").style.visibility = "visible";
       
    }

    function signUp(){
        document.getElementById("startDiv").style.visibility = "hidden"; 
        document.getElementById("signUpDiv").style.visibility = "visible";
    }


    // ----------quiz question functions----------------
    function tallySurvey() {

        alert("Hit tallySurvey()");
        console.log("Hit tallySurvey()");

        //var id = document.getElementById('q1').value;
        //alert("id = "+id);

    }


    function showQuizResults() {
        //document.getElementById("resultsDiv").style.visibility = "visible";
        //$('#correct').text('Correct: ' + correct);
        //$('#wrong').text('Wrong: ' + wrong);
        //$('#unanswered').text('Unanswered: ' + unanswered);
    }

    function reset() {
        //window.location.reload();
    }
};