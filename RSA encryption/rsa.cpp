#include<bits/stdc++.h>
#include<boost/multiprecision/cpp_int.hpp>
#include<boost/random.hpp>

using namespace std;
using namespace boost::multiprecision;

cpp_int getRandomR(cpp_int &n){
    boost::random::mt19937 gen(static_cast<unsigned int>(time(nullptr)));
    boost::random::uniform_int_distribution<cpp_int> dist(3,n-1);
    return dist(gen);
}

cpp_int modInv(cpp_int A, cpp_int M){
    cpp_int m0 = M;
    cpp_int y=0,x=1;

    if(M==0) return 0;

    while(A>1){
        cpp_int t=M;
        cpp_int q = A/M;

        M = A%M;
        A = t;
        t = y;

        y = x - q*y;
        x = t;
    }
    if(x<0) x+=m0;
    return x;
}

cpp_int power(cpp_int b, cpp_int p,cpp_int mod){
    b = b%mod;
    if(p==0) return 1;

    cpp_int j = power(b,p/2,mod);

    j = (j*j) % mod;
    if(p%2==1){
        j = (j*b) % mod;
    }
    return j;
}

cpp_int egcd(cpp_int a, cpp_int b){
    if(a==0) return b;
    return egcd(b%a,a);
}

int main(){
    cpp_int e,d,phi,m,n;

    cpp_int p("656692050181897513638241554199181923922955921760928836766304161790553989228223793461834703506872747071705167995972707253940099469869516422893633357693");
    cpp_int q("204616454475328391399619135615615385636808455963116802820729927402260635621645177248364272093977747839601125961863785073671961509749189348777945177811");

    n = p*q;
    phi = (p-1)*(q-1);

    e = getRandomR(phi);
    while(egcd(e,phi)!=1){
        e = getRandomR(phi);
    }

    d = modInv(e,phi);

    cpp_int enc,dec;

    //message
    m = 12;

    //encryption
    enc = power(m,e,n);

    //decryption
    dec = power(enc,d,n);

    cout<<enc<<endl<<dec<<endl;

    return 0;
}













