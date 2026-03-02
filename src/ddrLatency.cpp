#include <iostream>
#include <vector>
#include <algorithm>

#include "ramInfo.h"

void printUsage();

//make gui
int main(int argc, char *argv[]) {

	if(argc < 3 || (argc - 1) % 2 != 0) {
		printUsage();
		return 0;
	}

	std::vector<ramInfo> ramInfoVector;
	unsigned s, cl;
	for(int i = 1; i < argc; i += 2) {
		
		try {
			s = std::stoul(argv[i], NULL, 10); //why stol when s is of type unsigned???
			cl = std::stoul(argv[i+1], NULL, 10);
		}
		catch(...) {
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
	std::cout << "Incorrect Input!\n" << 
					"Usage: ddrLatency.exe [speed] [casLatency] ([speed2] [casLatency2] ...)\n" <<
					"\nPrints out calculated total latency of a given memory module or list of modules sorted in ascending order.";
}