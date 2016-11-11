<?php

// configuration
require("../includes/config.php");

// if form was submitted
if($_SERVER["REQUEST_METHOD"] == "POST")
{
	if(empty($_POST["amount"]))
	 {
	 	apologize("You need to specify how much money you want to deposit.");
	 }
	 else
	 {
	 	$id = $_SESSION["id"];
	 	$amount = $_POST["amount"];
	 	if($amount <= 0 || !is_numeric($amount))
	 	{
	 		apologize("Not a valid amount.");
	 	}
	 	else
	 	{
		 	CS50::query("UPDATE users SET cash = cash + $amount WHERE id = $id");
		 	CS50::query("INSERT INTO history (user_id, status, price) VALUES($id, 'DEPOSIT', $amount)");
		 	render("deposit.php", ["title" => "Deposit", "amount" => $amount]);
		 }
	 }
}
else
{
  // else render form
  render("deposit_form.php", ["title" => "Deposit"]);
}


?>