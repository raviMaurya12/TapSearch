<!DOCTYPE html>
<html>
	<head>
		<title>myApp</title>
	</head>
	<body bgcolor="cyan">
		<form action="index.php" method="post">
			<input type="text" name="name"><br>
			<input type="submit">
		</form>
		<p>
			<center>
			<?php

				$last_line=system('./test < input.txt');
				$output = file_get_contents('output.txt');
				echo $output;

			?>
			</center>
		<p>
	</body>
</html>