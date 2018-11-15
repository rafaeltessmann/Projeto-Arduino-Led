<!DOCTYPE html>
<html>
<head>
	<title>Arduino</title>
</head>
<body align="center">
	<h1>Controle</h1>
	<form action = "arduino.php" method = "post">
        <p>
			<?php
			if(!isset($_GET['led1'])){?>
        	<button type="submit" name="led" value="led1on">Liga Led 1</button>
        	<button type="submit" name="led" value="led1off">Desliga Led 1</button><br><br>
			<?php } ?>


			<?php
if(isset($_GET['led1'])){
	if($_GET['led1']==0){?>
		<button type="submit" name="led" value="led1on">Liga Led 1</button>
	<?php }else{?>
<button type="submit" name="led" value="led1off">Desliga Led 1</button><br><br>
	<?php }
 } ?>

        	<button type="submit" name="led" value="led2on">Liga Led 2</button>
        	<button type="submit" name="led" value="led2off">Desliga Led 2</button><br><br>

        	<button type="submit" name="led" value="led3on">Liga Led 3</button>
			<button type="submit" name="led" value="led3off">Desliga Led 3</button><br>
			
        </p>
	</form>
	
	<?php
		echo "teste";
	?>

    
</body>
</html>