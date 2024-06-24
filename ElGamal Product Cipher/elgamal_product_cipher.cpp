#include<bits/stdc++.h>
#include<boost/multiprecision/cpp_int.hpp>
#include<boost/random.hpp>

using namespace std;
using namespace boost::multiprecision;

cpp_int power(cpp_int b,cpp_int p,cpp_int mod){
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

cpp_int modInv(cpp_int a,cpp_int m){
    cpp_int m0=m,y=0,x=1;
    if(m==1) return 0;
    while(a>1){
        cpp_int q = a/m;
        cpp_int t = m;

        m = a%m;
        a = t;
        t = y;

        y = x- q*y;
        x = t;
    }
    if(x<0) x+=m0;
    return x;
}

cpp_int pow1(cpp_int x,cpp_int y){
    cpp_int tmp;
    if(y==0) return 1;

    tmp = pow1(x,y/2);

    if(y%2==0) return tmp*tmp;
    else{
        if(y>0)
            return x*tmp*tmp;
        else
            return tmp*tmp/x;
    }
}

cpp_int getRandomr(cpp_int n){
    boost::random::mt19937 gen(static_cast<unsigned int> (time(nullptr)));
    boost::random::uniform_int_distribution <cpp_int> dist(1,n-2);
    return dist(gen);
}

void encryption(cpp_int p,cpp_int m,cpp_int g,cpp_int beta, cpp_int &c1,cpp_int &c2){
    cpp_int r = getRandomr(p);
    c1 = power(g,r,p);
    c2 = (m%p) * power(beta,r,p);
}
cpp_int decryption(cpp_int p,cpp_int a, cpp_int &c1,cpp_int &c2){
    cpp_int t,mi,dec;
    t = pow1(c1,a);
    mi = modInv(t,p);
    dec = (c2*mi)%p;
    return dec;
}

int main()
{
    cpp_int p("212559481678916012965440078089");

    cpp_int g,a,beta,c11,c22,c12,c21,m1,m2;

    // key generation
    g = 2;
    a = getRandomr(1234);

    beta = power(g,a,p);

    //message
    m1 = 12;
    m2 = 10;

    //encryption
    encryption(p,m1,g,beta,c11,c12);
    encryption(p,m2,g,beta,c21,c22);

    //product
    cpp_int c1,c2;
    c1 = c11*c21;
    c2 = c12*c22;

    //decrytion
    cpp_int dec;
    dec = decryption(p,a,c1,c2);

    cout<<dec<<endl;

    return 0;
}
