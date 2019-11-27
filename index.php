<!DOCTYPE html>
<html>
	<head>
		<link rel="stylesheet" href="stylesheet.css">
		<title>myApp</title>
	</head>
	<body bgcolor="cyan">
		<center>
			<form action="index.php" method="post">
				<input type="text" name="content" class="inputbox"><br><br>
				<input type="submit">
			</form>
			<p>
				<?php

					$last_line=system('./test < input.txt');
					$output = file_get_contents('output.txt');
					echo $output;

				?>
			</p>
		</center>
	</body>
</html>