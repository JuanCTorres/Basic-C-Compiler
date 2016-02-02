int main(void) {

	int a = 5;
	int c = 10;

	if(1) {
		print "hi there\n";
	}

	//my_func(a b c); //incorrect variable input into a function (no commas to separate)
	print ("hello\n"); //illegal because strings cannot be inside brackets in our grammar

	for(321) { //this is a illegal for-header
		if("broken") { //illegal expression for if-else
			a = 5;
		}
		else {
			while (a != 5) {
				print; //illegal print statement
			}

			while (int asd = 5) { //illegal while parameter
				int a b c d e; //illegal declaration
			}
		}
	}




	return 0;
}

