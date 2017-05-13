#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cctype>
#include <string>
using namespace std;

//Tested successfully. Prints numbers from text file.

//Prototype function definitions.
void skipNonDigits(ifstream *infp, char &curch, bool &eofile);
void getnumber(ifstream *infp, char &curch, bool &eofile, int &number);
bool isDigit(char c);


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

  int number;	// the variable getnumber function reads the number into.
  while (!eofile) {
    skipNonDigits(&inf, ch, eofile);
	if (!eofile){
		getnumber(&inf, ch, eofile, number);
		cout << number << endl;
	}
  }

  inf.close();
}

void skipNonDigits(ifstream *infp, char &curch, bool &eofile){
	while (!eofile) {
		if (!isDigit(curch)){
			//Character is a non-digit. Get the next char from the input stream.
			eofile = !(*infp).get(curch); 
		}else{	
			//Character is a digit. Return program flow to calling procedure.
			return;
		}
	}
}

void getnumber(ifstream *infp, char &curch, bool &eofile, int &number){
	string bufferNumberString = "";
	while (!eofile) {
		if (isDigit(curch)){
			//Character is a digit. Add character to bufferNumberString, update return number, get the next char from the input stream.
			bufferNumberString = bufferNumberString + curch;
			number = stoi(bufferNumberString);
			eofile = !(*infp).get(curch); 
		}else{	
			//Character is not a digit - end of number has been reached. Return program flow to calling procedure.
			return;
		}
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