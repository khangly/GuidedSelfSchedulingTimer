#include <iostream>
#include "GuidedSelfScheduling.h"

int main() {
	const unsigned C = 1, P = 10, n = 1000;
	std::vector<unsigned> taskTimes(n);
	for (size_t i = 0; i < taskTimes.size(); i++) {
		taskTimes[i] = C * (i + 1);
	}
	GuidedSelfScheduling scheduling(taskTimes, P);
	std::cout << scheduling.processAll();
	return 0;
}

