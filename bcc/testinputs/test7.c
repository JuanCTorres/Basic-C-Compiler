void this_func() {
}

int some_func(){
	int i[2];
	int a = 1;
	i[a] = 300;

	// i[1] = 10;
	// if(-a == -200){
	if(i[1] = 300){
		print "HELLOOOOOO\n";
		print "i[0] + 1000. Should be 1000";
		print i[0] + 1000;
		print "i[1]. Should be 300.";
		print (i[1]);

		// return 0;
	}
	a = i[0];
	print "a = i[0]. a should be 0.";
	print a;
	return i[1];
}

int main(){
	int b;
	b = some_func();
	print "Called some_func(). Returned i[1] = 300";
	print b;

	return 0;
}
