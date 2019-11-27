<!DOCTYPE html>
<html>
<head>
	<title>Process</title>
</head>
	<body bgcolor="cyan">
		<h1>
			<center>
			<?php

				$last_line=system('./test < input.txt');
				$output = file_get_contents('output.txt');
				echo $output;

			?>
			</center>
		</h1>
		<hr>

	</body>
</html>