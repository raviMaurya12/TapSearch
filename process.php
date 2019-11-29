<html>
	<head>
		<title>Results</title>
		<meta name="viewport" content="width=device-width, initial-scale=1">
		<style>
		* {
		  box-sizing: border-box;
		}

		/* Create two equal columns that floats next to each other */
		.column {
		  float: left;
		  width: 50%;
		  padding: 10px;
		  height: 300px; /* Should be removed. Only for demonstration */
		}

		/* Clear floats after the columns */
		.row:after {
		  content: "";
		  display: table;
		  clear: both;
		}
		</style>
	</head>
	<body bgcolor="cyan">
		<?php 
			file_put_contents('input.txt', $_POST["content"]);
			$fs=fopen('input.txt','a');
			fwrite($fs,"\n\n");
			fwrite($fs,$_POST["searchInput"]);
			fclose($fs);
		?>
		<div class="row">
		  	<div class="column" style="background-color:#aaa;">
		    	<h4>Results from HashMap Implementation:</h4>
		    	<?php 
		    		$last_line1=system('./hash_implementation < input.txt',$retval1);
					$text1=nl2br(file_get_contents('output.txt'));
					echo $text1;
		    	?>
		  	</div>
		  	<div class="column" style="background-color:#bbb;">
		    	<h4>Results from Trie Implementation:</h4>
		    	<?php 
		    		$last_line2=system('./trie_implementation < input.txt',$retval2);
					$text2=nl2br(file_get_contents('output.txt'));
					echo $text2;
		    	?>
		  	</div>
		</div>
	</body>
</html>