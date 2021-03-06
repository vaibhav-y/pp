#include <gtest/gtest.h>

#include "Common.h"
#include "longestPalindromicSubstring.h"

class P0005_LongestPalindromicSubstring : public ::testing::Test {
protected:
  p0005::Solution sol;
};

TEST_F(P0005_LongestPalindromicSubstring, EmptyStr) {

  EXPECT_EQ(sol.longestPalindrome(""), "");
}

TEST_F(P0005_LongestPalindromicSubstring, TrivialPalindrome) {

  EXPECT_EQ(sol.longestPalindrome("the quick brown fox"), "t");
}

TEST_F(P0005_LongestPalindromicSubstring, FullMatch1) {

  EXPECT_EQ(sol.longestPalindrome("a"), "a");
}

TEST_F(P0005_LongestPalindromicSubstring, FullMatch2) {

  EXPECT_EQ(sol.longestPalindrome("bb"), "bb");
}

TEST_F(P0005_LongestPalindromicSubstring, FullMatch3) {

  EXPECT_EQ(sol.longestPalindrome("ccc"), "ccc");
}

TEST_F(P0005_LongestPalindromicSubstring, FullMatch4) {

  EXPECT_EQ(sol.longestPalindrome("racecar"), "racecar");
}

TEST_F(P0005_LongestPalindromicSubstring, LatterHalf0) {

  std::string lp(sol.longestPalindrome("xc"));
  EXPECT_TRUE(lp == "x" || lp == "c");
}

TEST_F(P0005_LongestPalindromicSubstring, LatterHalf1) {

  EXPECT_EQ(sol.longestPalindrome("xxyx"), "xyx");
}

TEST_F(P0005_LongestPalindromicSubstring, LatterHalf2) {

  EXPECT_EQ(sol.longestPalindrome("some_prefixxyx"), "xyx");
}

TEST_F(P0005_LongestPalindromicSubstring, LatterHalf3) {

  EXPECT_EQ(sol.longestPalindrome("ilikeracecars"), "racecar");
}

TEST_F(P0005_LongestPalindromicSubstring, FormerHalf1) {

  EXPECT_EQ(sol.longestPalindrome("racecarsilike"), "racecar");
}

TEST_F(P0005_LongestPalindromicSubstring, LeetCode1) {
  EXPECT_EQ(sol.longestPalindrome("aacdefcaa"), "aa");
}

// Failed with -fsanitize=address on leetcode lol
TEST_F(P0005_LongestPalindromicSubstring, LeetCode2) {
  EXPECT_EQ(sol.longestPalindrome("babaddtattarrattatddetartrateedredividerb"),
            "ddtattarrattatdd");
}

// Time Limit Exceeded, ~100ms O(n^3)
TEST_F(P0005_LongestPalindromicSubstring, LeetCode3) {
  EXPECT_EQ(
      sol.longestPalindrome(
          "flsuqzhtcahnyickkgtfnlyzwjuiwqiexthpzvcweq"
          "zeqpmqwkydhsfipcdrsjkefehhesubkirhalgnevju"
          "gfohwnlhbjfewiunlgmomxkafuuokesvfmcnvseixk"
          "kzekuinmcbmttzgsqeqbrtlwyqgiquyylaswlgfflrezaxtjobltcnpjsaslyviviosx"
          "orjsfncqirsjpkgajkfpoxxmvsyynbbovieoothpjgncfwcvpkvjcmrcuoronrfjcppb"
          "isqbzkgpnycqljpjlgeciaqrnqyxzedzkqpqsszovkgtcgxqgkflpmrikksaupukdvkz"
          "bltvefitdegnlmzeirotrfeaueqpzppnsjpspgomyezrlxsqlfcjrkglyvzvqakhtvfm"
          "eootbtbwfhqucbnuwznigoyatvkocqmbtqghybwrhmyvvuchjpvjckiryvjfxabezchy"
          "nfxnpqaeampvaapgmvoylyutymdhvhqfmrlmzkhuhupizqiujpwzarnszrexpvgdmtox"
          "vjygjpmiadzdcxtggwamkbwrkeplesupagievwsaaletcuxtpsxmbmeztcylsjxvhzrq"
          "izdmgjfyftpzpgxateopwvynljzffszkzzqgofdlwyknqfruhdkvmvrrjpijcjomnrjj"
          "ubfccaypkpfokohvkqndptciqqiscvmpozlyyrwobeuazsawtimnawquogrohcrnmexi"
          "wvjxgwhmtpykqlcfacuadyhaotmmxevqwarppknoxthsmrrknu"),
      "ljpjl");
}
