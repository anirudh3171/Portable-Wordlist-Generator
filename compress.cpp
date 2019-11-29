#include<iostream>
#include<bits/stdc++.h>
#include "word_gen_main.h"
using namespace std;

string lower = "abcdefghijklmnopqrstuvwxyz", upper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ", numbers = "1234567890", special = "_-+=!$%?*()^@#?/\\{}[]~";
long int max_filesize=5000000;

int deleteFile(char * fname)
{
	system("clear");
	int status;
	status=remove(fname);
	if(status==0)
	{
		cout<<"file "<<fname<<" deleted successfully..!!\n";
	}
	else
	{
		cout<<"Unable to delete file "<<fname<<"\n";
		perror("Error Message ");
	}
return 1;
	}
int main()
{
    int max_limit, min_limit;
    string list,l="", resume;

    FILE *op_file;
    bool will_out = false;

    int cnt = 1;
    cout<<"\nEnter max length : ";
    cin>>max_limit;
    cout<<"\nEnter min length : ";
    cin>>min_limit;
    cout<<"Enter \"l\" for Lowercase, \"u\" for Uppercase, \"n\" for numbers, \"s\" for symbols, \"x\" for customized characterset  \"lu\" for lower and upercase"<<endl;
    cout<<"\nEnter character set :";
    cin>>l;
    string pch;
    for(int i = 0; i < l.size(); i++)
      {
        pch = l[i];

        if(pch == "u") list += upper;
        else if(pch == "l") list += lower;
        else if(pch == "n") list += numbers;
        else if(pch == "s") list += special;
        else if(pch == "x")
        {
            cout<<"Enter customized characterset: ";
            cin>>list;
        }
      }

    if(max_limit > 0 && min_limit > 0 && min_limit <= max_limit && list.size() != 0)
    {
        printf("\nChoice of Letters Size: %i\n\n  Generating Word List...\n", list.size());

        Word_Gen_main gen(max_limit, min_limit, list);
        long double  total = 0;
        int cur = 0;

        if(!resume.empty())
        {
            total = gen.resume(resume);
        }
        else
        {
            for(int a = max_limit; a >= min_limit; a--)
            total += pow((double)list.size(), a);
        }
        int fno=(total/max_filesize)+1;

        cout<<fno<<endl;

        string str = gen.next();
        int c=0;
        string file;
        int f=1;

        while(f<=fno)
        {
            c=0;
            string val = "file"+to_string(cnt)+".txt";

            op_file = fopen(val.c_str(), "w");
            if(op_file != NULL)
            {
                will_out = true;
            }
            while(!str.empty())
            {
                c++;
                if(will_out)
                {
                    fprintf(op_file, "%s\n", str.c_str());
                }

                str = gen.next();

                if(c==max_filesize)
                {
                    break;
                }
            }
            file = "7z a archive" +to_string(cnt) +".zip " + val ;
            const char *command = file.c_str();
            system(command);
            string finalcmd = "7z a archive.zip archive" + to_string(cnt) + ".zip";
            const char *archivecmd = finalcmd.c_str();
            system(archivecmd);
            f++;
            cnt++;
        }
        cout<<total;
        if(will_out)
        {
        fclose(op_file);
        }
    }
    int count=1;
    while(count!=cnt)
    {
    string fname="file"+to_string(count)+".txt";
    char fname1[fname.length()+1];
    strcpy(fname1, fname.c_str());
    deleteFile(fname1);
    fname="archive"+to_string(count)+".zip";
    fname1[fname.length()+1];
    strcpy(fname1, fname.c_str());
    deleteFile(fname1);
    count++;
    }
}
