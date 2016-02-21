
int Fibonacci(int n)
{
   if ( n == 0 ) {
      return 0;
   }
   if ( n == 1 ) {
      return 1;
   }
   
   return Fibonacci(n-1) + Fibonacci(n-2);
} 




int main()
{
   int n = 4; 
   int i = 0;
   int c;
 
 
   for ( c = 1 ; c <= n ; ++c )
   {
      print Fibonacci(i);
      ++i; 
   }
 
   return 0;
}
 
