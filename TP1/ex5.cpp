// By: Gonçalo Leão

#include "exercises.h"
#include <iostream>
#include "algorithm"

bool isCanonical(unsigned int C[], unsigned int n) {
    if (n < 3) return false;
    unsigned int Stock[n];
    int min = C[2]+1;
    int max = C[n-1]+C[n-2];
    for (unsigned int T = min+1; T < max;T++)
    {
        for (unsigned j = 0; j < n; ++j){
            Stock[j] = n;
        }
        unsigned int usedCoinsG[n];
        unsigned int usedCoinsBF[n];
        changeMakingBF(C,Stock,n,T,usedCoinsBF);
        changeMakingGreedy(C,Stock,n,T,usedCoinsG);
        unsigned sumBruteForce = 0, sumGreedy = 0;
        for (unsigned i = 0; i < n; ++i){
            sumBruteForce += usedCoinsBF[i];
            sumGreedy += usedCoinsG[i];
        }
        if (sumBruteForce != sumGreedy) return false;
    }
    return true;
}


/// TESTS ///
#include <gtest/gtest.h>

TEST(TP1_Ex5, canonicalTrue) {
    unsigned int C[] = {1,2,5};
    EXPECT_EQ(isCanonical(C,3), true);

    unsigned int C2[] = {1,2,5,10};
    EXPECT_EQ(isCanonical(C2,4), true);
}

TEST(TP1_Ex5, canonicalFalse) {
    unsigned int C[] = {1,4,5};
    EXPECT_EQ(isCanonical(C,3), false);
}