//var data = []

//var nameData = {
   //prefix: ['Win', 'Qt', 'Arduino Bluetooth Controller', 'SwankySea', 'Setup', 'lib', 'mfc', 'MyValley', 'mdn'],
   //word: ['EGL', 'Installer', 'GLES', 'Soft', 'Diag', 'Over', 'vcr', 'Open', 'Light'],
   //suffix: ['Installer.apk', 'Extra.spike', '64a.apk', 'V2.apk', '12sw.apk', 'x86.apk', '120.apk']
//}
//var display = document.querySelectorAll('.display')[0]
//var loaderBar = document.querySelectorAll('.loader .bar')[0]
//var loaderText = document.querySelectorAll('.loader .text')[0]
//var words = makeInstallerFiles()
//drawInstallerFiles(words)
//setInterval(function(){
   //for(var i = 0; i < words.length; i++){  
      //if(words[i].percent < 100){
         //words[i].percent += Math.floor(Math.random()*25)
         //loaderBar.style.display = 'block'
         //if(words[i].percent >= 100){
            //words[i].percent = 100
            //if(words.length-1 !== i)
               //loaderBar.style.display = 'none'
   //      }
         //break;
   //   } 
  // }
   //drawInstallerFiles(words)
//}, 200)
//function drawInstallerFiles(words){
   //display.innerHTML = ''
   //words.forEach(function(word){
      //if(word.percent > 0){
         //display.innerHTML += '<div class="line">'+word.word+'...'+word.percent+'%</div>'
         //loaderText.innerHTML = word.word+'...'+word.percent+'%'
         //loaderBar.style.width = word.percent + '%'
         //if(word.percent < 100)
            //display.scrollTop = 100000;
         
      //}
  //})
//}

//function makeInstallerFiles(){
  // var arr = []
   //for(var i = 0; i < 20; i++){
   //   var prefix = chooseRandomValue(nameData.prefix) 
   //   var word = chooseRandomValue(nameData.word) 
   //   var suffix = chooseRandomValue(nameData.suffix) 
   //   arr.push({
    //     word: prefix + word + suffix,
  //       percent: 0
 //     })
//   }
//   return arr
//}
   
//function chooseRandomValue(arr){
 //  min = 0
 //  max = arr.length
  // return arr[Math.floor(Math.random()*(max-min)+min)]
//}

//document.getElementById('programname').innerHTML = nameprogram;
