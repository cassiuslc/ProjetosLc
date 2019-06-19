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

	if($total > 0) {

		do {

			echo $linha['motnome'];
			echo $linha['acigravidade'];
			echo $linha['bainome'];


		}while($linha = mysqli_fetch_assoc($dados));

	}

mysqli_close($conecta);