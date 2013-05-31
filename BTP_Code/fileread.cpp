#include<iostream>
#include<fstream>
#include<string>
#include<vector>
//#include<libxl.h>
//using namespace libxl;
using namespace std;
class splitstring : public string {
    vector<string> flds;
public:
    splitstring(string s) : string(s) { };
    vector<string>& split(char delim, int rep=0);
};

// split: receives two char delimiter; returns a vector of strings
// By default ignores repeated delimiters, unless argument rep == 1.
vector<string>& splitstring::split(char delim, int rep) {
    if (!flds.empty()) flds.clear();  // empty vector if necessary
    string work = data();
    string buf = "";
    int i = 0;
    while (i < work.length()) {
        if (work[i] != delim)
            buf += work[i];
        else if (rep == 1) {
            flds.push_back(buf);
            buf = "";
        } else if (buf.length() > 0) {
            flds.push_back(buf);
            buf = "";
        }
        i++;
    }
    if (!buf.empty())
        flds.push_back(buf);
    return flds;
}

void read_file(string cur_timestamp_xac[][16])
{
ifstream fin("test.txt");
	string str;
	//string cur_timestamp_xac[3300][16];
	vector<string> flds;
	for(int i = 0; i<3200; i++) {
		//cout<<i<<endl;
		getline(fin, str, '\n');
		splitstring s(str);
		flds = s.split('\t', 1);
		for(int j = 0; j<15; j++) {
			cur_timestamp_xac[i][j] = flds[j];
			//cout<<cur_timestamp_xac[i][j]<<"..";
		}
		//cout<<endl;
}
}
	//cout<<str;


/*int main() {
	ifstream fin("test.txt");
	string str;
	string cur_timestamp_xac[3300][16];
	vector<string> flds;
	for(int i = 0; i<3200; i++) {
		//cout<<i<<endl;
		getline(fin, str, '\n');
		splitstring s(str);
		flds = s.split('\t', 1);
		for(int j = 0; j<15; j++) {
			cur_timestamp_xac[i][j] = flds[j];
		//	cout<<cur_timestamp_xac[i][j]<<"..";
		}
		//cout<<endl;
	}
	//cout<<str;
}*/
