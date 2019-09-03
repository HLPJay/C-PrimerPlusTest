

#include <iostream>
#include <fstream>
//读取第一个文件写入到第二个文件
int main(int argc, char* argv[])
{
	using namespace std;
	if(argc <3)
	{
		cout<<"Usage: "<<argv[0]<<" filename1 filename2.\n.";
		exit(EXIT_FAILURE);
	}

    ifstream fin(argv[1], ios_base::in);
    if (!fin)
    {
        cerr << "Cant't open" << argv[1] << " for input" << endl;
        exit(EXIT_FAILURE);
    }

    ofstream fout(argv[2], ios_base::out);
    if (!fout)
    {
        cerr << "Can't open" << argv[2] << " for output" << endl;
        exit(EXIT_FAILURE);
    }

    // char ch;
    // while(!fin.eof())
    // {
    // 	fin.get(ch);
    // 	fout.put(ch);
    // }

    string ss;
    while(!fin.eof())
    {
    	getline(fin, ss, '\n');
    	// fin>>ss; //TODO 这里如果文件末尾是个空行就会有问题
    	fout<<ss<<'\n';
    	// fout.put('\n');
    }

    fin.close();
    fout.close();
	return 0;
}