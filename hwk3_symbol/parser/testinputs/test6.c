int myfunc(int a, int b){ // myfunc: (0,0), a, b: (1, 0)
   return a + b;           // a, b: (1, 0)
}

void main(){               // main: (0, 0)
                          // local declarations would go here: (1, 0)
  {
    int c = 4;            // c, d: (2, 0)
    int d = 5;
    {

      int e = 6;          // e: (3, 0)
      {

        int eeee = 113;// (4, 0)
        while(i = 3; i < 4; ++i){ // i inside the condition should be in (4, 0)

          banana = 3;          // (5, 0)
        }
      }

      a = 54;                  // (3, 0)
      {

        for(num = blah; num < something; --blah){ // (4, 1)

          whois(blah, blahblah); // (5, 1)
        }
      }
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
