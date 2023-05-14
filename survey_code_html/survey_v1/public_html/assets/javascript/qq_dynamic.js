window.onload = function () {
    
    startGame();

    // ----------function definitions----------------
    function startGame() {
        showQuestions();
    }
     
    function showQuestions() {
        alert("Hit showQuestions()");
        var radio;
        for (var x = 0; x < questions.length; x++) {

            var divQQ = document.getElementById("questions-container");
            var h2 = document.createElement('h2');
            h2.innerHTML = questions[x].prompt; //declare variable, writes prompt[x] in header2 tag & assigns it to variable                       
            var answers = questions[x].answers; //assigns the array of answers of questions[x] to varaible
            // var availableOptions = questions[x].answers; 
            console.log(h2);
            console.log(answers);
            var a = answers[0],
                    b = answers[1],
                    c = answers[2];
            var radio1, radio2, radio3;
            var label1, label2, label3;
            radio1 = makeRadio(a, x, 'a');
            radio2 = makeRadio(b, x, 'b');
            radio3 = makeRadio(c, x, 'c');
            label1 = makeLabel(a, x, 'a');
            label2 = makeLabel(b, x, 'b');
            label3 = makeLabel(c, x, 'c');

            // append nodes to HTML by appending variable data value to div id  
            divQQ.append(h2);
            divQQ.append(radio1);
            divQQ.append(label1);
            divQQ.append(radio2);
            divQQ.append(label2);
            divQQ.append(radio3);
            divQQ.append(label3);

        }
    }

    function showQuizResults() {
//        $('#correct').text('Correct: ' + correct);
//        $('#wrong').text('Wrong: ' + wrong);
//        $('#unanswered').text('Unanswered: ' + unanswered);
    }

    // ----------Survey display radio button functions----------------
    function makeRadio(val, qIndex, opt) {

        //var option = "<input type='radio' onclick='tallySurvey' value='"+val+"' id='q"+qIndex+"' qIndex='"+qIndex+"'/>";
        var option = document.createElement('input');
        option.setAttribute('type', 'radio');
        option.setAttribute('id', 'q' + qIndex + opt);
        option.setAttribute('onclick', tallySurvey());
        option.setAttribute('qIndex', qIndex);
        option.setAttribute('val', val);
        return option;
    }

    function makeLabel(val, qIndex, opt) { //create label html element
        var label = document.createElement('label');
        label.setAttribute('for', "q" + qIndex + opt);
        label.setAttribute('val', val);
        label.innerHTML = val;
        return label;
    }

    
};