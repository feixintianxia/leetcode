/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 *
 * https://leetcode-cn.com/problems/longest-palindromic-substring/description/
 *
 * algorithms
 * Medium (28.10%)
 * Likes:    2103
 * Dislikes: 0
 * Total Accepted:    250.7K
 * Total Submissions: 846.2K
 * Testcase Example:  '"babad"'
 *
 * 给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为 1000。
 * 
 * 示例 1：
 * 
 * 输入: "babad"
 * 输出: "bab"
 * 注意: "aba" 也是一个有效答案。
 * 
 * 
 * 示例 2：
 * 
 * 输入: "cbbd"
 * 输出: "bb"
 * 
 * 
 */

// @lc code=start
/* 
  * 中心扩散法
class Solution {
public:
    string longestPalindrome(string s) {
        int len = s.size();
        if (len < 2) {
            return s;
        }

        int maxLen = 0;
        string res;
        for (int i = 0; i < len - 1; i++) {
            string oddStr = centerSpread(s, i, i);
            string evenStr = centerSpread(s, i, i+1);
            string maxLenStr = (oddStr.size() < evenStr.size()) ? evenStr : oddStr; 

            if (maxLenStr.size() > maxLen) {
                maxLen = maxLenStr.size();
                res = maxLenStr;
            }
        }
       return res;
    }

    string centerSpread(string s, int left, int right) {
        int len = s.size();

        int i = left;
        int j = right;

        while ( 0 <= i && j < len) {
            if (s[i] == s[j]) {
                i--;
                j++;
            } else {
                break;
            }
        }

        return s.substr(i + 1, j - i - 1);
    }
};
*/
class Solution {
public:
    string longestPalindrome(string s) {
        int len = s.size();
        if (len < 2) {
            return s;
        }

        string newStr = addBoundaries(s, '#');
        int newLen = newStr.size();
        vector<int> index(newLen, 0);

        int maxRight = 0;
        int center = 0;

        int maxLen = 0;
        int start = 0;

        for (int i = 0; i < newLen; i++) {
            if (i < maxRight) {
                int mirror = 2 * center - i;
                index[i] = min(maxRight - i, index[mirror]);
            }

            int left = i - index[i] - 1;
            int right = i + index[i] + 1;

            while (0 <= left && right < newLen) {
                if (newStr[left] == newStr[right]) {
                    index[i]++;
                    left--;
                    right++;
                } else {
                    break;
                }
            }

            if (i+index[i] > maxRight) {
                maxRight = i + index[i];
                center = i;
            }

            if (index[i] > maxLen) {
                maxLen = index[i];
                start = (i - maxLen) / 2;
            }
        }
        return s.substr(start, maxLen);
    }

    string addBoundaries(string s, char divide)  {
        string newStr;
        newStr = divide;

        for (int i = 0; i < s.size(); i++) {
            newStr.append(1, s[i]);
            newStr.append(1, divide);
        }

        return newStr;
    }
};
// @lc code=end

