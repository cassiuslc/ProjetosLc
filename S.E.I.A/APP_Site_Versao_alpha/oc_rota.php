<?php 
//Iniciar Session
session_start();

if($_SESSION['login']!=1){?> 

<!DOCTYPE html>
<html lang="pt-Br">
<head>
<link rel="shortcut icon" href="favicon.ico">
<link href="https://fonts.googleapis.com/css?family=Oswald:300,400,700" rel="stylesheet">
<link rel="stylesheet" type="text/css" href="stylle2">
<meta HTTP-EQUIV='refresh' CONTENT='0;URL=http://seiaproject.com.br/app/index.php?erro=3'><?php
} else { ?>  
<?php
//Conexão Com Banco De Dados Remoto
$usuario = "seiap290";
$senha = "70Qgq82amK";
$host = "www.seiaproject.com.br";
$banco= "seiap290_Oficial";

$ococod=$_GET['ococod'];
//Inicio do Codigo
$mysqli = new mysqli($host, $usuario, $senha, $banco);

if (mysqli_connect_errno()) {
    die('Ocorreu um IGO, Não foi possível conectar-se: ' . mysqli_connect_error(). "\n");
    exit();
}
//PESQUISAR PARA VER SE OCORRENCIA FOI ATENDIDA

// Prepara uma consulta SQL
$sql = "SELECT * FROM ocorrencia where ococod=".$ococod.";";
$result = $mysqli->query($sql) or trigger_error($mysqli->error." [$sql]"); 
while($row = $result->fetch_array()) {
$ocostatus=$row['ocostatus'];
}

// Prepara uma consulta SQL
$sql = "SELECT * FROM usuarios,funcionarios where usucod=".$_SESSION['usucod']." and usufuncod=funcionarios.funcod;";
$result = $mysqli->query($sql) or trigger_error($mysqli->error." [$sql]"); 
while($row = $result->fetch_array()) {
$funcod=$row['funcod'];
}

if($ocostatus!="Em Aberto" && empty($_SESSION['ocorrencia'])){ 
unset($_SESSION['ocorrencia']);
	?>
<script> 

window.setTimeout("location.href='http://seiaproject.com.br/app/ocorrencia.php?erro=4'",0);
</script>
<?php
} else {
if(empty($_SESSION['ocorrencia'])){
	$_SESSION['ocorrencia']=$_GET['ococod'];
}
//UPDATA PARA EM ANDAMENTO
$sql = "UPDATE ocorrencia SET ocostatus = 'Em Andamento' WHERE ococod=".$ococod." and ocostatus!='Concluida';";
		$query = $mysqli->query($sql);

php?>

<!DOCTYPE html>
<html lang="pt-Br">
<head>
<link rel="shortcut icon" href="favicon.ico">
<link href="https://fonts.googleapis.com/css?family=Oswald:300,400,700" rel="stylesheet">
<link rel="stylesheet" type="text/css" href="stylle2.css">


	<meta charset="UTF-8">
	<title>S.E.I.A - Em Atendimento</title>
</head>
<body>
<div id="cadastrar"><a href="http://www.seiaproject.com.br/app/ausente/ausente.php?funcod=<?php echo $funcod ?>" title="Entre no site do projeto">Problema ?</a></div>
<div class="menssage2">Em Atendimento - Ocorrencia De Codigo: <?php echo $_GET['ococod']; ?></div>
	<div id="login" class="bradius">

		<div class="acomodar" style="height: 580px;
">
		<form action="" method="post">
						
		<a href="http://seiaproject.com.br/app/ocroute/estouloc.php?ococod=<?php echo $_SESSION['ocorrencia']; ?>"><div id="botao" class="sA bradius">Estou No Local</div></a>

		</form>
		<div id="mapa" style="height: 500px;width: 600px;position: relative;overflow: hidden;right: 330px;bottom: 0px;"></div>
		<!--acomodar-->
		</div>
		
		<!--ocorrencia-->
		</div>

		<script src="js/jquery.min.js"></script>
 
        <!-- Maps API Javascript -->
<script src="http://maps.googleapis.com/maps/api/js?key=AIzaSyCxMWkWnqaRtOgdi-rEvDFQ0yfYJzuLeIs&amp;sensor=false"></script>        
        <!-- Caixa de informação -->
        <script src="js/infobox.js"></script>
		
        <!-- Agrupamento dos marcadores -->
		<script src="js/markerclusterer.js"></script>
 
        <!-- Arquivo de inicialização do mapa -->
		<script src="js/mapa.js"></script>
<?php } } ?>
</body>
</html>