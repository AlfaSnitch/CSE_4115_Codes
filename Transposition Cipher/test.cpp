#include<bits/stdc++.h>
using namespace std;

string encryption(string m,int klen,int mlen,int row, int col_val[]){
    //define encryption table
    char t[row+1][klen];
    int x =0;
    for(int i=0; i<row+1;i++){
        for(int j=0; j<klen; j++){
            if(x>=mlen) t[i][j] ='_';
            else t[i][j] = m[x];

            x++;
        }
    }

    int tt=1;
    string cipher ="";
    while(tt<klen){
        for(int i=0; i<klen; i++){
            int k = col_val[i];
            if(k==tt){
                for(int j=0; j<row+1; j++){
                    cipher+=t[j][i];
                }
                tt++;
            }
        }
    }
    cout<<cipher<<endl;
    return cipher;

}

void decryption(string cipher,int klen, int row, int col_val[]){
    int t=1,x=0;
    char dec_tab[row+1][klen];
    while(t<klen){
        for(int i=0; i<klen; i++){
            int k = col_val[i];
            if(k==t){
                for(int j=0; j<row+1; j++){
                    dec_tab[j][i] = cipher[x];
                    x++;
                }
                t++;
            }
        }
    }

    string decm="";
    for(int i=0; i<row+1; i++){
        for(int j=0; j<klen; j++){
            if(dec_tab[i][j]=='_'){
                dec_tab[i][j]=' ';
            }
            decm+=dec_tab[i][j];
        }
    }
    cout<<decm<<endl;
}

int main()
{
    string m = "geeks for geeks";
    string key = "hack";

    int mlen = m.length(),klen = key.length();

    int col_val[klen] = {0};
    int val=1,count=0,ind;
    while(count<klen){
        int min = 999;
        for(int i=0; i<klen; i++){
            if(min > int(key[i]) && col_val[i]==0){
                min = int(key[i]);
                ind = i;
            }
        }
        col_val[ind] = val;
        val++;
        count++;
    }

    int row = mlen/klen;

    string ci = encryption(m,klen,mlen,row,col_val);
    decryption(ci,klen,row,col_val);

}
