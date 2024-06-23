#include<bits/stdc++.h>
#include<boost/multiprecision/cpp_int.hpp>
#include<boost/random.hpp>

using namespace std;
using namespace boost::multiprecision;

cpp_int modInv(cpp_int a,cpp_int m){
    cpp_int m0 = m;
    cpp_int y=0,x=1;

    if(m==1) return 0;

    if(a>1){
        cpp_int q = a/m;
        cpp_int t = m;

        m = a%m;
        a = t;
        t = y;

        y = x - q*y;
        x = t;
    }
    if(x<0){
        x +=m0;
    }
    return x;
}

// b^p % mod = ??
cpp_int power(cpp_int b,cpp_int p,cpp_int mod){
    b = b%mod;
    if(p == 0) return 1;
    cpp_int j = power(b,p/2,mod);

    j = (j*j)%mod;
    if(p%2==1){
        j = (j*b)%mod;
    }
    return j;
}

cpp_int Egcd(cpp_int a,cpp_int b){
    if(a == 0)
        return b;
    return gcd(b%a,a);
}

int main(){

}
