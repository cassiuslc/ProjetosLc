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
} else {
    echo "Conectado com sucesso (sem igos...)<BR>";
}
//Credenciais Do SEIA
if(!empty($_GET['sc'])||!empty($_GET['cm'])){
    $seiacod=$_GET['sc'];
    $motcod=$_GET['cm'];
	echo "";
		$confseiacod=null;
		$confmotcod=null;
// Prepara uma consulta SQL
$sql = "SELECT motcod,seia.seicod FROM motorista,seia where motcod='".$motcod."' and seia.seicod='".$seiacod."' limit 1";
$result = $mysqli->query($sql) or trigger_error($mysqli->error." [$sql]"); 
while($row = $result->fetch_array()) {
$confseiacod=$row['seicod'];
$confmotcod=$row['motcod'];
}
if($seiacod==$confseiacod && $motcod==$confmotcod){

 //Algoritmo Do Sensores
$sensor1 = $_GET['s1'];//Medio
$sensor2 = $_GET['s2'];//Medio
//Ambos Grave
if($sensor1==1&&$sensor2==0){
$ultimo_valor_inserido=null;
	//Acidente com acionamento do sensor 1 Medio status 0 (Nao atendido)
	if(!empty($sensor1)||!empty($sensor2)){
		$sql_insert = "INSERT INTO acidente(acigravidade,acistatus) VALUES ('Medio','Nao Atendido')";
		$query = $mysqli->query($sql_insert);
		$ultimo_valor_inserido = mysqli_insert_id($mysqli);
		$sql = "INSERT INTO ocorrencia(ocostatus,ocos1,ocos2,ocoseicod,ocoacicod,ocoloccod,ocoambcod,ocoobs) VALUES ('Em Aberto',1,0,".$confseiacod.",".$ultimo_valor_inserido.",1,null,null);";
		$queryy = $mysqli->query($sql);
		echo "Ok, Ocorrencia Salva com sucesso [Codigo Do Acidente: ".$ultimo_valor_inserido."  | SEIA: ".$confseiacod."]";
		?>
		<script> 
document.write="Preparando...";
window.setTimeout("location.href='http://192.168.43.114'",4000)

</script>
		<?php
	}
}else if($sensor2==1&&$sensor1==0){
	//Acidente com acionamento do sensor 2 Medio
			$sql_insert = "INSERT INTO acidente(acigravidade,acistatus) VALUES ('Medio','Nao Atendido')";
		$query = $mysqli->query($sql_insert);
		$ultimo_valor_inserido = mysqli_insert_id($mysqli);
		$sql = "INSERT INTO ocorrencia(ocostatus,ocos1,ocos2,ocoseicod,ocoacicod,ocoloccod,ocoambcod,ocoobs) VALUES ('Em Aberto',0,1,".$confseiacod.",".$ultimo_valor_inserido.",1,null,null);";
		$queryy = $mysqli->query($sql);
		echo "Ok, Ocorrencia Salva com sucesso [Codigo Do Acidente: ".$ultimo_valor_inserido."  | SEIA: ".$confseiacod."]";
		?>
		<script> 
document.write="Preparando...";
window.setTimeout("location.href='http://192.168.43.114'",4000)

</script>
		<?php
} else if($sensor1==1&&$sensor2==1){
	//Acidente com acionamento do sensor 1 e 2 Grave
			$sql_insert = "INSERT INTO acidente(acigravidade,acistatus) VALUES ('Grave','Nao Atendido')";
		$query = $mysqli->query($sql_insert);
		$ultimo_valor_inserido = mysqli_insert_id($mysqli);
		$sql = "INSERT INTO ocorrencia(ocostatus,ocos1,ocos2,ocoseicod,ocoacicod,ocoloccod,ocoambcod,ocoobs) VALUES ('Em Aberto',1,1,".$confseiacod.",".$ultimo_valor_inserido.",1,null,null);";
		$queryy = $mysqli->query($sql);
		echo "Ok, Ocorrencia Salva com sucesso [Codigo Do Acidente: ".$ultimo_valor_inserido."  | SEIA: ".$confseiacod."]";
		?>
		<script> 
document.write="Preparando...";
window.setTimeout("location.href='http://192.168.43.114'",4000)

</script>
		<?php
}else {
	echo "Ocorreu um IGO...";
}

} else {
 echo "<BR> Credencial De Acesso Invalida !!!";

}
    
} else {
    echo "<BR> Voce esta sem credencial de acesso !!!";
}