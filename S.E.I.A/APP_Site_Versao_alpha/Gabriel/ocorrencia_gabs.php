<?php 

$usuario = "seiap290";
$senha = "70Qgq82amK";
$host = "www.seiaproject.com.br";
$banco= "seiap290_Oficial";
$mysqli = new mysqli($host, $usuario, $senha, $banco);

	if (mysqli_connect_errno()) {
    	die('Ocorreu um IGO, Não foi possível conectar-se: ' . mysqli_connect_error(). "\n");
  	  	exit();
}

//$ococod = $_GET['ococod'];
//$sql = ();

//$sql = ("SELECT * FROM ocorrencia,acidente,motorista,seia where ococod=".$ococod." and ocoacicod=acidente.acicod and ocoseicod=seicod and seimotcod=motcod;");

/*$result = $mysqli->query($sql) or trigger_error($mysqli->error." [$sql]"); 
	while($row = $result->fetch_array()) {
	$ococodigo=$row['ococod'];
	$acinivel=$row['acigravidade'];
	$motnome=$row['motnome'];
	$ocobairro="Av. Gov. Danilo de Matos Areosa, 381 - Distrito Industrial";
	$ocostatus=$row['ocostatus'];*/

//}

php?>

<!DOCTYPE html>
<html lang="pt-Br">
<head>
<link rel="shortcut icon" href="favicon.ico">
<link href="https://fonts.googleapis.com/css?family=Oswald:300,400,700" rel="stylesheet">
<link rel="stylesheet" type="text/css" href="stylle2.css">
<link rel="stylesheet" type="text/css" href="estilo.css">


	<meta charset="UTF-8">
	<title>S.E.I.A - Nova ocorrência</title>
</head>
<body>
<div id="cadastrar"><a href="http://www.seiaproject.com.br/app/ocorrencia.php" title="Entre no Site Do Projeto">Ocorrencia &raquo;</a></div>
<div class="menssage2">Deseja Atender Essa Ocorrencia ?</div>
	<div id="login" class="bradius">

		<div class="acomodar" style="
    height: 410px;
">
		<form action="" method="post">
		<input type="hidden" value=""/>
		<label for="Acidente">Acidente:</label><input id="acidenteoOcorrenciaNova" value="" type="text" class="txt bradius" readonly="readonly" name="bairroOcorrenciaNova">
		<br/>
		<label for="Bairro">Motorista:</label><input id="bairroOcorrenciaNova"  value="" type="text" class="txt bradius" readonly="readonly" name="bairroOcorrenciaNova">
		<br/>
		<label for="Rua">Bairro</label><input id="ruaOcorrenciaNova" value="" type="text" class="txt bradius" readonly="readonly" name="ruaOcorrenciaNova">
		<br/>
		
		</form>
		<div id="mapa"style="height: 350px;width: 350px;position: relative;overflow: hidden;right: 380px;bottom: 400px;"></div>
		<!--acomodar-->
		</div>
		
		<!--ocorrencia-->
		</div>
		<div id="mapa" style="height: 200px;width: 200px;position: relative;overflow: hidden;right: 300px;bottom: 400px;"></div>

		<script src="js/jquery.min.js"></script>
 
        <!-- Maps API Javascript -->
<script src="http://maps.googleapis.com/maps/api/js?key=AIzaSyCxMWkWnqaRtOgdi-rEvDFQ0yfYJzuLeIs&amp;sensor=false"></script>        
        <!-- Caixa de informação -->
        <script src="js/infobox.js"></script>
		
        <!-- Agrupamento dos marcadores -->
		<script src="js/markerclusterer.js"></script>
 
        <!-- Arquivo de inicialização do mapa -->
		<script src="js/mapa.js"></script>

</body>
</html>