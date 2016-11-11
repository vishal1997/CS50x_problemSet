<?php

// configuration
    require("../includes/config.php");
    
    if($_SERVER["REQUEST_METHOD"] == "POST")
    {	
    	// Check if the userinputted anything
    	if(empty($_POST["stock"]))
    	{
    		apologize("Sorry you didn't enter any stock.");
    	}
    	else
    	{
    		$id = $_SESSION["id"];
    		$stock = $_POST["stock"];
    
    	if(!$shares = CS50::query("SELECT shares FROM portfolios WHERE user_id = $id AND symbol = '$stock'"))
    	{
    		apologize("You don't have the stock");
    	}
    	else
    	{
    	 	$value = lookup("$stock");
    	 	$shares = $shares[0]["shares"];
    	 	$price = $value["price"];
    	 	$sellPrice = $shares*$price;
    	 	CS50::query("DELETE FROM portfolios WHERE user_id = $id AND symbol = '$stock'");
    	 	CS50::query("UPDATE users SET cash = cash + $sellPrice WHERE id = $id");
    	 	CS50::query("INSERT INTO history (user_id, symbol, status, shares, price) VALUES($id, '$stock', 'SELL', $shares, $price)");
    	 	render("sell.php", ["title" => "Sell", "value" => $value , "profit" => $sellPrice]);
    	 }
    	}
    }
    else
    {
      // else render form
      render("sell_form.php", ["title" => "Sell"]);
    }


?>