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

$cod=$_GET[$ococodigo];

$sql = ("SELECT motnome,acigravidade,locx,locy,bainome,ocostatus  FROM ocorrencia inner join seia on ocoseicod=seicod inner join motorista on seimotcod=motcod  inner join ambulancia on ocoambcod=ambcod inner join acidente on ocoacicod=acicod inner join locall on ocoloccod=loccod inner join bairro on baicod=locbaicod where ococod= '$cod' ");


$dados = mysqli_query($conecta,$sql) or die(mysqli_error($conecta));

$linha = mysqli_fetch_assoc($dados);



$total = mysqli_num_rows($dados);





php?>



<!DOCTYPE html>

<html lang="pt-Br">

<head>

<link rel="shortcut icon" href="favicon.ico">

<link href="https://fonts.googleapis.com/css?family=Oswald:300,400,700" rel="stylesheet">

<link rel="stylesheet" type="text/css" href="stylle2.css">

	<meta charset="UTF-8">

	<title>S.E.I.A - Nova ocorrência</title>

</head>

<body>

	<div id="login" class="bradius">

		<div class="menssage"></div>

		<div class="acomodar">

		<form action="" method="post">
 	        <label for="Status">Status da Ocorrencia:</label><label><?php echo $linha['ocostatus']; php?></label>

		<br/>
		<label for="gravidade">Gravidade:</label><label><?php echo $linha['acigravidade']; php?></label>

		<br/>
               

                <label for="Nome">Motorista:</label><label><?php echo $linha['motnome']; php?></label>

		<br/>
           <label for="locx">Latitude:</label><label><?php echo $linha['locx']; php?></label>

		<br/>
                  <label for="locy">Longetude:</label><label><?php echo $linha['locy']; php?></label>

		<br/>

                <label for="Bairro">Bairro:</label><label ><?php echo $linha['bainome']; php?></label>
		

		

		



		</form>

		<!--acomodar-->

		</div>

		<!--ocorrencia-->

		</div>

</body>

</html>