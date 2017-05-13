#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cctype>
using namespace std;

//Tested successfully. Prints text file removing all whitespace.

//Prototype function definitions.
void skipspaces(ifstream *infp, char &curch, bool &eofile);

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
    skipspaces(&inf, ch, eofile);
	if (!eofile){
		cout << ch;
	}
    eofile = !inf.get(ch); // get next character
  }

  inf.close();
}

void skipspaces(ifstream *infp, char &curch, bool &eofile){
	while (!eofile) {
		if (isspace(curch)){
			//Character is whitespace. Get the next char from the input stream.
			eofile = !(*infp).get(curch); 
		}else{	
			//Character is not whitespace. Return program flow to calling procedure.
			return;
		}
	}
}
