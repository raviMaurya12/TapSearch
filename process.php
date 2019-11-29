<html>
	<head>
		<title>Results</title>
	</head>
	<body bgcolor="cyan">
		<?php 

			file_put_contents('input.txt', implode(PHP_EOL, $_POST["content"]), FILE_APPEND);
			$fs=fopen('input.txt','a');
			fwrite($fs,$_POST["searchInput"]);
			fclose($fs);
			$last_line=system('./hash_implementation < input.txt',$retval);
			$text=nl2br(file_get_contents('output.txt'));
			echo $text;

		?>

	</body>
</html>