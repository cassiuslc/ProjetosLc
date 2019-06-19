<?php
//Iniciar Session
session_start();
//Conexão Com Banco De Dados Remoto
$usuario = "seiap290";
$senha = "70Qgq82amK";
$host = "www.seiaproject.com.br";
$banco= "seiap290_Oficial";

$usuario=null;
$senhaOriginal=null;
$senhaCode=null;

$mysqli = new mysqli($host, $usuario, $senha, $banco);

if (mysqli_connect_errno()) {
    die('Ocorreu um IGO, Não foi possível conectar-se: ' . mysqli_connect_error(). "\n");
    exit();
}
//Credenciais De Acesso Ao Login
$usuario=$_POST['usuario'];
$senhaOriginal=$_POST['senha'];

if($_SESSION['login']==1){

		if(!empty($_SESSION['ocorrencia'])){
 ?>		<script language= "JavaScript">
		location.href="http://seiaproject.com.br/app/ocroute/oc_rota.php?ococod=<?php echo $_SESSION['ocorrencia'];?>"
		</script>
<?php } else {?>		
<script language= "JavaScript">
		location.href="http://seiaproject.com.br/app/carregar/index.php?pag=1"
		</script>
<?php }
}  else {

if(empty($_SESSION['login'])&&empty($_SESSION['usucod'])&&$_SESSION['login']!=1){

if(!empty($usuario)||!empty($senhaOriginal)){

$confusuario=null;
$confsenha=null;
$usucod=null;
// Prepara uma consulta SQL
$sql = "SELECT usucod,usulogin,ususenha FROM usuarios where usulogin='".$usuario."' and ususenha='".$senhaOriginal."' limit 1";
$result = $mysqli->query($sql) or trigger_error($mysqli->error." [$sql]"); 
while($row = $result->fetch_array()) {
$confusuario=$row['usulogin'];
$confsenha=$row['ususenha'];
$usucod=$row['usucod'];
}
if($usuario==$confusuario&&$senhaOriginal==$confsenha){
$_SESSION['login'] = 1;
$_SESSION['usucod'] = $usucod;


 ?>		
 <meta HTTP-EQUIV='refresh' CONTENT='0;URL=http://seiaproject.com.br/app/carregar/index.php?pag=1'>
<?php
} else{
	?>
		<script language= "JavaScript">
		location.href="http://seiaproject.com.br/app/index.php?erro=2"
		</script>
<?php
session_destroy(); // Destrói toda sessão
}

}else {
	?>
		<script language= "JavaScript">
		location.href="http://seiaproject.com.br/app/index.php?erro=1"
		</script>
<?php
session_destroy(); // Destrói toda sessão
}
} else {
	?>
		<script language= "JavaScript">
		location.href="http://seiaproject.com.br/app/index.php?erro=3"
		</script>
<?php
}
}
?>