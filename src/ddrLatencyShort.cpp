#include <iostream>
#include <cstdlib>

int main(int argc, char *argv[]) {

	if(argc != 3) return 0;

	try {
		std::cout << ((double)(2000 * std::stol(argv[2])) / std::stol(argv[1])) << "ns";
	}
	catch(...) { }

	//ovako bi realno trebalo ovo da se ispise
	/*
	double speed;
	double cas;

	try{
		speed = std::stol(argv[1], NULL, 10);
		cas = std::stol(argv[2], NULL, 10);
	}
	catch(...) {
		return 0;
	}

	std::cout << (2000 * cas) / speed << "ns";
	*/

	return 0;
}

