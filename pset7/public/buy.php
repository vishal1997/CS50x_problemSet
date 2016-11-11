<?php

// configuration
    require("../includes/config.php");
    
    // if form was submitted 
    if($_SERVER["REQUEST_METHOD"] == "POST")
    {
    	 	if(empty($_POST["stock"]))
    	 	{
    	 		apologize("You need to specify a stock name");
    	 	}
    	 	else if(empty($_POST["shares"]) || !preg_match("/^\d+$/", $_POST["shares"]) || 
    	 								($_POST["shares"] < 0 ))
    	 	{
    	 		apologize("You need to specify no. of shares.");
    	 	}
    	 else
    	 {
    	 	$symbol = strtoupper($_POST["stock"]);
    	 	$stock = lookup($symbol);
     		if( !$stock)
     		{
     			apologize("This stock doesn't exist.");
     		}
     		else
     		{
     			$id = $_SESSION["id"];
    	 		$shares = $_POST["shares"];
    	 		$price = $stock["price"];
    	 		$cash = CS50::query("SELECT cash FROM users WHERE id = $id");
    	 		$cost = $price*$_POST["shares"];
     			if($cost > $cash[0]["cash"])
    		 	{
    		 		apologize("You don't have enough money to buy ". $shares . " shares from " . $stock["name"] . ".");
    		 	}
    		 	else
    		 	{
    		 		CS50::query("INSERT INTO portfolios (user_id, symbol, shares) VALUES($id, '$symbol', $shares) ON DUPLICATE KEY UPDATE shares = shares + $shares");
    		 		CS50::query("UPDATE users SET cash = cash - $cost WHERE id = $id");
    		 		CS50::query("INSERT INTO history (user_id, symbol, status, shares, price) VALUES($id, '$symbol', 'BUY', $shares, $price)");
    		 		render("buy.php", ["title" => "Buy", "stock" => $stock, "cost" => $cost, "shares" => $shares]);
    		 	}
    	 	}
    	 }
    } 
    else
    {
      // else render form
      render("buy_form.php", ["title" => "Buy"]);
    }


?>