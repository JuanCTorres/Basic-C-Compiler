int myfunc(int g){ // 0.0
	int b;                  // 1.0
	{
		int c;                // 2.0
	}

}

int main(int uu, int ww){  // 0.0
	int i;     // 1.1
	for(i = 4; i < 4; ++i){   // 1.1
		int a = 3;            // 2.1
	}
	i = 3;     	              // 1.1
	{
		int z = 3;            // 2.2
	}
	{
		int y = 5;            // 2.3
		y = 4;
		{
			int yy = 2;       // 3.0
			yy = 123;
		}
	}
	myfunc();
}
