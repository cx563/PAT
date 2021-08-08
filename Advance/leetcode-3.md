##  3. 无重复字符的最长字串
### 题意描述  给定一个字符串`s`,请你找出其中不含有重复字符的 最长子串 的长度。 字串是连续的
### 输入输出格式  
s = "abcabcbb" 输出为 3 最长字串为`abc` 长度为3
### 数据规模  
0 <= s.length <= 5 * 1e4
### 算法设计  
此题的解法多种多样 这里采用双指针 和 滑动窗口的解法
双指针
此题需要我们枚举可能的区间 故设计两个指针 `start` `end` `start`负责维护区间的左端点，`end`负责维护区间的右端点
开始 两个指针都指向字符串起点 `end`不断后移 扩大区间 建立哈希表`unordered_map<char,bool>` 来维护区间的字符是否重复 
若`end`指向的字符在哈希表中对应的bool值为`true` 说明区间出现重复字符 此时，所以包含这两个重复字符的区间都不符合题意 
此时，应该使`start`右移 缩短区间 直到去除左端重复字符为止  
### c++代码  
```cpp
/*
双指针解法
*/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,bool> mp;
        int p1,p2;
        int len = s.size();
        int res=0;
        for(p1=0,p2=0;p2<len;){
            if(!mp[s[p2]]){
                mp[s[p2]]=true;
                p2++;
            }else{
                while(mp[s[p2]]==true){
                    mp[s[p1]]=false;
                    p1++;
                }
            }
            if(res < (p2-p1)) res=p2-p1;  // 这里很重要 必须每次枚举，都要更新答案
        }
        return res;
    }
};

/*
滑动窗口解法
*/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
      deque<char>de;
      unordered_map<char,bool>mp;
      int res=0;
      int len = s.size(); 
      for(int i=0;i<len;i++){
           while(mp[s[i]]== true){
                mp[de.back()]=false;
                de.pop_back();
            }
            de.push_front(s[i]);
            mp[s[i]]=true;
            if(res < de.size()) res = de.size();
       }
       return res;
    }
};
```
### [题目链接](https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/)  