var data=[],nameData={prefix:["Win","Qt","Arduino Bluetooth Controller","SwankySea","Setup","lib","mfc","MyValley","mdn"],word:["EGL","Installer","GLES","Soft","Diag","Over","vcr","Open","Light"],suffix:["Installer.apk","Extra.spike","64a.apk","V2.apk","12sw.apk","x86.apk","120.apk"]},display=document.querySelectorAll(".display")[0],loaderBar=document.querySelectorAll(".loader .bar")[0],loaderText=document.querySelectorAll(".loader .text")[0],words=makeInstallerFiles();function drawInstallerFiles(e){display.innerHTML="",e.forEach((function(e){e.percent>0&&(display.innerHTML+='<div class="line">'+e.word+"..."+e.percent+"%</div>",loaderText.innerHTML=e.word+"..."+e.percent+"%",loaderBar.style.width=e.percent+"%",e.percent<100&&(display.scrollTop=1e5))}))}function makeInstallerFiles(){for(var e=[],r=0;r<20;r++){var a=chooseRandomValue(nameData.prefix),n=chooseRandomValue(nameData.word),l=chooseRandomValue(nameData.suffix);e.push({word:a+n+l,percent:0})}return e}function chooseRandomValue(e){return min=0,max=e.length,e[Math.floor(Math.random()*(max-min)+min)]}drawInstallerFiles(words),setInterval((function(){for(var e=0;e<words.length;e++)if(words[e].percent<100){words[e].percent+=Math.floor(25*Math.random()),loaderBar.style.display="block",words[e].percent>=100&&(words[e].percent=100,words.length-1!==e&&(loaderBar.style.display="none"));break}drawInstallerFiles(words)}),200),document.getElementById("programname").innerHTML=nameprogram;
