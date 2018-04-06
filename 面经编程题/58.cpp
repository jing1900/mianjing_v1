//合法符号匹配
#include<iostream>
using namespace std;
class Parenthesis {
public:
    bool chkParenthesis(string A, int n) {
        // write code here
        int c = 0;
        for(int i=0;i<n;i++)
        {
            if(A[i] == '(')
                c++;
            else if(A[i] == ')')
                c--;
            else
            {
                if(c<=0) return false;
            }       
            if(c<0)
                return false;
        }
        if(c == 0)
            return true;
        else
            return false;
        
    }
};
int main()
{
	string s = "()a()()";
	Parenthesis p;
	bool b = p.chkParenthesis(s,7);
	cout<<b<<endl;
}
