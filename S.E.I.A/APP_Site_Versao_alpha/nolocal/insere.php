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
$obs=$_POST['obs'];
$ambcod=$_GET['ambcod'];
//UPDATA PARA CONCLUIDA
$sql = "UPDATE ocorrencia SET ocostatus = 'Concluida',ocoobs='".$obs."', ocoambcod=".$ambcod." WHERE ococod=".$_SESSION['ocorrencia']." and ocostatus!='Concluida';";
		$query = $mysqli->query($sql);
unset($_SESSION['ocorrencia']);	

?> 
<script> 

window.setTimeout("location.href='http://seiaproject.com.br/app/ocorrencia.php?erro=1'",0)
</script>
