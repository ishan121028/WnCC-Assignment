#include<iostream>
#include<fstream>
#include<string>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    fstream myFile;
    string line[22];
    int start_time[22], dura[22],count = 0;
    myFile.open("Schedule.txt",ios::in);
    if(myFile.is_open()){
        
        for(int i=0;i<22;i++)
        {   
            getline(myFile, line[i]);
        }
    }
    for(int i=0;i<22;i++)
    {
        start_time[i] = (line[i][5]-48)*10 + (line[i][6]-48);
        dura[i] = line[i][8]-48;
    }
    vector < int  > start_time_1,start_time_2;
    for(int i=0;i<22;i++)
    {
        if(dura[i]==1)
        {
            start_time_1.push_back(start_time[i]);
        }
        else
        {
            start_time_2.push_back(start_time[i]);
        }
    }
    sort(start_time_1.begin(),start_time_1.end());
    sort(start_time_2.begin(),start_time_2.end());
    for(int i=0;i<start_time_1.size()-1;i++)
    {
        int time1,time2;
        int d=0;
        if(start_time_1[i+1]-start_time_1[i] >= 3)
        {
            d = start_time_1[i+1]-start_time_1[i];
            time1 = start_time[i]+1;
            time2 = start_time[i+1];
            while(d>1)
            {
                for(int j=0;j<start_time_2.size();j++)
                {
                    if(time1 == start_time_2[j])
                    {
                        count++;
                        time1 = time1 + 2;
                        d = time2-time1;
                    }
                }
            }
            
        }
    }
    for(int i=0;i<start_time_1.size();i++)
    {
        if(start_time_1[i] == start_time_1[i+1]) 
        {
            start_time_1[i+1] = 25;
        }
        if(start_time_1[i] < 25)
        {
            count++;
        }
    }
    cout<< count;
}
