<?php
	//Dr. Mark E. Lehr
	//Create a connection to the database
	//DB, UN, Pass, DB
        //require_once ('..\..\ConnectOutOfRootLocal.php'); // Connect to the db. if this file is outside of xampp>htdocs
        require_once ('ConnectTest.php'); // Connect to the db locally via localhost
        
	//Query the database
        $query="INSERT INTO `entity_user` (`first_name`,`last_name`,`email`,`password`) VALUES ";             
               //(`entity_user`.`first_name`, `entity_user`.`last_name`, `entity_user`.`email`, `entity_user`.`password`) VALUES ";
                
        // Created a string and appended a bunch of records to it to fill DB
        $records=10;
        for($i=1;$i<=$records;$i++){
          //$query.="(".$i.",";  
          $query.="('user".$i."',";
          $query.="'last_name".$i."',";
          $query.="'email".$i."@gmail.com',";
          $query.="'password"."!".rand(0,9).rand(1,12).rand(13,28)."')";
          //$query.=rand(0,3).","; // id_q1vote1
          //$query.=rand(0,3).","; // id_q2vote2
          //$query.=rand(0,3).")"; // id_q3vote3
          if($i!=$records){$query.=",";}
        }
        echo $query."<br/>";
        $result=$conn->query($query);
?>