#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cctype>
#include <vector>
using namespace std;

const int maxLength = 8; // maximum number of characters in a name string.
typedef string namestring;
std::vector<namestring> namestrings;
typedef int name;

int main(int argc, char **argv)
// If this program is put in a file called small.cc, it can
// be compiled with the command  g++ -g -o small small.cc
{
  ifstream inf; // input file
  char ch;      // current character
  bool eofile;  // true when end of file is reached

  if (argc != 2) {
    cout << "Usage:         " << argv[0] << " [filename]" << endl;
    exit(1);
  }

  inf.open(argv[1]);
  if (!inf) {
    cout << "Error: cannot open file " << argv[1] << " for reading" << endl;
    exit(1);
  }

  eofile = !inf.get(ch); // get first character

  while (!eofile) {
    if (isspace(ch)) cout << '.';
    else cout << ch;
    eofile = !inf.get(ch); // get next character
  }

  inf.close();
}

void skipspaces(ifstream *infp, char &church, bool &eofile){
	while (!eofile) {
		if (isspace(church)){
			eofile = !(*infp.get(church)); // get next character
		}else{	//valid non-whitespace char found.
			return;
		}
	}
}

void getnumber(ifstream *infp, char &church, bool &eofile, int &number){
	string str = "";
	while (!eofile) {
		if (isDigit(church)){
			str = str + church;
			eofile = !(*infp.get(church)); // get next character
		}else{	//valid non-digit character.
			number = stoi(str)
			return;
		}
	}
	number = stoi(str)
	return;
}

void getname(ifstream *infp, char &church, bool &eofile, namestring &str){
	str = "";
	while (!eofile) {
		if (isDigit(church) || isLetter(church)){
			if (str.length <= 8){
				str = str + church;
			}else{	//string longer than 8 chars - generate a warning message.
				cout << "Warning message - string longer than 8 characters." << endl;
			}
			eofile = !(*infp.get(church)); // get next character
		}else{	//valid non-digit character.
			return;
		}
	}
}

name lookup(namestring str){
	for (int i=0; i<namestrings.length(); i++){
		if (str == namestrings[i]){
			return i;
		}
	}
	//if here - namestring not found in the program's namestrings vector - append it to the vector.
	namestrings.push(str);
	return (namestrings.length() - 1);
}

void printNameTable(){
	cout << endl; 
	cout << "Printing entire contents of the program name table." << endl;
	for (int i=0; i<namestrings.length(); i++){
		if (i>0){
			cout << " , ";
		}
		cout << namestrings[i];
	}
	cout << endl;
	cout << endl;
}	

bool isDigit(char c){
	switch (c){  
        case '0':  
			return true;
        break;  
		case '1':  
			return true;
        break;  
		case '2':  
			return true;
        break;  
		case '3':  
			return true;
        break;  
		case '4':  
			return true;
        break;  
		case '5':  
			return true;
        break;  
		case '6':  
			return true;
        break;  
		case '7':  
			return true;
        break;  
		case '8':  
			return true;
        break;  
		case '9':  
			return true;
        break;  
        default:  
			return false;
     }  
}
bool isLetter(char c){
	switch (c){  
        case 'a':  
			return true;
        break;  
		case 'b':  
			return true;
        break;  
		case 'c':  
			return true;
        break;  
		case 'd':  
			return true;
        break;  
		case 'e':  
			return true;
        break;  
		case 'f':  
			return true;
        break;  
		case 'g':  
			return true;
        break;  
		case 'h':  
			return true;
        break;  
		case 'i':  
			return true;
        break;  
		case 'j':  
			return true;
        break;  
		case 'k':  
			return true;
        break;  
		case 'l':  
			return true;
        break;  
		case 'm':  
			return true;
        break;  
		case 'n':  
			return true;
        break;  
		case 'o':  
			return true;
        break;  
		case 'p':  
			return true;
        break;  
		case 'q':  
			return true;
        break;  
		case 'r':  
			return true;
        break;  
		case 's':  
			return true;
        break;  
		case 't':  
			return true;
        break; 
		case 'u':  
			return true;
        break;  
		case 'v':  
			return true;
        break;  
		case 'w':  
			return true;
        break;  
		case 'x':  
			return true;
        break;  
		case 'y':  
			return true;
        break;  
		case 'z':  
			return true;
        break; 

		case 'A':  
			return true;
        break;  
		case 'B':  
			return true;
        break;  
		case 'C':  
			return true;
        break;  
		case 'D':  
			return true;
        break;  
		case 'E':  
			return true;
        break;  
		case 'F':  
			return true;
        break;  
		case 'G':  
			return true;
        break;  
		case 'H':  
			return true;
        break;  
		case 'I':  
			return true;
        break;  
		case 'J':  
			return true;
        break;  
		case 'K':  
			return true;
        break;  
		case 'L':  
			return true;
        break;  
		case 'M':  
			return true;
        break;  
		case 'N':  
			return true;
        break;  
		case 'O':  
			return true;
        break;  
		case 'P':  
			return true;
        break;  
		case 'Q':  
			return true;
        break;  
		case 'R':  
			return true;
        break;  
		case 'S':  
			return true;
        break;  
		case 'T':  
			return true;
        break; 
		case 'U':  
			return true;
        break;  
		case 'V':  
			return true;
        break;  
		case 'W':  
			return true;
        break;  
		case 'X':  
			return true;
        break;  
		case 'Y':  
			return true;
        break;  
		case 'Z':  
			return true;
        break;  

        default:  
			return false;
     }  
}
