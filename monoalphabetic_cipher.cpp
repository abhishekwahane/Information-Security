/*
Name : Ritesh Bhadane
Roll No. : PB19
Batch : B2
Problem Statement : Implement any classical cryptographic technique using python, Java or C++.
*/
#include <bits/stdc++.h>
using namespace std;
//Initalize function to create an array of alphabets from a-z.
void initalize(vector<char>&cipher) {
     for(int i=97;i<=122;i++)
        cipher.push_back(char(i));
}//end of function

int main()
{
    unsigned seed =0;
    string s;
    cout<<"\nEnter plaintext : ";
    cin>>s;
    vector<char>cipher;
    unordered_map<char,int>mp;
    unordered_map<char,char>mp1;
    int n = s.size();
    initalize(cipher);
    //creating a cipher array with shuffled alphabets
    shuffle(cipher.begin(),cipher.end(),default_random_engine(seed));
    //Mapping plaintext indices into map
    for(int i=0;i<n;i++)
        mp[s[i]]=i;

    string ciphertext="";
    for(int i=0;i<n;i++)
     {
        ciphertext += cipher[mp[s[i]]];
        mp1[cipher[mp[s[i]]]] = s[i];
    }
    cout<<"\nCipher Text : "<<ciphertext;

    string plaintext="";
    for(int i=0;i<n;i++)
     {
        plaintext += mp1[cipher[mp[s[i]]]];
    }
    cout<<"\nPlaintext : "<<plaintext;
}
