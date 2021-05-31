function fibnum(arg){
     var array;
     if(arg > 0) array.push(0);
     if(arg > 1) array.push(1);
     if(arg > 2) array.push(1);    
     for(var i = 3; i <= arg;i ++)
         array.push(array[i - 1] + array[i - 2]);
     return array;
}