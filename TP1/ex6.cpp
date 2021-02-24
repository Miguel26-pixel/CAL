// By: Gonçalo Leão

#include "exercises.h"
#include <algorithm>
#include "math.h"

bool Activity::operator==(const Activity &a2) const {
    return start == a2.start && finish == a2.finish;
}

bool Activity::operator<(const Activity &a2) const {
    return finish < a2.finish;
}

std::vector<Activity> earliestFinishScheduling(std::vector<Activity> A) {
    std::vector<Activity> res;
    unsigned int actual = 0;
    while(A.size()!=0)
    {
        bool fake = false;
        unsigned int max = 100000000;
        auto i = A.begin();
        for (auto it = A.begin(); it !=A.end(); it++)
        {
            if((*it).start > actual && (*it).start < max) {
                fake = true;
                i = it;
                max = (*it).start;
            }
        }
        if(fake)
        {
            fake = false;
            res.push_back(*i);
            actual = (*i).finish;
            A.erase(i);
        }
        else break;
    }
    return res;
}

/// TESTS ///
#include <gtest/gtest.h>
#include <gmock/gmock.h>

TEST(TP1_Ex6, activityScheduling) {
    std::vector<Activity> A = {{10,20}, {30, 35}, {5, 15}, {10, 40}, {40, 50}};
    std::vector<Activity> V = earliestFinishScheduling(A);
    EXPECT_EQ(V.size(), 3 );
    ASSERT_THAT(earliestFinishScheduling(A),  ::testing::ElementsAre(Activity(5, 15), Activity(30, 35), Activity(40, 50)));
}