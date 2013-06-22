#include <iostream>
#include "BigInteger.h"


const unsigned int exp  = 7830457;
const unsigned int multa = 20000;
const unsigned int multb =  8000;
const unsigned int multc =   400;
const unsigned int multd =    30;
const unsigned int multe =     3;

int main(){
	
	BigInteger vala(10, 1);
	BigInteger valb(10, 1);
	BigInteger valc(10, 1);
	BigInteger vald(10, 1);
	BigInteger vale(10, 1);


	vala.Multiply(multa);
	valb.Multiply(multb);
	valc.Multiply(multc);
	vald.Multiply(multd);
	vale.Multiply(multe);

	for(unsigned int i=0; i<exp; i++){
		vala.Double();
		valb.Double();
		valc.Double();
		vald.Double();
		vale.Double();
	}

	BigInteger val(10, 0);
	val.Add(vala);
	val.Add(valb);
	val.Add(valc);
	val.Add(vald);
	val.Add(vale);

	BigInteger one(10,1);
	val.Add(one);

	val.Print(10);

	return 0;
}
