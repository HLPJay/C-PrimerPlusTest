

#include <iostream>
#include <fstream>

int main(int argc, char* argv[])
{
	using namespace std;
	if(argc == 1)
	{
		cout<<"Usage: "<<argv[0]<<" filename.\n.";
		exit(EXIT_FAILURE);
	}

	ofstream fout(argv[1], std::ios_base::out);
	char ch;
    while (cin.get(ch))
        fout.put(ch);

    if (cin.eof())//ctrl+d模拟文件结束
        cout << "\n It is EOF" << endl;
    else
    {
        std::cerr << "Unkonwn error" << endl;
        exit(EXIT_FAILURE);
    }

	return 0;
}