#include<iostream>
#include<conio.h>
#include<ctime>
#include<fstream>
#include<string>

using namespace std;

/*
int convertLowercase(string s)
{
    for(int i=0;i<s.length();i++)
        {
            if(s[i]>='A' && s[i]<='Z')
            {
                s[i]=s[i]+32;
            }
            if(s[i]>=33 && s[i]<=47 || s[i]>=58 && s[i]<=63)
            {
                s.erase(i,1);
            }

        }
        return s;
}
*/
bool checkemail(string s)
{
    for(int i=0;i<s.length();i++)
    {
        if(s[i]=='@')
            return true;
    }
    return false;
}

int getanswerNumber(string s,string questions[])
{
    for(int i=0;i<s.length();i++)
    {
        if(s==questions[i])
            return i;
    }
     return -1; //cout<<answer[i]; in the answer statement
}

bool checkNumber(string s)
{
for(int i=0;i<s.length();i++)
{
    if(s[i]>=48 && s[i]<=57)
       return true;
}
return false;
}



int main()
{


int hour,min1,sec; //total time output





    time_t t=time(0);
    tm* tmp = localtime(&t);
    hour=tmp->tm_hour;
    min1=tmp->tm_min;
    sec=tmp->tm_sec;

ofstream file("details.txt");
string email,number,name;
cout<<"Welcome to Chatbot, What is your good name?"<<endl;
cin>>name;
cout<<"Hello,"<<name<<", It's "<<hour<<":"<<min1<<":"<<sec<<endl;
cout<<"Please enter your phone number:"<<endl;
cin>>number;
int l=checkNumber(number);
if(l==0)
{
while(l==0);
{
cout<<"Number should contain only Digits"<<endl;
cin>>number;
l=checkNumber(number);
}
}
cout<<"Please confirm your phone number y/n "<<number<<endl;
string yesNo;
cin>>yesNo;
if(yesNo=="y" || yesNo=="Y")
    cout<<"Thanks for confirming"<<endl;
else
{
cout<<"Enter your Number again:"<<endl;
cin>>number;
l=checkNumber(number);
if(l==0)
{
while(l==0);
{
cout<<"Number should contain only Digits"<<endl;
cin>>number;
l=checkNumber(number);
}
}

}
cout<<"Enter your Email-Id:"<<endl;
cin>>email;
while(checkemail(email)==false)
{
cout<<"Email should contain '@', Enter Valid Email"<<endl;
cin>>email;
checkemail(email);
}

string questions[100007]={0};
string answers[100007]={0};

string sentence;
cout<<"*********************************"<<endl;

cout<<"*********************************"<<endl;
cout<<"        Chat starts here        "<<endl;

cout<<"*********************************"<<endl;

cout<<"*********************************"<<endl;
do
{
    cout<<"Say something! Human!!"<<endl;

    getline(cin,sentence);
    l=getanswerNumber(sentence,questions);

    if(l==-1)
    {   string yesNo2;
        cout<<"Do you want me to search Internet for that?(y/n)";
        cin>>yesNo2;

            if(yesNo == "y")
            {
                cout<<"Okay, Here you go!"<<endl;
                string google="https://www.google.com/";
                string lol=google+sentence;
                system("start https://www.google.com/");

            }
                else
            {
                cout<<"That is fine, write exit if you want to exit out of the Chatbox"<<endl;
            }

    }
    else
    {
        cout<<answers[l];
    }

}
while(sentence!="exit");

    cout<<"I hope that I was of some help :)"<<endl;

cout<<"*********************************"<<endl;

cout<<"*********************************"<<endl;
cout<<"        Chat Ends here        "<<endl;

cout<<"*********************************"<<endl;

cout<<"*********************************"<<endl;

std::ofstream outfile;
outfile.open("haxx.txt", std::ios_base::app); // append instead of overwrite
outfile<<endl;
outfile<<"Name:"<<name<<endl;
outfile<<"Number:"<<number<<endl;
outfile<<"Email:"<<email<<endl;


    return 0;
}
