<?php 



 $servername="50.116.87.155";

 $user="seiap290";

 $senha="70Qgq82amK";

 $db="seiap290_Oficial";

$conecta = new mysqli($servername,$user,$senha,$db);



if($conecta->connect_error){

    die("conexao falhou".$conecta->connect_error);

}else{

	

}



$motnome = $_GET['motnome'];  

$acigravidade= $_GET['acigravidade'];

$bainome = $_GET['bainome'];



$sql = ("SELECT motnome,acigravidade,bainome FROM ocorrencia inner join seia on ocoseicod=seicod inner join motorista on seimotcod=motcod inner join ambulancia on ocoambcod=ambcod inner join acidente on ocoacicod=acicod inner join locall on ocoloccod=loccod inner join bairro on baicod=locbaicod");



$dados = mysqli_query($conecta,$sql) or die(mysqli_error($conecta));

$linha = mysqli_fetch_assoc($dados);



$total = mysqli_num_rows($dados);





php?>



<!DOCTYPE html>

<html lang="pt-Br">

<head>

<link rel="shortcut icon" href="favicon.ico">

<link href="https://fonts.googleapis.com/css?family=Oswald:300,400,700" rel="stylesheet">

<link rel="stylesheet" type="text/css" href="style.css">

	<meta charset="UTF-8">

	<title>S.E.I.A - Nova ocorrência</title>

</head>

<body>

	<div id="login" class="bradius">

		<div class="menssage"></div>

		<div class="logo"></div>

		<div class="acomodar">

		<form action="" method="post">

		<label for="Acidente">Acidente:</label><label><?php echo $linha['acigravidade']; php?></label>

		<br/>

		<label for="Bairro">Motorista:</label><input id="bairroOcorrenciaNova"  value="<?php echo $linha['motnome']; php?>" type="text" class="txt bradius" readonly="readonly" name="bairroOcorrenciaNova">

		<br/>

		<label for="Rua">Bairro</label><input id="ruaOcorrenciaNova" value="<?php echo $linha['bainome']; php?>" type="text" class="txt bradius" readonly="readonly" name="ruaOcorrenciaNova">

		<br/>

		

	

		<button class="sb bradius" type="submit" name="voltar">Voltar</button>



		</form>

		<!--acomodar-->

		</div>

		<!--ocorrencia-->

		</div>

</body>

</html>