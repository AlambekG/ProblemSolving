function palindromcheck(arg){
     var str = "";
      for(var i = arg.length() - 1; i >= 0; i -- )
          str += arg[i];
    return str == arg;
}