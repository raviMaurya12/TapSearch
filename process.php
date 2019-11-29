<html>
	<head>
		<title>Results</title>
	</head>
	<body bgcolor="cyan">
		<?php 

			file_put_contents('input.txt', $_POST["content"]);
			$last_line=system('./hash_implementation < input.txt',$retval);
			$text=file_get_contents('output.txt');
			echo $text;

		?>

	</body>
</html>