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
	int answer[5];
	answer[4] = 6;

	answer[2] = recurr(answer[4]);


	print answer[2];
	return answer[2];
}