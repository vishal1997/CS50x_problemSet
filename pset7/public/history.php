<?php

    // configuration
    require("../includes/config.php"); 
	
	$id = $_SESSION["id"];
	$history = CS50::query("SELECT symbol, status, shares, price, date_time FROM history WHERE user_id = $id ORDER BY date_time DESC");
    // render portfolio
    render("history_form.php", ["title" => "History", "history" => $history]);

?>