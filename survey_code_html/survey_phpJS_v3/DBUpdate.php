<?php

//Dr. Mark E. Lehr
//Create a connection to the database
//DB, UN, Pass, DB
//require_once ('..\..\ConnectOutOfRootLocal.php'); // Move this file outside of xampp>htdocs to protect DB when remote and NOT localhost
require_once ('ConnectTest.php'); // Connect to the db locally via localhost

// Create an Object         https://www.geeksforgeeks.org/how-to-create-an-object-without-class-in-php/
$cookieObj = new stdClass();

// Added property to the object
$cookieObj->id = '1';
$cookieObj->name = 'Homer';
$cookieObj->email = 'homer@simp.com';
$cookieObj->password = 'Homer!23';
$cookieObj->vote0 = rand(0, 2);
$cookieObj->vote1 = rand(0, 2);
$cookieObj->vote2 = rand(0, 2);

// Print the object
//print_r($cookieObj);


//  Query database.  This query is from surveyDB2.odb OpenOffice Query for user_votes_4
$sql = " UPDATE `test`.`entity_user_votes` 
                 SET votes0='".$cookieObj->vote0."',votes1='".$cookieObj->vote1."', votes2='".$cookieObj->vote2."'
                  WHERE `id` = '".$cookieObj->id."' ";

//$sql = " UPDATE `test`.`entity_user_votes` 
//                 SET votes0=2,votes1=2, votes2=2
//                 WHERE `id` = '1' ";

echo $sql . "<br/>";
$result = $conn->query($sql);
?>