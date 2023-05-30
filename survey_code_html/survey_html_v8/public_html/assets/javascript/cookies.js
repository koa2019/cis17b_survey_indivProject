// https://www.tutorialspoint.com/javascript/javascript_cookies.htm 
// Store Cookie. Set multiple cookies using multiple key = value pairs separated by comma.
function writeCookie() {

    if (document.myform1.email.value === "") {
        alert("Enter your email...");
        return;
    }
    if (document.myform1.password.value === "") {
        alert("Enter your password..");
        return;
    }

    // Set cookie Expiry date
    var now = new Date();
    now.setMonth(now.getDay()); // + 1);

    cookievalue2 = escape(document.myform1.email.value) + ";";
    cookievalue3 = escape(document.myform1.password.value) + ";";
    document.cookie = "email=" + cookievalue2;
    document.cookie = "password=" + cookievalue3;
    document.cookie = "expires=" + now.toUTCString() + ";";
    console.log("Setting Cookies : " + "email=" + cookievalue2 + "password=" + cookievalue3);
}




// https://www.tutorialspoint.com/javascript/javascript_cookies.htm 
function writeNewUserCookie() {
    
    alert("Hit writeNewUserCookie()");
    
    if (document.myform.name.value === "") {
        alert("Enter your name...");
        return;
    }
    if (document.myform.email.value === "") {
        alert("Enter your email...");
        return;
    }
    if (document.myform.password.value === "") {
        alert("Enter your password..");
        return;
    }

    // Set cookie Expiry date
    var now = new Date();
    now.setMonth(now.getDay()); // + 1);

    cookievalue1 = escape(document.myform.name.value) + ";";
    cookievalue2 = escape(document.myform.email.value) + ";";
    cookievalue3 = escape(document.myform.password.value) + ";";
    document.cookie = "name=" + cookievalue1;
    document.cookie = "email=" + cookievalue2;
    document.cookie = "password=" + cookievalue3;
    document.cookie = "expires=" + now.toUTCString() + ";";
    console.log("Setting Cookies : " + "name=" + cookievalue1 + "email=" + cookievalue2 + "password=" + cookievalue3);
}

// https://www.tutorialspoint.com/javascript/javascript_cookies.htm 
// document.cookie string will keep a list of name=value pairs separated by semicolons, 
// where name is the name of a cookie and value is its string value.
// You can use strings' split() function to break a string into key and values as follows 
function readCookie() {
    
    var allcookies = document.cookie;
    //alert("Hit readCookie()");    
    //console.log("All Cookies : " + allcookies);

    // Get all the cookies pairs in an array
    cookiearray = allcookies.split(';');
    //console.log("All Cookies length : " + cookiearray.length + " Key:Value;\n");

    if (cookiearray.length > 0) {

        var name = [cookiearray.length - 1];
        var value = [cookiearray.length - 1]; // i dont want  to save the expiry date
        var cookieObj = {name: "", email: "", password: ""};


        // Now take key value pair out of this array
        for (var i = 0; i < cookiearray.length; i++) {

            name[i] = unescape(cookiearray[i].split('=')[0]);
            value[i] = unescape(cookiearray[i].split('=')[1]);

            // Set object key value pairs
            if (i === 0) {        // name
                cookieObj.name = value[0];
            } else if (i === 1) { // email
                cookieObj.email = value[1];
            } else if (i === 2) { // password   
                cookieObj.password = value[2];
            }
        }
        //console.log('Hit readCookie()'); console.log(cookieObj);
        return cookieObj;
    }
    return "";
}


//********************************************************
//          Dr. Lehr's/w3schools examples
//      https://www.w3schools.com/js/js_cookies.asp
//********************************************************          
function getCookie(c_name) {
    console.log('Hit getCookie()');
    if (document.cookie.length > 0) {
        c_start = document.cookie.indexOf(c_name + "=");
        if (c_start !== -1) {
            c_start = c_start + c_name.length + 1;
            c_end = document.cookie.indexOf(";", c_start);
            if (c_end === -1) {
                c_end = document.cookie.length;
            }
            var email = unescape(document.cookie.substring(c_start, c_end));
            var cookie = {'email': email};
            return cookie;
        }
    }
    return "";
}

// https://www.w3schools.com/js/js_cookies.asp
function setCookie(c_name, value, expiredays) {
    var exdate = new Date();
    exdate.setDate(exdate.getDate() + expiredays);
    document.cookie = c_name + "=" + escape(value) +
            ((expiredays === null) ? "" : ";expires=" + exdate.toGMTString());
}

// https://www.w3schools.com/js/js_cookies.asp
function checkCookie() {
    email = getCookie('email');
    if (email !== null && email !== "") {
    } else {
        email = prompt('Please enter your email:', "");
        if (email !== null && email !== "") {
            setCookie('username', email, 365);
            alert('Welcome ' + email + '!');
        }
    }
}