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

int main()
{
    cpp_int p("212559481678916012965440078089");

    cpp_int a,g,beta,k,r,s;

    //message
    cpp_int m = 190;

    //key generation
    g = 2;

    a = getRandomR(p);

    beta = power(g,a,p);



    //sigin
    k = getRandomR(p);
    while(egcd(k,p-1)!=1){
        k = getRandomR(p);
    }
    r = power(g,k,p);
    cpp_int t = modInv(k,p-1);
    s = ((m-r*a)*t)%(p-1);
    if(s<0) s+=p-1;


    cout<<r<<endl<<s<<endl;

    //verify
    cpp_int v1,v2;
    v1 = (power(beta,r,p) * power(r,s,p))%p;
    //v1 = (pow1(beta,r) * pow1(r,s))%p;
    v2 = power(g,m,p);

    cout<<v1<<endl<<v2<<endl;

    if(v1==v2) cout<<"success"<<endl;

    return 0;
}
