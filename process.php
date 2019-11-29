<html>
	<head>
		<title>Results</title>
	</head>
	<body bgcolor="cyan">
		<?php 

			$para=implode(PHP_EOL, $_POST["content"]);
			$inp=implode(PHP_EOL, $_POST["searchInput"]);
			$final=$para+$inp;
			file_put_contents('input.txt', $final);
 			echo $_POST["content"];
			// $last_line=system('./hash_implementation < input.txt',$retval);
			// $text=nl2br(file_get_contents('output.txt'));
			// echo $text;

		?>

	</body>
</html>