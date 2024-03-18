// CheckSum
#include <bits/stdc++.h>

using namespace std;

string OnesComplement(string result)
{
    for(int i=0;i<result.length();i++)
    {
        if(result[i]=='0')
        {
            result[i]='1';
        }
        else
        {
            result[i]='0';
        }
    }
    return result;
}

string CheckSum(string data,int block_length)
{
    int n=data.length();
    if((n%block_length)!=0)
    {
        int pad_length=n-(n%block_length);
        for(int i=0;i<pad_length;i++)
        {
            data='0'+data;
        }
    }
    string result="";
    for(int i=0;i<block_length;i++)
    {
        result=result+data[i];
    }
    for(int i=block_length;i<n;i=i+block_length)
    {
        string next_block="";
        for(int j=i;j<i+block_length;j++)
        {
            next_block= next_block + data[j];
        }
            string addition="";
            int sum,carry;
            sum=carry=0;
        for(int k=block_length-1;k>=0;k--)
        {
            sum=sum+(result[k]-'0')+(next_block[k]-'0');
            carry=sum/2;
            if(sum==0)
            {
                addition='0'+addition;
                sum=carry;
            }
            else if(sum==1)
            {
                addition='1'+addition;
                sum=carry;
            }
            else if(sum==2)
            {
                addition='0'+addition;
                sum=carry;
            }
            else
            {
                addition='1'+addition;
                sum=carry;
            }
        }
        string final_val="";
        if(carry==1)
        {
            for(int l=addition.length()-1;l>=0;l--)
            {
                if(carry==0)
                {
                    final_val=addition[l]+final_val;
                }
                else if(((addition[l]-'0')+carry)%2==0)
                {
                    final_val='0'+final_val;
                    carry=1;
                }
                else
                {
                    final_val='1'+final_val;
                    carry=0;
                }
            }
            result=final_val;
        }
        else
        {
            result=addition;
        }
    }
    return OnesComplement(result);
}

bool Checker(string sent_message,string recieved_message,int block_length)
{
    string send_checksum=CheckSum(sent_message,block_length);
    cout<<endl;
    cout<<send_checksum<<endl;
    string recieve_checksum=CheckSum(recieved_message+send_checksum,block_length);
    cout<<endl;
    cout<<recieve_checksum<<endl;
    if(count(recieve_checksum.begin(),recieve_checksum.end(),'0')==block_length)
    {
        return true;
    }
    else
    {
        return false;
    }
}


int main()
{
    string sent_message,recieved_message;
    int block_length;
    cout<<"enter the sent message:"<<endl;
    cin>>sent_message;
    cout<<"enter the recieved message:"<<endl;
    cin>>recieved_message;
    cout<<"enter the block size:"<<endl;
    cin>>block_length;
    if(Checker(sent_message,recieved_message,block_length))
    {
        cout<<"No Error"<<endl;
    }
    else
    {
        cout<<"Error"<<endl;
    }

    return 0;
}

// 10000101011000111001010011101101
// 10000101011000111001010011101101
// 8