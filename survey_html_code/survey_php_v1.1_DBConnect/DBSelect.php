<?php

//Dr. Mark E. Lehr
//Create a connection to the database
//DB, UN, Pass, DB
//require_once ('..\..\ConnectOutOfRootLocal.php'); // Connect to the db if this file is outside of xampp>htdocs
require_once ('ConnectTest.php'); // Connect to the db locally via localhost
//Query the database
// YOU can get this query from openOffice.createQuery>editQuery>copy and paste it here. See screenshots
// OpenOffice Query for movie = "Martian"
$sql = "SELECT `entity_user`.`id_user`, "
        . "`entity_user`.`first_name`, "
        . "`entity_user`.`email`, "
        . "`entity_user`.`password`, "
        . "`entity_survey_votes`.`id_q1vote1`, "
        . "`entity_survey_votes`.`id_q2vote2`, "
        . "`entity_survey_votes`.`id_q3vote3` "
        . "FROM `test`.`enum_numbers` "
        . "AS `enum_numbers`, `test`.`entity_survey_votes` "
        . "AS `entity_survey_votes`, `test`.`xref_user_votes` "
        . "AS `xref_user_votes`, `test`.`entity_user` "
        . "AS `entity_user` "
        . "WHERE `enum_numbers`.`id_num` = `entity_survey_votes`.`id_q1vote1` "
        . "AND `enum_numbers`.`id_num` = `entity_survey_votes`.`id_q2vote2` "
        . "AND `enum_numbers`.`id_num` = `entity_survey_votes`.`id_q3vote3` "
        . "AND `entity_survey_votes`.`id_votes` = `xref_user_votes`.`id_votes` "
        . "AND `xref_user_votes`.`id_user` = `entity_user`.`id_user`";


    $result = $conn->query($sql);
    echo "<table border='1'>";
    echo "<tr><th>" . 'id' . "</th>";
    echo "<th>" . 'name' . "</th>";
    echo "<th>" . 'email' . "</th>";
    echo "<th>" . 'password' . "</th>";
    echo "<th>" . 'q1vote' . "</th>";
    echo "<th>" . 'q2vote' . "</th>";
    echo "<th>" . 'q3vote' . "</th></tr>";
    while ($re = $result->fetch_assoc()) {
        echo "<tr><td>" . $re['id_user'] . "</td>";
        echo "<td>" . $re['first_name'] . "</td>";
        echo "<td>" . $re['email'] . "</td>";
        echo "<td>" . $re['password'] . "</td>";
        echo "<td>" . $re['id_q1vote1'] . "</td>";
        echo "<td>" . $re['id_q2vote2'] . "</td>";
        echo "<td>" . $re['id_q3vote3'] . "</td></tr>";
    }
    echo "</table>";
?>