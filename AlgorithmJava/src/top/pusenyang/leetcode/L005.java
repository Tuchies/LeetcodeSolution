package top.pusenyang.leetcode;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

/**
 * 给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为 1000。
 *
 * 示例 1：
 *
 * 输入: "babad"
 * 输出: "bab"
 * 注意: "aba" 也是一个有效答案。
 *
 */
public class L005 {
    public int expand(String s, int left, int right) {
        // 计算以left和right为中心的回文串长度
        while (left >= 0 && right < s.length() && s.charAt(left) == s.charAt(right)) {
            left --;
            right ++;
        }
        // 返回长度
        return right - left - 1;
    }

    public String longestPalindrome(String s) {
        int len = s.length();
        if (len < 1) return "";

        int start = 0, end = 0;
        for (int i = 0; i < len; i++){
            // 一个元素为中心
            int len1 = expand(s, i, i);
            // 两个元素为中心
            int len2 = expand(s, i, i + 1);
            // 取最长
            int maxLen = Math.max(len1, len2);
            if (end - start < maxLen) {
                // 找到该回文串的起始点
                start = i - (maxLen - 1) / 2;
                // 找到该回文串的终点
                end = i + maxLen / 2;
            }
        }
        return s.substring(start, end+1);
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String tmp  = br.readLine();
        L005 l = new L005();
        l.longestPalindrome(tmp);
    }
}
