#include <string>
#include <iostream>
using namespace std;
string strTostr(string str)
{
    int cnt = 1;
    string result;

    for(int i = 0; i < str.length() -1 ; i++)
    {
        if (str[i]==str[i+1]) 
        {
            cnt++;
        }
        else
        {

            result=result + to_string(cnt);
            result=result + str[i];
            cnt = 1;
        }
    }
    
    result=result + to_string(cnt);
    result=result + str[str.length() -1];
    return result;
}

string countAndSay(int n) {
    string str;
    if (n==0) return str;
    
    str = "1";
    //if (n==1) return str;
    for (int i = 1; i <= n; i++)
    {
    	
        str = strTostr(str);
    }
    return str;
}

int main(int argc, char** argv)
{
	//string str("11");
	cout << countAndSay(atoi(argv[1]))<< "\n";
	return 0;
}
