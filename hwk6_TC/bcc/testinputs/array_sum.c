int sum(int b[]){
  int c, d, e;
  b[4] = 5;
  b[3] = 4;

  for(d = 0; d< 5; ++d){
    c = c + b[d];
  }
  //return b[3] + b[4];
  return c;

}

int main(){
  int i[5];
  i[0] = 1;
  i[1] = 2;
  i[2] = 3;
  print "Passing array i as a parameter to my_f(). Should return 8";
  print sum(i);
  return 0;
}
