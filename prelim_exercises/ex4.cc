#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cctype>
#include <string>
using namespace std;

//Tested successfully. Prints names of max length 8 chars from a text file.

//Constants and typedefs.
const int maxlength = 8; // maximum number of characters in a name string.
typedef string namestring;

//Prototype function definitions.
void skipNonLetters(ifstream *infp, char &curch, bool &eofile);
void getname(ifstream *infp, char &curch, bool &eofile, namestring &str);
bool isDigit(char c);
bool isLetter(char c);


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

  namestring ns;	// the variable getname function reads the namestring into.
  while (!eofile) {
    skipNonLetters(&inf, ch, eofile);
	if (!eofile){
		getname(&inf, ch, eofile, ns);
		cout << ns << endl;
	}
  }

  inf.close();
}

void skipNonLetters(ifstream *infp, char &curch, bool &eofile){
	while (!eofile) {
		if (!isLetter(curch)){
			//Character is not a letter. Get the next char from the input stream.
			eofile = !(*infp).get(curch); 
		}else{	
			//Character is a letter. Return program flow to calling procedure.
			return;
		}
	}
}

void getname(ifstream *infp, char &curch, bool &eofile, namestring &str){
	str = "";
	string fullLengthStr = "";
	bool truncationWarningFlag = false;
	while (!eofile) {
		if (isDigit(curch) || isLetter(curch)){
			//Character is a digit/letter. Add character to output string (provided shorter than max output length), get the next char from the input stream.
			fullLengthStr = fullLengthStr + curch;
			if (str.length() < maxlength){
				str = str + curch;
			}else{	
				//Additional character would make string length greater than maxlength. Don't add, and trigger the warning flag.
				truncationWarningFlag = true;
			}
			eofile = !(*infp).get(curch); 
		}else{	
			//Character is not a digit/letter - end of name has been reached. Output warning message if name truncated. Return program flow to calling procedure.
			if (truncationWarningFlag == true){
				cout << "Warning: name '" << fullLengthStr << "' was truncated." << endl;
			}
			return;
		}
	}
	//if here then eofile reached. Check for truncation warning.
	if (truncationWarningFlag == true){
		cout << "Warning: name '" << fullLengthStr << "' was truncated." << endl;
	}
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