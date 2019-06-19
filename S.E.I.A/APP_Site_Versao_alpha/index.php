<?php
//Iniciar Session
session_start();
if(!empty($_SESSION['login'])&&!empty($_SESSION['usucod'])&&$_SESSION['login']==1){
	?>
	<script language= "JavaScript">
		location.href="http://seiaproject.com.br/app/logar.php"
		echo "Você ja esta Logado";
		</script><?php
}
$title="Seia Project";
$home="http://www.seiaproject.com.br";
?>

<!DOCTYPE html>
<html lang="pt-Br">
<head>
<link rel="shortcut icon" href="favicon.ico">
<link href="https://fonts.googleapis.com/css?family=Oswald:300,400,700" rel="stylesheet">
<link rel="stylesheet" type="text/css" href="sty.css">
<?php if($_SESSION['login']==1){
	?> <meta HTTP-EQUIV='refresh' CONTENT='0;URL=http://seiaproject.com.br/app/carregar/index.php?pag=1'><?php
} ?>
	<meta charset="UTF-8">
	<title>Seia - Login</title>
</head>
<body>
<div class="menssage2">Bem Vindo Ao Login Do Seia Project</div>
<div id="cadastrar"><a href="http://www.seiaproject.com.br" title="Entre no Site Do Projeto">Site &raquo;</a></div>
	<div id="login" class="bradius">
		<?php

		if($_GET['erro']==1){
			?> <div class="menssage"> <?php echo "Preencha Todos os campos do login...</div>";
		}
		if($_GET['erro']==2){
			?> <div class="menssage"> <?php echo "Credencial De Acesso Invalida</div>";
		}
		if($_GET['erro']==3){
			?> <div class="menssage"> <?php echo "Você Não está Logado...</div>";
		}


		?>
		<div class="logo"><a title="<?php echo $title;?>" href="<?php echo $home;?>"><img src="logo.png" alt="" title="" width="200" height="200"></a></div>
		<div class="acomodar">
		<form action="/app/logar.php" method="post">
		<label for="usuario">Usuario:</label><input id="usuario" type="text" class="txt bradius" name="usuario">
		<label for="senha">Senha:</label><input id="senha" type="password" class="txt bradius" name="senha">
		<input type="submit" class="sb bradius" name="Entrar" value="Entrar">
		</form>
		<!--acomodar-->
		</div>
		<!--login-->
		</div>
</body>
</html>