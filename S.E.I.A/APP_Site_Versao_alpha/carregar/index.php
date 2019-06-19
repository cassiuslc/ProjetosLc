<!DOCTYPE html>
<html >
<head>
  <meta charset="UTF-8">
  <title>Seia Carregando...</title>
  
  
  <?php
$pag=$_GET['pag'];
if($pag==1){ ?>
<meta HTTP-EQUIV='refresh' CONTENT='2;URL=http://seiaproject.com.br/app/ocorrencia.php'>
<?php } ?>
<?php
if($pag==2){ ?>
<meta HTTP-EQUIV='refresh' CONTENT='2;URL=http://seiaproject.com.br/app/'>
<?php } ?>
      <link rel="stylesheet" href="css/style.css">
      <link rel="shortcut icon" href="favicon.ico">
  
</head>

<body>
          <main>
            <div class="container">
                <input type="radio" class="radio" id="radio-1" name="group"/>
                <label for="radio-1"></label>
                <input type="radio" class="radio" id="radio-2" name="group"/>
                <label for="radio-2"></label>
                <input type="radio" class="radio" id="radio-3" name="group"/>
                <label for="radio-3"></label>
                <input type="radio" class="radio" id="radio-4" name="group"/>
                <label for="radio-4"></label>
            </div>
        </main>
  
      <script src="js/index.js"></script>

</body>
</html>
