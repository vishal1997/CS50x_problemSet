<?php 
    $stock = lookup($_POST["symbol"]);
    if($stock!==0)
    {
        printf("Price of a symbol of %s is $%.2f",$stock["symbol"],$stock["price"]);
    }
    else
        printf("Symbol not found");
?>

        

      