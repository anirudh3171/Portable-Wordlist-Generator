#include<bits/stdc++.h>
using namespace std;

int deleteFile(char * fname)
{

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

void decompress()
{
int cnt=1;
ifstream fin;
char ch='y';
while(1)
    {
        if(ch=='y')
        {
        string val = "file"+to_string(cnt)+".txt";
        system(("7za e archive.zip archive"+to_string(cnt)+".zip").c_str());
        string file = "7za e archive"+to_string(cnt)+".zip";
    const char* filecmd = file.c_str();
    system(filecmd);
        cout<<"printing "<<val<<endl;
        cnt++;
//     fin.open(val);
//     string line;
//     cout<<val<<endl;
//     while(fin)
//         {
//             getline(fin,line);
//             cout<<line<<endl;
//         }
//        //  nfile--;
//          fin.close();
    }
    else
    {
     break;
    }
    cout<<"do you want to open second file?(y/n)"<<endl;
    cin>>ch;
       int cnt2=cnt-1;
        string valu = "file"+to_string(cnt2)+".txt";
        char fname1[valu.length()+1];
        strcpy(fname1, valu.c_str());
         deleteFile(fname1);
         string fileN="archive"+(to_string(cnt2))+".zip";
        fname1[fileN.length()+1];
        strcpy(fname1, fileN.c_str());
         deleteFile(fname1);
}
}

int main()
{
decompress();

}
