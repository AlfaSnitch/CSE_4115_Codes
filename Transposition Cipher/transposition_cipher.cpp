#include<bits/stdc++.h>
using namespace std;



int main(){

    string s = "geeks for geeks";
    string key = "hack";

    int k_len = key.size();
    int m_len = s.size();

    int row = ceil(1.0*m_len/k_len);

    int col_val[k_len]={0};
    int val =1,count =0,ind;
    while(count< k_len){
        int min = 999;
        for(int i =0; i<k_len; i++){
            if(min>int(key[i]) && col_val[i]==0){
                min = int(key[i]);
                ind = i;
            }
        }
        col_val[ind] = val;
        count++;
        val++;
    }

    //encryption
    char tab[row][k_len];
    int k=0;
    for(int i=0; i<row; i++){
        for(int j=0; j<k_len; j++){
            if(k>=m_len)
                tab[i][j]=' ';
            else{
                tab[i][j] = s[k];
            }
            k++;
        }
    }

    string cipher="";
    int t =1;
    while(t<k_len){
        for(int i=0; i<k_len; i++){
            int k = col_val[i];
            if(k==t){
                for(int j=0; j<row; j++){
                    cipher+=tab[j][i];
                }
                t++;
            }
        }
    }
    cout<<cipher<<endl;

    //decryption
    char dec[row][k_len];
    t = 1; int x=0;
    while(t<k_len){
        for(int i=0; i<k_len; i++){
            int k = col_val[i];
            if(k==t){
                for(int j=0; j<row; j++){
                    dec[j][i] = cipher[x];
                    x++;
                }
                t++;
            }
        }
    }

    string dec_s = "";
    for(int i=0; i<row; i++){
        for(int j=0; j<k_len; j++){
            dec_s+=dec[i][j];
        }
    }
    cout<<dec_s<<endl;

}
