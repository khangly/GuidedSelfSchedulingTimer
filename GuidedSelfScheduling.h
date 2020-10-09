//
// Created by khang on 10/9/20.
//

#ifndef GUIDED_SELF_SCHEDULING_GUIDEDSELFSCHEDULING_H
#define GUIDED_SELF_SCHEDULING_GUIDEDSELFSCHEDULING_H

#include <queue>
#include <vector>

class GuidedSelfScheduling {
	const std::vector<unsigned> taskTimes;
	size_t currentTask, processors, tasks;
	std::priority_queue<unsigned, std::vector<unsigned>, std::greater<>> processorTimes;
public:
	/**
	 * @param taskTimes: the time each task takes
	 * @param processors: the number of processors
	 */
	GuidedSelfScheduling(std::vector<unsigned> taskTimes, unsigned processors);
	/**
	 * Process new tasks for a processor
	 * @return The time the processor has been running
	 */
	unsigned processNext();
	/**
	 * Process all tasks
	 * @return The time of the slowest processor
	 */
	unsigned processAll();

};


#endif //GUIDED_SELF_SCHEDULING_GUIDEDSELFSCHEDULING_H
