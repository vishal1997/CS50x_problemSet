<div>
	<div id="message">
		<?php
			print("Hello, ". $cash[0]["username"] .". Your current balance is " . sprintf("%.2f",$cash[0]["cash"]).".");
		?>
	</div>
    <table class="table table-striped">
		<?php
			print("<tr>");
				print("<th class='container'>Symbol</th>");
				print("<th class='container'>Name</th>");
				print("<th class='container'>Shares</th>");
				print("<th class='container'>Price</th>");
				print("<th class='container'>Total value</th>");
			print("</tr>");
				  
			foreach ($positions as $position)
			{	  
				print("<tr>");
				print("<td class='container'>" . $position["symbol"] . "</td>");
				print("<td class='container'>" . $position["name"] . "</td>");
				print("<td class='container'>" . $position["shares"] . "</td>");
				print("<td class='container'>" . $position["price"] . "</td>");
				print("<td class='container'>" . $position["total"] . "</td>");
				print("</tr>");
			}
		?>
	</table>
</div>
