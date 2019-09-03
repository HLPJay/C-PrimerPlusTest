
#include <iostream>
#include <fstream>
//读取第一个文件写入到第二个文件
int main(int argc, char* argv[])
{
	using namespace std;
	if(argc <4)
	{
		cout<<"Usage: "<<argv[0]<<" fileInname1 fileInname2 fileOutname1 .\n.";
		exit(EXIT_FAILURE);
	}

    ifstream fin(argv[1], ios_base::in);
    if (!fin)
    {
        cerr << "Cant't open" << argv[1] << " for input" << endl;
        exit(EXIT_FAILURE);
    }

    ifstream fin1(argv[2], ios_base::in);
    if (!fin1)
    {
        cerr << "Can't open" << argv[2] << " for output" << endl;
        exit(EXIT_FAILURE);
    }

    ofstream fout(argv[3], ios_base::in);
    if (!fout)
    {
        cerr << "Can't open" << argv[2] << " for output" << endl;
        exit(EXIT_FAILURE);
    }



    string ss;
    string ss1;
    while(!fin.eof() && !fin1.eof())
    {
    	getline(fin, ss, '\n');
        getline(fin1, ss1, '\n');
    	fout<<ss<<' '<<ss1<<'\n';
    }

    while(!fin.eof())
    {
        getline(fin, ss, '\n');
        fout<<ss<<'\n';
    }

    while(!fin1.eof())
    {
        getline(fin, ss, '\n');
        fout<<ss<<'\n';
    }


    fin.close();
    fin1.close();
    fout.close();
	return 0;
}