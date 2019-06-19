<?php
session_start();
 ?>		<script language= "JavaScript">
		location.href="http://seiaproject.com.br/app/"
		</script>
<?php
 $espaco = "&nbsp&nbsp&nbsp";
?>
<?php
		//Conexão Com Banco De Dados Remoto
		$usuario = "seiap290";
		$senha = "70Qgq82amK";
		$host = "www.seiaproject.com.br";
		$banco= "seiap290_projeto";

		$mysqli = new mysqli($host, $usuario, $senha, $banco);

	if (mysqli_connect_errno()) {
    	die('Ocorreu um IGO, Não foi possível conectar-se: ' . mysqli_connect_error(). "\n");
  	  	exit();
	}
?>
<!DOCTYPE html>
<html lang="pt-Br">
<head>
<link rel="shortcut icon" href="favicon.ico">
<link href="https://fonts.googleapis.com/css?family=Oswald:300,400,700" rel="stylesheet">
<link rel="stylesheet" type="text/css" href="stylle3.css">
<meta HTTP-EQUIV='refresh' CONTENT='5;URL=http://seiaproject.com.br/app/ocorrencia.php'>
	<meta charset="UTF-8">
	<title>Seia - Login</title>
</head>
<body>
	<div id="frase" style="
    padding-left: 250px;
    margin-top: 100px;
">Ocorrências na região:</div>
	<div id="ocorrencia" class="bradius" style="width: 400px;padding-left: 0px;padding-right: 450px;top: 10px;">
		<div class="menssage"></div>

		<div class="acomodar">

<?php
$loc=null;
	// Prepara uma consulta SQL
	$sql = "SELECT * FROM ocorrencia,acidente where ocoacicod=acidente.acicod and ocostatus='Em Aberto'";
	$result = $mysqli->query($sql) or trigger_error($mysqli->error." [$sql]"); 
	while($row = $result->fetch_array()) {
	$ococodigo=$row['ococod'];
	$acinivel=$row['acigravidade'];
	$ocobairro="Manaus-AM";
	$ocostatus=$row['ocostatus'];
	$loc=13;
?>
<!--Tabela-->
		<table border=0 cellspacing=0 cellpadding=2 bordercolor="f1f1f1" style="" width="700px">

   		<tr><td align=center width="150px" height="60">
   		<?php if($acinivel=="Grave"){ ?>
   		<img src="grave.png" style="width: 50px;">
   <?php } ?>

   <?php if($acinivel=="Medio"){ ?>
   		<img src="medio.png" style="width: 50px;">
   <?php } ?>
   		</td> 

   		<td align=center width="170px" height="60"> 

   		Acidente: <?php echo $acinivel; ?>
   		</td>  

   		<td align=center width="150px" height="60"> 
   		<?php echo $ocobairro; ?>
   		</td> 

   		<td align=center width="150px" height="60"> 
   		<?php echo $ocostatus; ?>
   		</td> 

   		<td align=center width="300px" height="60"> 
   		<a style="text-decoration: none" href="verocorrencia.php?ococod=<?php echo $ococodigo;?>"><input style="width: 150px;" type="submit" class="sb bradius" value="Ver Ocorrencia" name="Ocorrencia"></a>
   		</td> 

   		</tr>
		</table>
		<hr width="700px">
<?php
	}

?>
<?php
	if($loc != 13){
		?> <label for="usuario" style="width: 600px;"><img src="n11.gif" style="
    width: 15px;"><?php echo $espaco; ?>Procurando ocorrência na região...</label><?php
}
?>
		<!--acomodar-->
		</div>
		<!--login-->
		</div>
		<div id="frase2" style="padding-left: 250px";>Histórico de ocorrências</div>
		<div id="historico" class="bradius" style="width: 400px;padding-left: 0px;padding-right: 450px; top: 10px;">
		<div class="menssage"></div>

		<div class="acomodar">
		<?php
		$loc2=null;
	// Prepara uma consulta SQL
	$sql = "SELECT * FROM ocorrencia,acidente where ocoacicod=acidente.acicod and ocostatus='Concluida'";
	$result = $mysqli->query($sql) or trigger_error($mysqli->error." [$sql]"); 
	while($row = $result->fetch_array()) {
	$ococodigo=$row['ococod'];
	$acinivel=$row['acigravidade'];
	$ocobairro="Manaus-AM";
	$ocostatus=$row['ocostatus'];
	$loc2=12;
?>
<!--Tabela-->
		<table border=0 cellspacing=0 cellpadding=2 bordercolor="f1f1f1" style="" width="700px">

   		<tr><td align=center width="150px" height="60">
   		<?php if($acinivel=="Grave"){ ?>
   		<img src="grave.png" style="width: 50px;">
   <?php } ?>

   <?php if($acinivel=="Medio"){ ?>
   		<img src="medio.png" style="width: 50px;">
   <?php } ?>
   		</td> 

   		<td align=center width="170px" height="60"> 

   		Acidente: <?php echo $acinivel; ?>
   		</td>  

   		<td align=center width="150px" height="60"> 
   		<?php echo $ocobairro; ?>
   		</td> 

   		<td align=center width="150px" height="60"> 
   		<?php echo $ocostatus; ?>
   		</td> 

   		<td align=center width="300px" height="60"> 
   		<a style="text-decoration: none" href="verocorrencia.php?ococod=<?php echo $ococodigo;?>"><input style="width: 150px;" type="submit" class="sb bradius" value="Ver Ocorrencia" name="Ocorrencia"></a>
   		</td> 

   		</tr>
		</table>
		<hr width="700px">
<?php
	}
	if($loc2 != 12){
		?> <label for="usuario" style="width: 600px;"><img src="lampada.png" style="
    width: 25px;"><?php echo $espaco; ?>Não sei se é bom ou ruim, mas você não tem históricos...</label><?php
}
?>
		<!--acomodar-->
		</div>
		<!--login-->
		</div>
</body>
</html>