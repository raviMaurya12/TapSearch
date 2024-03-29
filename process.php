<html>
	<head>
		<title>Results</title>
		<meta name="viewport" content="width=device-width, initial-scale=1">
		<style>
		* {
		  box-sizing: border-box;
		}
		.column {
		  float: left;
		  width: 50%;
		  padding: 10px;
		  height: auto;
		}
		.row:after {
		  content: "";
		  display: table;
		  clear: both;
		}
		</style>
	</head>
	<body bgcolor="#e6e6e6">
		<?php 
			//Creating input file that will be given to the executable
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
		    		//Getting and displaying results from HashMap implementation
		    		$start1 = microtime(true);
		    		$last_line1=system('./hash_implementation < input.txt',$retval1);
					$text1=nl2br(file_get_contents('output.txt'));
					echo $text1;
					$time_elapsed_secs1 = microtime(true) - $start1;
					echo "<br>";
					echo "time taken in seconds:";
					echo $time_elapsed_secs1;
		    	?>
		  	</div>
		  	<div class="column" style="background-color:#bbb;">
		    	<h4>Results from Trie Implementation:</h4>
		    	<?php
		    		//Getting and displaying results from Trie implementation
		    		$start2 = microtime(true); 
		    		$last_line2=system('./trie_implementation < input.txt',$retval2);
					$text2=nl2br(file_get_contents('output.txt'));
					echo $text2;
					$time_elapsed_secs2 = microtime(true) - $start2;
					echo "<br>";
					echo "time taken in seconds:";
					echo $time_elapsed_secs2;
		    	?>
		  	</div>
		</div>
	</body>
</html>