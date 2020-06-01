/* Name     : Ritesh Bhadane
    Roll No   : PB19
    Batch     : B2
    Problem Statement : Implement simple asymmetric RSA key algorithm using python, java or C++
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long int
ll temp[100];
bool check_prime (ll n) {
    if(n<=1)
        return false;
    for(int i=2;i<=n;++i) {
        if(i%2==0)
            return false;
    }
    return true;
}
bool check_coprime (ll a, ll b) {
    if(__gcd(a,b)==1)
        return true;
    return false;
}
ll find_e (ll phi) {

    for(int i=2;i<phi;++i) {
        if(check_coprime(i,phi))
            return i;
    }
}

void encrypt (string s,ll e,ll n) {
    ll len=s.length (),i,k,c;
    for (i=0;i<len;++i) {
        k=(int)s[i]-96;
        c=1;
        //breaking the equation c = P^e mod n  using property (a*b)mod n = ((amodn)*(bmodn))modn
        for(ll j=0;j<e;++j) {
            c *= k;
            c %=  n;
        }
        temp[i]=c;
    }
    temp[i]=-99;

    cout<<"\nEnrypted message is : ";
    for(int i=0;temp[i]!=-99;++i) {
        cout<<temp[i];
    }
}

string decrypt (ll n, ll d) {
   string ans="";
   ll k,c;
   //Calculating data = c^dmodn using property (a*b)mod n = ((amodn)*(bmodn))modn
   for(int i=0;temp[i]!=-99;++i) {
        k=temp[i];
        c=1;
        for(int j=0;j<d;++j) {
            c *= k;
            c %= n;
        }
        ans += char(c+96);
   }
   return ans;
}
int main () {

    ll p,q,d,e,phi,n;
    string plain;
    cout<<"\nEnter the two prime numbers : ";
    cin>>p>>q;

    //Checking for prime
    while (check_prime(p) && check_prime(q)) {
        if (!check_prime(p) || !check_prime(q)) {
            cout<<"Entered numbers are not prime. Please reenter";
            cin>>p>>q;
        }
    }
    cout<<"\nEnter the plaintext : ";
    cin>>plain;
    n = p*q;
    phi = (p-1)*(q-1);
    //finding value of e(encrypt key) which is greater than 1 and less than phi
    e = find_e(phi);

    ll x;
    //finding value of d(decrypt key)
    for(int i=1;;++i) {
        x = 1 + phi*i;
        if(x%e==0) {
            d= x/e;
            break;
        }
    }
    //function to find encrypted message
    encrypt(plain,e,n);
    cout<<"\nDecrypted message is : "<<decrypt(n,d); //function to decrypt the message
}
