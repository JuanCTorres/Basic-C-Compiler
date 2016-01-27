int myfunc(int b, int c){ // 0.0
	int b;                  // 1.0
	{
		int c;                // 2.0
	}

}

int main(){  // 0.0
	int i;     // 1.1
	for(i = 4; i < 4; ++i){ // 1.1
		int a = 3;            // 2.1
	}
	b = 3;                  // 1.1
	{
		int z = 3;            // 2.2
	}
	{
		int y = 5;            // 2.3
		{
			int yy = 2;         // 3.0
		}
	}

}
