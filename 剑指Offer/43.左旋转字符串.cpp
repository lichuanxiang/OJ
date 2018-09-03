/*
	题目描述：
	汇编语言中有一种移位指令叫做循环左移（ROL），现在有个简单的任务，就是用字符串模拟这个指令的运算结果。
	对于一个给定的字符序列S，请你把其循环左移K位后的序列输出。例如，字符序列S=”abcXYZdef”,
	要求输出循环左移3位后的结果，即“XYZdefabc”。是不是很简单？OK，搞定它！
*/
class Solution {
public:
    string LeftRotateString(string str, int n) {
        int len = str.size();
        if(len == 0) return str;
        n %= len;
        for(int i=0, j=n-1; i<j; i++, j--) swap(str[i], str[j]);
        for(int i=n, j=len-1; i<j; i++, j--) swap(str[i], str[j]);
        for(int i=0, j=len-1; i<j; i++, j--) swap(str[i], str[j]);
        return str;
    }
};
    /*string LeftRotateString(string str, int n) {
        int len = str.length();
        if(len==0) return "";
        if(n==0) return str;
        n = n%len;
        str += str;
        return str.substr(n, len);
    }*/
