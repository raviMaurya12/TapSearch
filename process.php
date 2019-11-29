<html>
	<head>
		<title>Results</title>
	</head>
	<body bgcolor="cyan">
		<?php 

			file_put_contents('input.txt', implode(PHP_EOL, $_POST["content"]), FILE_APPEND);
 			$myfile = file_put_contents('input.txt', $_POST["searchInput"].PHP_EOL , FILE_APPEND | LOCK_EX);
			$last_line=system('./hash_implementation < input.txt',$retval);
			$text=nl2br(file_get_contents('output.txt'));
			echo $text;

		?>

	</body>
</html>