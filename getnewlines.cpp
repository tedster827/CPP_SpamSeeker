#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char const *argv[]) {
  ifstream fin;
  fin.open("messagefile.html");
  if(!fin) {
    cout << "File could not be opened." << endl;
    cout << "The most likely issue is that the file does not exist in " << endl;
    cout << "the current directory." << endl;
    // Exit Call (Error: -1)
    return -1;
  }
  char c;
  while(fin) {
    c = fin.get();
    if(c == '\n') {
      cout << "new line!" << endl;
    }
    else {
      cout << c << " ";
    }
  }
  // Exit Call (No Error: 0)
  return 0;
}
