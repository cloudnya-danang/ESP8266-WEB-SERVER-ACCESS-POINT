const char MAIN_page[] PROGMEM = R"=====(
<!DOCTYPE html>
<html>
<head>
  <title>WEB IoT ROBOTIC</title>
  <meta charset="utf-8">
<style>

    /* Style the header */
   header {
    padding: 5px;
      text-align: center;
      font-size: 20px;
      color: white;
      font-family: Georgia, sans-serif;
      background-color: salmon;
  }

  /* Style the footer */
   footer {
      background-color: salmon;
      padding: 8px;
      text-align: center;
      color: white;
      font-family: Georgia, sans-serif;
   }

   body {
    color: white;
    text-align: center;
   }

     /* Style the botton start stop */
   .btn{
    position: relative;
    border-radius: 15px 15px 15px 15px;
    width: 8%;
    height: 25px;
    border: none;
    outline: none;
    cursor: pointer;
    background: #ffc107;
    color: #fff;
   }


</style>
</head>

<body style="background-color:slategrey;
       font-family: Georgia, sans-serif;">
  
  <header>
  <h3>WEB IoT ROBOTIC</h3>
  </header>
  <br><br><br>

  <div class="">
      <button type="button" onclick="sendData(0)" class="btn">ON</button>
      <label> LED 1 STATE : </label>
      <label><span id="isiStatusled1">NA</span></label>
      <button type="button" onclick="sendData(1)" class="btn">OFF</button>
  </div><br><br><br>


<script style="">
    /* fungsi send data on/off */
        function sendData(Statusled1) {
        var xhttp = new XMLHttpRequest();
        xhttp.onreadystatechange = function() {
          if (this.readyState == 4 && this.status == 200) { 
            document.getElementById("LEDstate1").innerHTML = this.responseText;
          }
        };
        
        xhttp.open("GET", "setLED1?;LEDstate1=" + Statusled1, true);
        xhttp.send();
        }



    /* fungsi read data on/off */
        function getDataLED1() {
        var xhttp = new XMLHttpRequest();
        xhttp.onreadystatechange = function() {
          if (this.readyState == 4 && this.status == 200) {
            document.getElementById("isiStatusled1").innerHTML = this.responseText;
          }
        };
        xhttp.open("put", "readLED1", true);
        xhttp.send();
        }


        setInterval(function() {
        // Call a function repetatively with 2 Second interval
        getDataLED1();
        }, 2000); //2000mSeconds update rate   
</script>


<footer>
  <h2>Presented by:</h2>
    <p>
  UKM ROBOTIC</br>
  </p>
  <p>Astra Manufacturing Polytechnic @2019</p>
</footer>

</body>
</html>
)=====";
