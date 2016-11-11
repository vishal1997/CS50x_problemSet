<?php
    // configuration
    require("../includes/config.php"); 
    if($_SERVER["REQUEST_METHOD"]=="GET")
    {
        // else render form
        render("quote_form.php",["title"=>"QUOTE"]);
    }
    else if($_SERVER["REQUEST_METHOD"]=="POST")
    {
        
        render("quote.php",["title"=>"QUOTE"]);
    }
?>