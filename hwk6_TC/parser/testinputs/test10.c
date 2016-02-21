int recurr( int a ) {

	if (a == 0) {
		return 1;
	}
	else {
		return a*recurr(a-1);
	}

	return 1;
}


int main(void) {
	int answer;

	answer = recurr(6);


	print answer;
	return answer;
}