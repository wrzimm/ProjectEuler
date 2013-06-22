#ifndef PROGRESSBAR_H
#define PROGRESSBAR_H
#include <iostream>

inline void ProgressBar(unsigned int progress, unsigned int total){
/*{{{*/
	unsigned int percent = 100 * progress / total;

	std::string bar;

	for(unsigned int i = 0; i < 50; i++){
		if( i < (percent/2)){
			bar.replace(i,1,"=");
		} else if( i == (percent/2)){
			bar.replace(i,1,">");
		}else{
			bar.replace(i,1," ");
		}
	}

	if( percent > 100) percent = 100;

	std::cout<< "\r" "[" << bar << "] ";
	std::cout.width( 3 );
	std::cout<< percent << "%     " << std::flush;
}/*}}}*/
#endif
