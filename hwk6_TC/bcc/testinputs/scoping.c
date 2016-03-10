int a, b, c;

int myfunc(int a, int b) {
	int c = 9;

	print c;

	a = a+b;

	print a;

	return 999;

}


int main (){

	if(1 == 1){
		int a = 333;
		print a;
	}

	a = 1;
	
	c = 11;
	
	myfunc(3,4);
	print a;
	print c;



	return 0;
}