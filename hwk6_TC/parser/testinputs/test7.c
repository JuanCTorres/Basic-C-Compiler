void this_func() {
}

int some_func(){
	int i[2];
	int a = 100;
	i[0] = 100;
	// i[1] = 10;
	if(++i[0] == 101){
		print "HELLOOOOOO\n";
		// return 0;
	}
	a = i[0];
	print a;
	return 0;
}

int main(){
	some_func();
	return 0;
}
