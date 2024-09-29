#include<bits/stdc++.h>
using namespace std;
int kmp(string needle,string haystack){
	  if (needle == "") return 0;
        int n = needle.length();
        vector<int> lps(n,0);
        int prevLPS = 0;
        int i = 1;
        while(i<n){
            if(needle[i] == needle[prevLPS]){
                lps[i] = prevLPS+1;
                prevLPS+=1;
                i+=1;
            }else if(prevLPS == 0){
                lps[i] = 0;
                i+=1;
            }else{
                prevLPS = lps[prevLPS-1];
            }
        }
        i = 0;
        int j = 0;
        int m = haystack.length();
        while(i<m){
            if(haystack[i] == needle[j]){
                i+=1;
                j+=1;
            }else{
                if(j == 0){
                    i+=1;
                }else{
                    j = lps[j-1];
                }
            }
            if(j == n){
                return i-n;
            }
        }
        return -1;
}
int main(){
	string needle = "ll";
	string haystack = "hello World";
	int res = kmp(needle,haystack);
	cout<<res;//this is the first occurrence of "ll" at index res in the given haystack string;
	return 0;
}