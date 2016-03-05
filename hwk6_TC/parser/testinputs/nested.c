int a=0;
void main(void){
	for(a=0; a<10; ++a){
		int b=a;
		if (a==b){
			int c=a+b;
			print "yes";	
		} else {
			int c=a-b;
			print "no";	
		}	
	}
}