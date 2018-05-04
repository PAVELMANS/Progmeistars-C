static int i=10;

int next(int j)
{
   return( j = i++ );
}

int last()
{
   return( i -= 1 );
}

int new(int i)
{
   static int j=5;
   return( i = j += i );
}
