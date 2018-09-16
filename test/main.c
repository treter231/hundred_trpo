#define CTEST_MAIN

#include "check.h"
#include "ctest.h"

CTEST(check, uncorrect1) {
    printf("Test on correct num started");
    int correct;
    const int one = 11;
    int exp = 0;
    correct = check(one, 100);
    ASSERT_EQUAL(exp, correct);
}

CTEST(check, uncorrect2) {
    printf("Test on correct num started");
    int correct;
    const int one = -1;
    int exp = 0;
    correct = check(one, 100);
    ASSERT_EQUAL(exp, correct);
}

CTEST(check, correct1) {
    printf("Test on correct num started");
    int correct;
    const int one = 5;
    int exp = 1;
    correct = check(one, 100);
    ASSERT_EQUAL(exp, correct);
}

CTEST(check, correct2) {
    printf("Test on correct num started");
    int correct;
    const int one = 5;
    const int two = 5;
    int exp = 1;
    correct = check(one, two);
    ASSERT_EQUAL(exp, correct);
}

CTEST(check, uncorrect_num) {
    printf("Test on correct num started");
    int correct;
    const int one = 5;
    const int two = 4;
    int exp = 0;
    correct = check(one, two);
    ASSERT_EQUAL(exp, correct);
}


int main(int argc, const char** argv) {
    return ctest_main(argc, argv);
}
