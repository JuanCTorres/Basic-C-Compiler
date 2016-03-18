int aaa = 7;

int func(){
	print "accessing aaa again in a different function:";
	print aaa;
	return 0;
}


int main() {
	print "aaa is a global var with value 7. Printing:";
	print aaa;
	func();
	return 0;
}
