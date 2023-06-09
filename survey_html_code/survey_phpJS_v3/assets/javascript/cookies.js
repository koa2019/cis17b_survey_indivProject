
//********************************************************
// This code is based off Dr. Lehr's JSON_Cookies > CookieFunctions.js
//      https://www.w3schools.com/js/js_cookies.asp
//******************************************************** 
function setCookie(cname, value, expiredays) {
    var d = new Date();
    d.setTime(d.getTime() + (expiredays * 86400)); // 86400 = 1 day
    var expires = "expires="+d.toUTCString();
    document.cookie = cname + "=" + value + ";" + expires + ";path=/";
    console.log("Hit setCookie(). cookie = " + document.cookie + "\n");
}


//********************************************************
// This code is based off Dr. Lehr's JSON_Cookies > CookieFunctions.js
//      https://www.w3schools.com/js/js_cookies.asp
//********************************************************          
function getCookie(cname) {
    console.log('Hit getCookie()');
    var name = cname + "=";
    var ca = document.cookie.split(';');
    for(var i = 0; i < ca.length; i++) {
        var c = ca[i];
        while (c.charAt(0) === ' ') {
            c = c.substring(1);
            console.log('Hit getCookie().  c.substring(1) = ' + c + "\n");
        }
        if (c.indexOf(name) === 0) {
            console.log('Hit getCookie().  c.substring(name.length, c.length) = ' + c.substring(name.length, c.length) + "\n");
            return c.substring(name.length, c.length);
        }
    }
    return "";
}



//********************************************************
// This code is based off Dr. Lehr's JSON_Cookies > CookieFunctions.js
//      https://www.w3schools.com/js/js_cookies.asp
//******************************************************** 
function checkCookie(cname) {
    var value = getCookie(cname);
    if (value !== "") {
        alert("Cookie Name = " + cname + "Value = " + value);
    } else {
        value = prompt("Please enter your cookie :"+cname+" Value", "");
        if (value !== "" && value !== null) {
            setCookie(cname, value, 365);
        }
    }
    console.log("Hit checkCookie(). cname = " + cname + ".  Value = " + value + "\n");
}



//*************************************************************************
//  Tutorialspoint's cookies        https://www.tutorialspoint.com/javascript/javascript_cookies.htm 
// Store Cookie. Set multiple cookies using multiple key = value pairs separated by comma.
//*************************************************************************
function setEmailQueryCookie() {
    
    alert('Hit setEmailQueryCookie()');
    
    if (document.loginForm.email.value === "") {
        alert("Enter your email...");
        return;
    }
    if (document.loginForm.password.value === "") {
        alert("Enter your password..");
        return;
    }

    // Set cookie Expiry date
    var now = new Date();
    now.setMonth(now.getDay()); // + 1);

    cookievalue2 = escape(document.loginForm.email.value) + ";";
    cookievalue3 = escape(document.loginForm.password.value) + ";";
    document.cookie = "email=" + cookievalue2;
    document.cookie = "password=" + cookievalue3;
    document.cookie = "expires=" + now.toUTCString() + ";";
    //console.log("Setting Cookies : " + "email=" + cookievalue2 + "password=" + cookievalue3);
    console.log("Setting Cookies : " + "email=" + cookievalue2 + "password=" + cookievalue3);
    
    
}



//*************************************************************************
//                      Tutorialspoint's cookies      
// https://www.tutorialspoint.com/javascript/javascript_cookies.htm 
//*************************************************************************
function setNewUserCookie() {
    
    alert("Hit setNewUserCookie()");
    
    if (document.signUpForm.name.value === "") {
        alert("Enter your name...");
        return;
    }
    if (document.signUpForm.email.value === "") {
        alert("Enter your email...");
        return;
    }
    if (document.signUpForm.password.value === "") {
        alert("Enter your password..");
        return;
    }

    // Set cookie Expiry date
    var now = new Date();
    now.setMonth(now.getDay()); // + 1);

    cookievalue1 = escape(document.signUpForm.name.value) + ";";
    cookievalue2 = escape(document.signUpForm.email.value) + ";";
    cookievalue3 = escape(document.signUpForm.password.value) + ";";
    document.cookie = "name=" + cookievalue1;
    document.cookie = "email=" + cookievalue2;
    document.cookie = "password=" + cookievalue3;
    document.cookie = "expires=" + now.toUTCString() + ";";
    alert("Hit setNewUserCookie(). Setting Cookies : " + "name=" + document.cookie.name + "  email=" + document.cookie.email + "password=" + document.cookie.password);

}

//*************************************************************************
//                      Tutorialspoint's cookies      
// https://www.tutorialspoint.com/javascript/javascript_cookies.htm 
// document.cookie string will keep a list of name=value pairs separated by semicolons, 
// where name is the name of a cookie and value is its string value.
// You can use strings' split() function to break a string into key and values as follows 
//*************************************************************************
function readCookie() { // get cookie and returns a object with cookie key:value pairs
    
    var allcookies = document.cookie;  
    console.log("Hit readCookie().  All Cookies : " + allcookies);

    // Get all the cookies pairs in an array
    cookiearray = allcookies.split(';');
    //console.log("All Cookies length : " + cookiearray.length + " Key:Value;\n");

    if (cookiearray.length > 0) {

        var name = [cookiearray.length - 1];
        var value = [cookiearray.length - 1]; // i dont want  to save the expiry date
        var cookieObj = {name: "", email: "", password: "", chekPass:""};


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
            }else if (i === 3){
                cookieObj.password = value[3];
            }
        }
        //console.log('Hit readCookie()'); console.log(cookieObj);
        return cookieObj;
    }
    return "";
}

//*************************************************************************
//                      Tutorialspoint's cookies      
// https://www.tutorialspoint.com/javascript/javascript_cookies.htm 
//*************************************************************************
function readAllCookies() {
               var allcookies = document.cookie;
               document.write ("All Cookies : " + allcookies );
               
               // Get all the cookies pairs in an array
               cookiearray = allcookies.split(';');
               
               // Now take key value pair out of this array
               for(var i=0; i<cookiearray.length; i++) {
                  name = cookiearray[i].split('=')[0];
                  value = cookiearray[i].split('=')[1];
                  document.write ("Key is : " + name + " and Value is : " + value);
               }
}
