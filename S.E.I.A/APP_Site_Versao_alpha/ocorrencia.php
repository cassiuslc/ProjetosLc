<?php
session_start();
 $espaco = "&nbsp&nbsp&nbsp";
?>
<?php
		//Conexão Com Banco De Dados Remoto
		$usuario = "seiap290";
		$senha = "70Qgq82amK";
		$host = "www.seiaproject.com.br";
		$banco= "seiap290_Oficial";

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

<?php 

if($_SESSION['login']!=1){
	?> <meta HTTP-EQUIV='refresh' CONTENT='0;URL=http://seiaproject.com.br/app/index.php?erro=3'><?php
} else { 

if(!empty($_SESSION['ocorrencia'])){
 ?>		<script language= "JavaScript">
		location.href="http://seiaproject.com.br/app/ocroute/oc_rota.php?ococod=<?php echo $_SESSION['ocorrencia'];?>"
		</script>
<?php } else {

$sql = "SELECT * FROM funcionarios,ambulancia,usuarios where usucod=".$_SESSION['usucod']." and funcod=usuarios.usufuncod and usucod=ambulancia.ambusucod";

$result = $mysqli->query($sql) or trigger_error($mysqli->error." [$sql]"); 
	while($row = $result->fetch_array()) {
    $funcod=$row['funcod'];
	$funnome=$row['funnome'];	
	$ambcod=$row['ambcod'];

}

?>
<?php if($_GET['reft']==1){
	?> <meta HTTP-EQUIV='refresh' CONTENT='5;URL=http://seiaproject.com.br/app/ocorrencia.php?reft=1'><?php
} ?>
	<meta charset="UTF-8">
	<title>Seia - Login</title>
</head>
<body>
<div class="menssage2"><?php if($_GET['erro']==4){ echo "Ocorrencia Selecionada Já Esta Sendo Atendida..."; } else if($_GET['erro']==2) {echo "Hum... Ok Sua Justificativa foi Salva No Sistema"; } else if($_GET['erro']==1) { echo "Ok, ".$funnome." Ocorrencia Finalizada...";} else { echo "Bem Vindo ".$funnome." a Tela De Ocorrência Do SEIA"; }?></div>
<a href="<?php if($_GET['reft']==1){ echo "http://seiaproject.com.br/app/ocorrencia.php"; } else { echo "http://seiaproject.com.br/app/ocorrencia.php?reft=1";}?>" title="Atualizar..."><div id="<?php if($_GET['reft']==1){ echo "reft"; } else { echo "reftt";} ?>"> <img src="reft.png" style="width: 30px;"></div></a>
<a href="logout.php" title="Fazer Logout..."><div id="cadastrar">Logout &raquo;</div></a>
	<div id="frase" style="
    padding-left: 250px;
    margin-top: 100px;
">Ocorrências na região:</div>
	<div id="ocorrencia" class="bradius" style="width: 400px;padding-left: 0px;padding-right: 450px;top: 10px;">
		<div class="menssage"></div>

		<div class="acomodar">

<?php
$loc=null;
$n=null;
$o=null;
$sql = "SELECT * FROM ocorrencia,acidente where ocoacicod=acidente.acicod and ocostatus='Em Aberto'";
	$result = $mysqli->query($sql) or trigger_error($mysqli->error." [$sql]"); 
	while($row = $result->fetch_array()) {
		$n++;
}

	// Prepara uma consulta SQL
	$sql = "SELECT * FROM ocorrencia,acidente where ocoacicod=acidente.acicod and ocostatus='Em Aberto'";
	$result = $mysqli->query($sql) or trigger_error($mysqli->error." [$sql]"); 
	while($row = $result->fetch_array()) {
	$ococodigo=$row['ococod'];
	$acinivel=$row['acigravidade'];
	$ocobairro="Distrito Industrial";
	$ocostatus=$row['ocostatus'];
	$ocodata=$row['ocodata'];
	$ocohora=$row['ocohora'];
	$loc=13;
	$o++;
	

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

   		<?php echo "<b>".$acinivel."</b>"; ?>
   		</td>  
			
   		<td align=center width="170px" height="60"> 

   		<?php echo "<b>Data: </b>".$ocodata; ?>
   		</td>  

   		<td align=center width="150px" height="60"> 
   		<?php echo "<b>Hora: </b>".$ocohora; ?>
   		</td> 

   		<td align=center width="150px" height="60"> 
   		<?php echo "<b>".$ocobairro."<b>"; ?>
   		</td> 

   		<td align=center width="300px" height="60"> 
   		<a style="text-decoration: none" href="nc/nova_ocorrencia.php?ococod=<?php echo $ococodigo;?>"><input style="width: 150px;" type="submit" class="sb bradius" value="Ver Ocorrencia" name="Ocorrencia"></a>
   		</td> 

   		</tr>
		</table>
		<?php
			if($n!=$o){ ?>
<hr width="700px">

		<?php	} ?>

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
		<div id="frase2" style="padding-left: 250px";>Histórico de ocorrências:</div>
		<div id="historico" class="bradius" style="width: 400px;padding-left: 0px;padding-right: 450px; top: 10px;">
		<div class="menssage"></div>

		<div class="acomodar">
		<?php
		$loc2=null;
		$s=null;
		$d=null;
		// Prepara uma consulta SQL
	$sql = "SELECT * FROM ocorrencia,acidente where ocoacicod=acidente.acicod and ocostatus='Concluida' and ocoambcod=".$ambcod.";";
	$result = $mysqli->query($sql) or trigger_error($mysqli->error." [$sql]"); 
	while($row = $result->fetch_array()) {
		$s++;
	}
	// Prepara uma consulta SQL
	$sql = "SELECT * FROM ocorrencia,acidente where ocoacicod=acidente.acicod and ocostatus='Concluida' and ocoambcod=".$ambcod.";";
	$result = $mysqli->query($sql) or trigger_error($mysqli->error." [$sql]"); 
	while($row = $result->fetch_array()) {
	$ococodigo=$row['ococod'];
	$acinivel=$row['acigravidade'];
	$ocobairro="Distrito Industrial";
	$ocostatus=$row['ocostatus'];
	$ocodata=$row['ocodata'];
	$ocohora=$row['ocohora'];
	$loc2=12;
	$d++;
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

   		<?php echo "<b>".$acinivel."</b>"; ?>
   		</td>  
			
   		<td align=center width="170px" height="60"> 

   		<?php echo "<b>Data: </b>".$ocodata; ?>
   		</td>  

   		<td align=center width="150px" height="60"> 
   		<?php echo "<b>Hora: </b>".$ocohora; ?>
   		</td> 

   		<td align=center width="150px" height="60"> 
   		<?php echo "<b>".$ocobairro."<b>"; ?>
   		</td>

   		<td align=center width="300px" height="60"> 
   		<a style="text-decoration: none" href="nc/ocorrencia_gabs.php?ococod=<?php echo $ococodigo;?>"><input style="width: 150px;" type="submit" class="sb bradius" value="Ver Ocorrencia" name="Ocorrencia"></a>
   		</td> 

   		</tr>
		</table>
		
		<?php
			if($s!=$d){ ?>
<hr width="700px">

		<?php	} ?>
<?php
	}
	if($loc2 != 12){
		?> <label for="usuario" style="width: 600px;"><img src="lampada.png" style="
    width: 25px;"><?php echo $espaco; ?>Não sei se é bom ou ruim, mas você não tem históricos de atendimento...</label><?php
}
?>
		<!--acomodar-->
		</div>
		<!--login-->
		</div >
		<?php } } ?>
</body>
</html>