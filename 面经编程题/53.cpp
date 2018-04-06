//https://www.nowcoder.com/questionTerminal/c3f30092999e42a9b2c36496693bd458?pos=83&orderByHotValue=0&difficulty=10000
//判断是否为旋转词
class Solution {
public:
	/**
	 *	判断str1是否是str2的旋转词
	 *	输入：字符串str1，字符串str2
	 *	返回：true代表str1是str2的旋转词；false代表不是
	 */
	bool isRotation(string str1, string str2) {
        if(str1.size() != str2.size())
            return false;
        string s = str2+str2;
        if(s.find(str1)!=string::npos)
            return true;
        return false;
    }
};
