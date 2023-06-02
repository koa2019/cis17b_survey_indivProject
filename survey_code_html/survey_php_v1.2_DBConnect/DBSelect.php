<?php

//Dr. Mark E. Lehr
//Create a connection to the database
//DB, UN, Pass, DB
//require_once ('..\..\ConnectOutOfRootLocal.php'); // Move this file outside of xampp>htdocs to protect DB when remote and NOT localhost
require_once ('ConnectTest.php'); // Connect to the db locally via localhost

// YOU can get this query from openOffice.createQuery>editQuery>copy and paste it here. See screenshots in mySQL_openOffice>lecture>05-22-23

// Dr Lehr's DBConnect>DBSelect.php > OpenOffice Query for movie = "Martian"
//$sql = "SELECT `movie_id`, `name`, `studio`, `release_date`, `rating_id`, `duration` 
//        FROM `test`.`ml1150258_entity_movie` 
//        AS `ml1150258_entity_movie` 
//        WHERE `name` = 'Martian' AND `duration` > 1.75";

// surveyDB2.odb OpenOffice Query for user_votes_4
$sql = " SELECT `id`, 
                `first_name`, 
                `email`, 
                `password`, 
                `votes0`, `votes1`, `votes2` 
                FROM `test`.`entity_user_votes` AS `entity_user_votes`
                WHERE `id` = '1' ";

    $result = $conn->query($sql);
    echo "<table border='1'>";
    echo "<tr><th>" . 'id' . "</th>";
    echo "<th>" . 'name' . "</th>";
    echo "<th>" . 'email' . "</th>";
    echo "<th>" . 'password' . "</th>";
    echo "<th>" . 'votes0' . "</th>";
    echo "<th>" . 'votes1' . "</th>";
    echo "<th>" . 'votes2' . "</th></tr>";
    while ($re = $result->fetch_assoc()) {
        echo "<tr><td>" . $re['id'] . "</td>";
        echo "<td>" . $re['first_name'] . "</td>";
        echo "<td>" . $re['email'] . "</td>";
        echo "<td>" . $re['password'] . "</td>";
        echo "<td>" . $re['votes0'] . "</td>";
        echo "<td>" . $re['votes1'] . "</td>";
        echo "<td>" . $re['votes2'] . "</td></tr>";
    }
    echo "</table>";
?>

<!--
// surveyDB.odb OpenOffice Query for user_votes_xref_1
//$sql = "SELECT `entity_user`.`id_user`, "
//        . "`entity_user`.`first_name`, "
//        . "`entity_user`.`email`, "
//        . "`entity_user`.`password`, "
//        . "`entity_survey_votes`.`id_q1vote1`, "
//        . "`entity_survey_votes`.`id_q2vote2`, "
//        . "`entity_survey_votes`.`id_q3vote3` "
//        . "FROM `test`.`enum_numbers` "
//        . "AS `enum_numbers`, `test`.`entity_survey_votes` "
//        . "AS `entity_survey_votes`, `test`.`xref_user_votes` "
//        . "AS `xref_user_votes`, `test`.`entity_user` "
//        . "AS `entity_user` "
//        . "WHERE `enum_numbers`.`id_num` = `entity_survey_votes`.`id_q1vote1` "
//        . "AND `enum_numbers`.`id_num` = `entity_survey_votes`.`id_q2vote2` "
//        . "AND `enum_numbers`.`id_num` = `entity_survey_votes`.`id_q3vote3` "
//        . "AND `entity_survey_votes`.`id_votes` = `xref_user_votes`.`id_votes` "
//        . "AND `xref_user_votes`.`id_user` = `entity_user`.`id_user`";
-->