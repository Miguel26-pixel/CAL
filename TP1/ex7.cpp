// By: Gonçalo Leão

#include "exercises.h"

#include <algorithm>
#include <stdio.h>
#include <vector>

double minimumAverageCompletionTime(std::vector<unsigned int> tasks, std::vector<unsigned int> &orderedTasks) {
    double res = 0.0f, sum = 0.0f;
    std::vector<unsigned int> ordtasks = tasks;
    std::sort(ordtasks.begin(),ordtasks.end());
    for (auto i = ordtasks.begin(); i != ordtasks.end(); i++)
    {
        orderedTasks.push_back((*i));
        res += sum + (*i);
        sum += (*i);
    }
    return res/tasks.size();
}

/// TESTS ///
#include <gtest/gtest.h>
#include <gmock/gmock.h>

TEST(TP1_Ex7, taskOrdering) {
    std::vector<unsigned int> tasks = {15, 8, 3, 10};
    std::vector<unsigned int> orderedTasks;
    double averageTime = minimumAverageCompletionTime(tasks, orderedTasks);
    EXPECT_EQ(orderedTasks.size(), 4);
    ASSERT_NEAR(averageTime, 17.75, 0.00001);
    ASSERT_THAT(orderedTasks,  ::testing::ElementsAre(3,8,10,15));
}