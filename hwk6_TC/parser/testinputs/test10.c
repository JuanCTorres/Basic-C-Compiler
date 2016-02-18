int recurr( int a ) {
	int b;

	if (a == 0) {
		return 1;
	}
	else {
		return a*recurr(a-1);
	}

	return b;
}


int main(void) {
	int answer;

	answer = recurr(10);



	return answer;
}