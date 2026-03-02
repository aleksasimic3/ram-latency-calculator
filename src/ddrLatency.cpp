#include <iostream>
#include <vector>
#include <algorithm>

#include "ramInfo.h"

void printUsage();
void printCommonValues();

//make gui
int main(int argc, char *argv[]) {

	if(argc == 1) {
		printCommonValues();
		printUsage();
		return 0;
	}

	if(argc < 3 || (argc - 1) % 2 != 0) {
		std::cout << "Incorrect input!\n";
		printUsage();
		return 0;
	}

	std::vector<ramInfo> ramInfoVector;
	unsigned s, cl;
	for(int i = 1; i < argc; i += 2) {
		
		try {
			s = std::stoul(argv[i], NULL, 10);
			cl = std::stoul(argv[i+1], NULL, 10);
		}
		catch(...) { //name this exception
			//skip this pair
			continue;
		}

		ramInfoVector.push_back(ramInfo(s, cl));
	}

	std::sort(ramInfoVector.begin(), ramInfoVector.end());

	std::cout << "\n";
	for(auto it = ramInfoVector.begin(); it != ramInfoVector.end(); it++) {
		std::cout << *it << "\n";
	}

	return 0;
}

void printUsage() {
	std::cout <<"Usage: ddrLatency.exe [speed] [casLatency] ([speed2] [casLatency2] ...)\n" <<
					"\nPrints out calculated total latency of a given memory module or list of modules sorted in ascending order.";
}

void printCommonValues() {
	//2133 15 2400 16 2666 18 3200 22 3200 16 3600 18
	std::vector<std::pair<unsigned, unsigned>> values = {{2311, 15}, {2400, 16}, {2666, 18}, {3200, 22}, {3200, 16}, {3600, 18}};

	std::cout << "Most common DDR4 values:\n";
	for(auto specs: values) {
		ramInfo info(specs.first, specs.second);
		std::cout << '\t' << info << '\n';
	}

	std::cout << '\n';
}