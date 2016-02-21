int main()
{
   int n = 10; //number of fibb terms
   int first = 0;
   int second = 1;
   int next, c;
 
 
   for ( c = 0 ; c < n ; ++c )
   {
      if ( c <= 1 ) {
         next = c;
      }
      else
      {
         next = first + second;
         first = second;
         second = next;
      }
      print next;
   }
 
   return 0;
}