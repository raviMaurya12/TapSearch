<html>
	<head>
		<title>Results</title>
	</head>
	<body bgcolor="cyan">
		<?php 

			file_put_contents('input.txt', $_POST["content"]);
			$fs=fopen('input.txt','a');
			fwrite($fs,"\n\n");
			fwrite($fs,$_POST["searchInput"]);
			fclose($fs);
			$last_line=system('./hash_implementation < input.txt',$retval);
			$text=nl2br(file_get_contents('output.txt'));
			echo $text;

		?>

	</body>
</html>