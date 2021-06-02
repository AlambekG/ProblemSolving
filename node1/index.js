const fs = require('fs');
const path = require('path');

const filepath = path.join(__dirname, 'input.txt');
const file2path = path.join(__dirname, 'patterns.txt');

let str1 = fs.readFileSync(filepath, 'utf-8', (err, content) => {
    if(err) throw err;
   // console.log(content);
})


let str2 = fs.readFileSync(file2path, 'utf-8', (err, content) => {
    if(err) throw err;
    //console.log(content);
})
str1 = str1.split('\n');
str2 = str2.split('\n');
str1[str1.length - 1] += '\r';
str2[str2.length - 1] += '\r';

console.log(str1);
console.log(str2);

function fun1(){
      for(let i = 0;i < str1.length;i ++){
            let flag = false;
            let a = str1[i];
            for(let j = 0;j < str2.length;j ++){
                let b = str2[j];
                  if(a == b) {flag = true;
                     break;
                }
            }
            if(flag) console.log(a);
      }
}
function fun2(){
    for(let i = 0;i < str1.length;i ++){
        let flag = false;
        let a = str1[i];
        for(let j = 0;j < str2.length;j ++){
            let b = str2[j];
              if(a == b && i == j) {flag = true;
                 break;
            }
        }
        if(flag) console.log(a);
   }
}
function fun3(){
    for(let i = 0;i < str1.length;i ++){
        let flag = false;
        let a = str1[i];
        for(let j = 0;j < str2.length;j ++){
            let b = str2[j];
            let dif = 0;
            for(let k = 0;k < a.length;k ++){
                  if(a[k] != b[k]) dif ++;
                  if(dif > 1) break;
            }
            //console.log(i, j, " dif: ", dif);
            if(dif <= 1){flag = true; break;}
        }
        if(flag) console.log(a);
  }
}

console.log("First mode:");
fun1();
console.log("\nSecond mode:");
fun2();
console.log("\nThird mode:");
fun3();
