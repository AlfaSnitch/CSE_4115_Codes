#include<bits/stdc++.h>
using namespace std;

string encryption(string m,int key){
    for(int i=0; i<m.size(); i++){
        char c = m[i];
        if(c>= 'a' && c<= 'z'){
            m[i] = char((c-'a' + key)%26+'a');
            // to change case just use c - 'a' +'A'
        }
        else if(c>='A' && c<='Z'){
            m[i] = char((c-'A'+key)%26 +'A');
        }
        else if(c>='0' &&c<='9'){
            m[i] = char((c-'0'+key)%10+'0');
        }
        else continue;
    }
    return m;
}
string decryption(string m,int key){
    for(int i=0; i<m.size(); i++){
        char c = m[i];
        if(c>= 'a' && c<= 'z'){
            m[i] = char((c-'a' - key+26)%26+'a');
        }
        else if(c>='A' && c<='Z'){
            m[i] = char((c-'A'-key+26)%26 +'A');
        }
        else if(c>='0' &&c<='9'){
            m[i] = char((c-'0'-key+10)%10+'0');
        }
        else continue;
    }
    return m;
}

int main()
{
    // for string input
    /*
      string s;
      getline(cin,s);
    */

    string m = "a b c A B xyz 9 XY";
    string enc = encryption(m,3);
    string dec = decryption(enc,3);
    cout<<enc<<endl<<dec<<endl;
    return 0;

}
