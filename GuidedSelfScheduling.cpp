//
// Created by khang on 10/9/20.
//

#include "GuidedSelfScheduling.h"

#include <numeric>
#include <utility>

GuidedSelfScheduling::GuidedSelfScheduling(std::vector<unsigned> taskTimes, unsigned processors) :
		taskTimes(std::move(taskTimes)), tasks(this->taskTimes.size()), processors(processors), currentTask(0) {}

unsigned GuidedSelfScheduling::processNext() {
	if (currentTask >= tasks) return 0;
	size_t toProcess = (tasks - currentTask - 1) / processors + 1;
	auto from = std::next(taskTimes.begin(), currentTask);
	auto to = std::next(from, toProcess);
	size_t lastProcessed = 0;
	if (processorTimes.size() == processors) {
		lastProcessed = processorTimes.top();
		processorTimes.pop();
	}
	unsigned timeProcess = std::accumulate(from, to, lastProcessed);
	processorTimes.push(timeProcess);
	currentTask += toProcess;
	return timeProcess;
}

unsigned GuidedSelfScheduling::processAll() {
	while (processNext());
	unsigned longestTime = 0;
	while (!processorTimes.empty()) {
		longestTime = std::max(processorTimes.top(), longestTime);
		processorTimes.pop();
	}
	return longestTime;
}
