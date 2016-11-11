
<div>
    <table class="table table-striped">
		<?php
			print("<tr>");
				print("<th class='container'>Transaction</th>");
				print("<th class='container'>Date/Time</th>");
				print("<th class='container'>Symbol</th>");
				print("<th class='container'>Shares</th>");
				print("<th class='container'>Price</th>");
			print("</tr>");
				  
			foreach ($history as $history)
			{	  
				print("<tr>");
				print("<td class='container'>" . $history["status"] . "</td>");
				print("<td class='container'>" . $history["date_time"] . "</td>");
				print("<td class='container'>" . $history["symbol"] . "</td>");
				print("<td class='container'>" . $history["shares"] . "</td>");
				print("<td class='container'>" . sprintf("%.2f",$history["price"]) . "</td>");
				print("</tr>");
			}
		?>
	</table>
</div>
