#include "headers/domain/shared/StringUtils.h"
#include "gtest/gtest.h"

class StringUtilsFixture : public ::testing::Test {

protected:
    virtual void SetUp() {
        // Add here some testing set up code
    }

    virtual void TearDown() {
        // Add here some testing tear down code
    }

    StringUtils *utils;
};

TEST_F(StringUtilsFixture, CheckingUpperCase) {
    wstring expected = L"ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    wstring original = L"abcdefghijklmnopqrstuvwxyz";
    wstring result = utils->toUpperCase(original);

    EXPECT_EQ(result, expected);
}

TEST_F(StringUtilsFixture, CheckingLowerCase) {
    wstring expected = L"abcdefghijklmnopqrstuvwxyz";
    wstring original = L"ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    wstring result = utils->toLowerCase(original);

    EXPECT_EQ(result, expected);
}

TEST_F(StringUtilsFixture, LeftTrim) {
    wstring expected = L"name  ";
    wstring original1 = L"   name  ";
    wstring original2 = L"name  ";
    wstring original3 = L" name  ";

    wstring result = utils->leftTrim(original1);
    EXPECT_EQ(result, expected);
    result = utils->leftTrim(original2);
    EXPECT_EQ(result, expected);
    result = utils->leftTrim(original3);
    EXPECT_EQ(result, expected);
}

TEST_F(StringUtilsFixture, RightTrim) {
    wstring expected = L"  name";
    wstring original1 = L"  name  ";
    wstring original2 = L"  name";
    wstring original3 = L"  name ";

    wstring result = utils->rightTrim(original1);
    EXPECT_EQ(result, expected);
    result = utils->rightTrim(original2);
    EXPECT_EQ(result, expected);
    result = utils->rightTrim(original3);
    EXPECT_EQ(result, expected);
}

TEST_F(StringUtilsFixture, Trim) {
    wstring expected = L"name";
    wstring original1 = L"  name  ";
    wstring original2 = L"  name";
    wstring original3 = L"name  ";

    wstring result = utils->trim(original1);
    EXPECT_EQ(result, expected);
    result = utils->trim(original2);
    EXPECT_EQ(result, expected);
    result = utils->trim(original3);
    EXPECT_EQ(result, expected);
}

TEST_F(StringUtilsFixture, EnsureNotNullOrEmpty) {
    EXPECT_FALSE(utils->ensureNotNullOrEmpty(L""));
    EXPECT_FALSE(utils->ensureNotNullOrEmpty(L"   "));
    EXPECT_TRUE(utils->ensureNotNullOrEmpty(L" some value "));
    EXPECT_TRUE(utils->ensureNotNullOrEmpty(L" some value ", 10));
    EXPECT_FALSE(utils->ensureNotNullOrEmpty(L" some value ", 11));
}