<?php
	//Dr. Mark E. Lehr
	//Create a connection to the database
	//DB, UN, Pass, DB
        //require_once ('..\..\ConnectOutOfRootLocal.php'); // Move this file outside of xampp>htdocs to protect DB when remote and NOT localhost
        require_once ('ConnectTest.php'); // Connect to the db locally via localhost
        
	// Query the database
        // Dr Lehr's DBConnect>DBSelect.php>OpenOffice Query to
        // update any movies after 2010 by adding 1.3 hours to it
        //$sql="UPDATE `ml1150258_entity_movie` 
               // SET duration=duration+1.3
               // WHERE release_date >'2010-02-08' 
               // AND studio like '%Amblin%'";
        
        // surveyDB2.odb OpenOffice Query for user_votes_4 > selectALL
        //SELECT `id`, `first_name`, `email`, `password`, `votes0`, `votes1`, `votes2` 
        //FROM `test`.`entity_user_votes` AS `entity_user_votes`
        
        $sql = " UPDATE `test`.`entity_user_votes` 
                 SET votes0=2,votes1=2, votes2=2
                 WHERE `id` = '1' ";
        
        echo $sql."<br/>";
        $result=$conn->query($sql);
?>