<?php 
session_start();
$usuario = "seiap290";
$senha = "70Qgq82amK";
$host = "www.seiaproject.com.br";
$banco= "seiap290_Oficial";
$mysqli = new mysqli($host, $usuario, $senha, $banco);

	if (mysqli_connect_errno()) {
    	die('Ocorreu um IGO, Não foi possível conectar-se: ' . mysqli_connect_error(). "\n");
  	  	exit();
}

$funcod = $_GET['funcod'];
//$sql = ();

$sql = "SELECT * FROM funcionarios,ambulancia,usuarios where funcod=".$funcod." and funcod=usuarios.usufuncod and usucod=ambulancia.ambusucod";

$result = $mysqli->query($sql) or trigger_error($mysqli->error." [$sql]"); 
	while($row = $result->fetch_array()) {
    $funcod=$row['funcod'];
	$funnome=$row['funnome'];	
	$ambcod=$row['ambcod'];

}
$sql = "SELECT * FROM ocorrencia,seia,motorista where ococod=".$_SESSION['ocorrencia']." and ocoseicod=seicod and seimotcod=motcod;";
$result = $mysqli->query($sql) or trigger_error($mysqli->error." [$sql]"); 
	while($row = $result->fetch_array()) {
    $ococod=$row['ococod'];
	$clinome=$row['motnome'];	

}
date_default_timezone_set("America/Manaus");
$data=date('d/m/Y');
$hora=date('h:i:s');
?>

<!DOCTYPE html>
<html lang="pt-Br">
<head>
<link rel="shortcut icon" href="favicon.ico">
<link href="https://fonts.googleapis.com/css?family=Oswald:300,400,700" rel="stylesheet">
<link rel="stylesheet" type="text/css" href="stylle3.css">
<?php if($_SESSION['login']!=1){
	?> <meta HTTP-EQUIV='refresh' CONTENT='0;URL=http://seiaproject.com.br/app/index.php?erro=3'><?php
} else { ?>

	<meta charset="UTF-8">
	<title>S.E.I.A - No Local</title>
</head>
<body>
<div id="cadastrar"><a href="http://www.seiaproject.com.br/app/ocorrencia.php" title="voltar"> Retornar</a></div>
<div class="menssage2">Rota Finalizada - Estou no local...</div>
	
	<div id="login" class="bradius" style="
    padding-left: 60px;
    height: 340px;
">

		<div class="acomodar" style="
    height: 410px;
">
		<form action="insere.php?funcod=<?php echo $funcod; ?>&&ambcod=<?php echo $ambcod; ?>" method="POST">

		<label for="Funcionario">Funcionario:</label><input id="funnome" name="funnome" value="<?php echo $funnome; ?>" type="text" class="txtt bradius" readonly="readonly" name="funnome">
		<br/>
		<label for="Motivo">OBS:</label>
		<input type="text" class="txt" id="obs" name="obs">
		<br/>
		<label for="datahora">Cliente:</label><input id="cli" name="cli" value="<?php echo $clinome; ?>" type="text" class="txtt bradius" name="aushora" readonly="readonly">
		
		
		<button class="sA bradius" type="submit" name="Salvar">Atendido</button>
		

		</form>
		
 
     <?php } ?>

</body>
</html>