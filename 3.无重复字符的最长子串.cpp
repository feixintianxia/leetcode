/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 *
 * https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/description/
 *
 * algorithms
 * Medium (32.50%)
 * Likes:    3532
 * Dislikes: 0
 * Total Accepted:    451.6K
 * Total Submissions: 1.3M
 * Testcase Example:  '"abcabcbb"'
 *
 * 给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。
 * 
 * 示例 1:
 * 
 * 输入: "abcabcbb"
 * 输出: 3 
 * 解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
 * 
 * 
 * 示例 2:
 * 
 * 输入: "bbbbb"
 * 输出: 1
 * 解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
 * 
 * 
 * 示例 3:
 * 
 * 输入: "pwwkew"
 * 输出: 3
 * 解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
 * 请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int subLen = 0;
        int maxSubLen = 0;
        int begin = 0;

        unordered_map<int, int> hash;

        for (int i = 0; i < s.size(); i++) {
            unordered_map<int, int>::iterator iter = hash.find(s[i]);
            if ( iter != hash.end()) {
                begin = (begin < hash[s[i]] + 1) ? hash[s[i]]  + 1 : begin;
            }
            subLen = i - begin + 1;
            maxSubLen = (maxSubLen < subLen) ? subLen : maxSubLen;
            hash[s[i]] = i;
        }

        return maxSubLen;
        
    }
};
// @lc code=end

