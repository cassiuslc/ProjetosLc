
<!DOCTYPE html>
<html>
	<head>
		<title>GEO</title>
		<script>
			function getLocation(){
			
				var saida = document.getElementById("saida");
				if( navigator.geolocation ){
					navigator.geolocation.getCurrentPosition( showSucesso , showErro);
				}else{
					saida.innerHTML = "Geolocalização não é suportado por este navegador!";
				}
			}
			
			
			function showSucesso(position){
				var saida = document.getElementById("saida");
				lat = position.coords.latitude;
				lng = position.coords.longitude;
				saida.innerHTML = "Latitude: "+lat+" - Longitude: "+lng;	
			}
			
			function showErro(erro){
				var saida = document.getElementById("saida");
				
				switch( erro.code ){
					case erro.PERMISSION_DENIED:
						saida.innerHTML = "O usuário negou o pedido de Geolocalização";
						break;
					case erro.POSITION_UNAVAILABLE:
						saida.innerHTML = "A posição não está disponível";
						break;
					case erro.TIMEOUT:
						saida.innerHTML = "O pedido para obter a localização do usuário expirou";
						break;
					case erro.UNKNOWN_ERROR:
						saida.innerHTML = "Um erro desconhecido ocorreu";
						break;
				}
				
			}
		</script>	
	</head>
	
	<body>
	
		<button onclick="getLocation()">Localizar</button>
		<div id="saida"></div>
	</body>
</html>
