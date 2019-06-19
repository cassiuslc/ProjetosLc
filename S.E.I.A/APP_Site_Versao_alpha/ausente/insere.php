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

//UPDATA PARA CONCLUIDA
$sql = "UPDATE ocorrencia SET ocostatus = 'Em Aberto' WHERE ococod=".$_SESSION['ocorrencia']." and ocostatus!='Concluida';";
		$query = $mysqli->query($sql);
unset($_SESSION['ocorrencia']);

$funcod = $_GET["funcod"];
$ausmotivo = $_POST["motivo"];
$aushora = $_POST["datahora"];	
	
	$query = "INSERT INTO ausente (ausmotivo, aushora,ausfuncod) VALUES ('".$ausmotivo."','".$aushora."',".$funcod.")";
	mysqli_query($mysqli,$query) or die(mysqli_error($mysqli));

header("Location: http://seiaproject.com.br/app/ocorrencia.php?erro=2");


?> 
