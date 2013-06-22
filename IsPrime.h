inline bool  IsPrime(unsigned long number){
	bool prime=true;
	unsigned long i;

	for (i=2; i<number; i++){
		if (number % i ==0){
			prime = false;
			break;
		}
	}
	
	return prime;
}
