<html>
	<body>

		<?php 

			file_put_contents('input.txt', $_POST["content"]);
			$last_line=system('./test < input.txt',$retval);
			$text=file_get_contents('output.txt');
			echo $text;
			
		?>

	</body>
</html>