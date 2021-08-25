/* 
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
/* 
    Created on : 07.06.2016, 2:11:05
    Author     : KnightDanila
*/
/**
    How to use it:
    IN HTML
        <div class="loader-circle">
            <div id="loaderCircleLeft" class="loader-circle-left"></div>
            <div id="loaderCircleRight" class="loader-circle-right"></div>
        </div>
        <div id="loaderCircleLabel" class="loader-circle-label">100%</div>

    THEN IN JS
    loaderCircleType0(currentValue, maxValue);

    ALSO NEED 
    <link rel="stylesheet" href="js/loadingStatusBarCircle/loadingStatusBarCircle.css">
    <script src="js/loadingStatusBarCircle/loadingStatusBarCircle.js"></script>
**/

function loaderCircleType1(current, max) {
    var percent = (current / max) * 100;
    var loadLeft = Math.round((percent / 100) * (230));
    var loadRight = Math.round(230 * (percent / 100)) - 5; //(210-230);  //100%
    /*<shape> = rect(<top>, <right>, <bottom>, <left>)*/
    document.getElementById("loaderCircleLeft").style.clip = "rect(-50px, " + loadLeft + "px, 310px, -50px)";
    document.getElementById("loaderCircleRight").style.clip = "rect(-50px, 310px, 310px, " + loadRight + "px)";
    document.getElementById("loaderCircleLabel").innerHTML = Math.round(percent) + "%";
}
function loaderCircleType2(current, max) {
    var percent = Math.round((current / max) * 100);
    var loadLeft = Math.round((percent / 100) * (230));
    var loadRight = Math.round((percent / 100) * (230));
    /*<shape> = rect(<top>, <right>, <bottom>, <left>)*/
    //clip: rect(-50px, -50px, 250px, -50px); 
    document.getElementById("loaderCircleLeft").style.clip = "rect(-50px, " + loadLeft + "px, 250px, -50px)";
    //clip: rect(-50px, 250px, 250px, 250px); 
    document.getElementById("loaderCircleRight").style.clip = "rect(-50px, 250px, 250px, " + loadRight + "px)";
    document.getElementById("loaderCircleLabel").innerHTML = Math.round(percent) + "%";
}
function loaderCircleType3(current, max) {
    var percent = (current / max) * 100;
    var loadLeft = Math.round((percent / 100) * (230));
    var loadRight = percent;
    /*<shape> = rect(<top>, <right>, <bottom>, <left>)*/
    document.getElementById("loaderCircleLeft").style.clip = "rect(-50px, " + loadLeft + "px, 310px, -50px)";
    document.getElementById("loaderCircleRight").style.clip = "rect(-50px, 310px, 310px, " + loadRight + "px)";
    document.getElementById("loaderCircleLabel").innerHTML = Math.round(percent) + "%";
}
function loaderCircleType4(current, max) {
    var percent = (current / max) * 100;
    var loadLeft = Math.round((percent / 100) * (250));
    var loadRight = Math.round(230 * (percent / 100)); //(210-230);  //100%
    /*<shape> = rect(<top>, <right>, <bottom>, <left>)*/
    document.getElementById("loaderCircleLeft").style.clip = "rect(-50px, " + loadLeft + "px, 310px, -50px)";
    document.getElementById("loaderCircleRight").style.clip = "rect(-50px, 310px, 310px, " + loadRight + "px)";
    document.getElementById("loaderCircleLabel").innerHTML = Math.round(percent) + "%";
}
function loaderCircleType0(current, max) {
    var percent = Math.round((current / max) * 100);
    var loadLeft = Math.round((percent / 100) * (230)); //(230 - 0);   //100%
    var loadRight = Math.round(210 - (230 * (percent / 100))); //(210-230);  //100%
    /*<shape> = rect(<top>, <right>, <bottom>, <left>)*/
    //clip: rect(-50px, -50px, 250px, -50px); 
    document.getElementById("loaderCircleLeft").style.clip = "rect(-50px, " + loadLeft + "px, 250px, -50px)";
    //clip: rect(-50px, 250px, 250px, 250px); 
    document.getElementById("loaderCircleRight").style.clip = "rect(-50px, 250px, 250px, " + loadRight + "px)";
    document.getElementById("loaderCircleLabel").innerHTML = Math.round(percent) + "%";
}
