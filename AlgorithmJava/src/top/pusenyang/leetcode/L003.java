package top.pusenyang.leetcode;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.Map;

/**
 * 给定一个字符串，请你找出其中不含有重复字符的最长子串的长度。
 *
 * 示例 1:
 *
 * 输入: s = "abcabcbb"
 * 输出: 3
 * 解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
 */
public class L003 {
    // slide window
    public int lengthOfLongestSubstring(String s) {
        int len = s.length();
        if (len == 0) return 0;
        int maxStr = 0;
        int left = 0;
        Map<Character, Integer> window = new HashMap<>();
        //
        for (int i = 0; i < len; i++) {
            if (window.containsKey(s.charAt(i))) {
                // update left boundary
                left = Math.max(left, window.get(s.charAt(i)) + 1);
            }
            window.put(s.charAt(i), i);
            maxStr = Math.max(maxStr, i - left + 1);
        }
        return maxStr;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        L003 l = new L003();
        System.out.print(l.lengthOfLongestSubstring(br.readLine()));
    }
}
