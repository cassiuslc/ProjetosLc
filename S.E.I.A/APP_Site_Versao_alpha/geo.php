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
      getLocation();
    </script> 
<?php
$gpsX = "<script>document.write(lat)</script>";
$gpsY = "<script>document.write(lng)</script>";
$address = $gpsX.",%20".$gpsY;

$geocode = file_get_contents('http://maps.google.com/maps/api/geocode/json?address='.$address.'&sensor=false');

$output= json_decode($geocode);

$latitude = $output->results[0]->geometry->location->lat;
$longitude = $output->results[0]->geometry->location->lng;
$bairro = $output ->results[0]->address_components[2]->long_name;
$cidade = $output ->results[0]->address_components[3]->long_name;
$rua = $output ->results[0]->address_components[1]->long_name;

echo "Rua: ".$rua."<br>";
echo "Bairro: ".$bairro."<br>";
echo "Cidade: ".$cidade."<br>";
?>  