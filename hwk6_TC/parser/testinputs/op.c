int foo(int bar[]){
	bar[1]=3;
	return bar[1];
}

void main(void){
	int b[10];
	int a=foo(b); // a = 3
	int c = a+ ++b[1]*4-5; // c = 3 + -1 = 2
	a=++b[++a]; // ++b[4] = 1
	a=-a; // a = -1
	print b[-a]; // b[1] = 1 (since array modified by foo is local to foo)
}
