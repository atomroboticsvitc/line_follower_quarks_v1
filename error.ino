bool error1(int a0, int a1 , int a2 , int a3 , int a4 , int a5 ){
  
  if (b[0]==a0&&b[1]==a1&&b[2]==a2&&b[3]==a3&&b[4]==a4&&b[5]==a5){
    return true;
  }
  
  else{
    return false;
  }
}
int  error2(int a0, int a1 , int a2 , int a3 , int a4 , int a5 ){
 int error=((a0*3)+(a1*2)+(a2*1)+(a3*-1)+(a4*-2)+(a5*-3));
 return error;
}