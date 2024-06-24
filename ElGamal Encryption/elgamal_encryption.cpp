#include<bits/stdc++.h>
#include<boost/multiprecision/cpp_int.hpp>
#include<boost/random.hpp>

using namespace std;
using namespace boost::multiprecision;

cpp_int pow1(cpp_int x,cpp_int y){
    cpp_int temp;
    if(y==0) return 1;

    temp = pow1(x,y/2);
    if(y%2==0){
        return temp*temp;
    }
    else{
        if(y>0){
            return x*temp*temp;
        }
        else{
            return temp*temp/x;
        }
    }
}

cpp_int getRandomR(cpp_int n){
    boost::random::mt19937 gen(static_cast<unsigned int>(time(nullptr)));
    boost::random::uniform_int_distribution<cpp_int> dist(1,n-2);
    return dist(gen);
}

cpp_int modInv(cpp_int a, cpp_int m){
    cpp_int m0=m,y=0,x=1;
    if(m==1) return 0;

    while(a>1){
        cpp_int q = a/m;
        cpp_int t = m;

        m = a%m;
        a = t;
        t = y;

        y = x-q*y;
        x = t;
    }
    if(x<0) x+=m0;
    return x;
}

cpp_int egcd(cpp_int a,cpp_int b){
    if(a==0) return b;
    return egcd(b%a,a);
}

cpp_int power(cpp_int b, cpp_int p, cpp_int mod){
    b = b%mod;
    if(p == 0) return 1;

    cpp_int j = power(b,p/2,mod);

    j = (j*j)%mod;
    if(p%2==1) j=(j*b)%mod;
    return j;
}

int main(){
    cpp_int p("656692050181897513638241554199181923922955921760928836766304161790553989228223793461834703506872747071705167995972707253940099469869516422893633357693");
    //cpp_int q("204616454475328391399619135615615385636808455963116802820729927402260635621645177248364272093977747839601125961863785073671961509749189348777945177811");

    cpp_int r,beta,g,a;

    //key generation: public(beta,g,p) private(a)
    g = 2; //primitive element
    r =  getRandomR(1234);
    a =  getRandomR(1234);

    beta = power(g,a,p);

    // message
    cpp_int m = 1233;

    // encryption
    cpp_int c1,c2;
    c1 = power(g,r,p);
    c2 = (m%p) * power(beta,r,p);

    // decryption
    cpp_int dec,t,mi;
    t = pow1(c1,a);
    mi = modInv(t,p);
    dec = (c2*mi) % p;

    cout<<dec<<endl;

    return 0;
}
