#include<bits/stdc++.h>
#include<boost/multiprecision/cpp_int.hpp>

using namespace std;
using namespace boost::multiprecision;

cpp_int power(cpp_int b, cpp_int p, cpp_int mod){
    b = b%mod;
    if(p==0) return 1;
    cpp_int j = power(b,p/2,mod);

    j = (j*j) % mod;
    if(p%2==1){
        j = (b*j)%mod;
    }
    return j;
}

int main()
{
    cpp_int p = 67;

    vector<cpp_int> primitive;

    for(cpp_int i=1; i<=p-1; i++){
        map<cpp_int,cpp_int> mp;

        bool flag = true;
        for(cpp_int j = 1; j<p; j++){
            cpp_int ans = power(i,j,p);
            mp[ans]++;
            if(mp[ans]>1){
                flag = false;
                break;
            }
        }
        if(flag) primitive.push_back(i);
    }
    for(auto x:primitive){
        cout<<x<<" ";
    }

}
