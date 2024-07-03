/*
    #include <gtest/gtest.h>
#include "Soundex.h"


TEST(SoundexTest, HandlesEmptyString) {
    EXPECT_EQ(generateSoundex(""), "");
}

TEST(SoundexTest, HandlesSingleCharacter) {
    EXPECT_EQ(generateSoundex("A"), "A000");
}
*/
#include <gtest/gtest.h>
#include "Soundex.h"

TEST(SoundexTest, HandlesEmptyString) {
    EXPECT_EQ(generateSoundex(""), "0000");
}

TEST(SoundexTest, HandlesSingleCharacter) {
    EXPECT_EQ(generateSoundex("A"), "A000");
}

TEST(SoundexTest, HandlesStandardNames) {
    EXPECT_EQ(generateSoundex("Robert"), "R163");
    EXPECT_EQ(generateSoundex("Rupert"), "R163");
    EXPECT_EQ(generateSoundex("Rubin"), "R150");
    EXPECT_EQ(generateSoundex("Ashcraft"), "A261");
    EXPECT_EQ(generateSoundex("Tymczak"), "T522");
    EXPECT_EQ(generateSoundex("Pfister"), "P236");
}

TEST(SoundexTest, HandlesRepetitiveCharacters) {
    EXPECT_EQ(generateSoundex("BbBb"), "B100");
    EXPECT_EQ(generateSoundex("Bcdl"), "B234");
}

