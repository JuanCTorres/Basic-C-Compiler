int myfunc(int a, int b){ // myfunc: (0,0), a, b: (1, 0)
   return a + b;           // a, b: (1, 0)
}

int main(){               // main: (0, 0)
                          // local declarations would go here: (1, 0)
  {
    int c = 4;            // c, d: (2, 0)
    int d = 5;
    {
      int e = 6;          // e: (3, 0)
    }
    myfunc(f, g);         // f, g: (2, 0) (same scope as c, d)
    newfunc(h, i);        // h, j: (2, 0)
    {
      int mynewvar = 9;   // mynewvar: (3, 1)
    }
    j = 3;
  }
  k = 8;                  // k: (1, 1) (different from 1.0, which is for myfunc)

}
