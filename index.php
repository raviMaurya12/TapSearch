<!DOCTYPE html>
<html>
	<head>
		<title>myApp</title>
	</head>
	<body bgcolor="cyan">
		<center>
			<form action="index.php" method="post">
				<input type="text" name="content" style="font-size:18pt;height:500px;width:1000px;"><br><br>
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