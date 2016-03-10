int qq;
int dd[10];

int main() {


	int a[12];
	int b;
	int c;
	int d;
	a[0] = 7;
	a[1] = 2;
	a[2] = 3;

	b = 2;
	c = 3;
	d = 2;

	print "d before";
	print d;

	a[4] = 2;

	print "d after";
	d = a[4] + 3;

	print "a[4] == 2: (should be true).";
	d = (a[4] == 2);

	print d;
	if(a[4] == 2){
		print "c is:";
		print c;
	}

	++a[4];
	c = b + a[4];
	print "Incrementing a[4] (should be 3 now):";
	print a[4];
	print "c = b + a[4] (should be 5 now)";
	print c;

	return 0;
}
