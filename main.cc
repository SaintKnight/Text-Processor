#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "textprocess.h"
#include "echo.h"
#include "dropfirst.h"
#include "doublewords.h"
#include "allcaps.h"
#include "count.h"

using namespace std;

int main () {
  string s;

  while(1) {
    getline(cin,s);
    if (cin.fail()) break;
    istringstream iss(s);
    string fname;
    iss >> fname;
    istream *in = (fname == "stdin") ? &cin : new ifstream(fname.c_str());

    TextProcessor *tp = new Echo;
    string dec;
    
    while (iss >> dec) {
      if (dec == "dropfirst") {
        int n;
        iss >> n;
        tp = new DropFirst(tp, n);               // Construct a new DropFirst Class
      }
      else if (dec == "doublewords") {
        tp = new DoubleWords(tp);                // Construct a new DoubleWords Class
      }
      else if (dec == "allcaps") {
        tp = new AllCaps(tp);                    // Construct a new AllCaps Class
      }
      else if (dec == "count") {
        char c;
        iss >> c;
        tp = new Count(tp, c);                   // Construct a new Count Class
      }
   } 

   tp->setSource(in);

   string word;

   // A loop to get words one by one and doing the commands in order and display the edited words.
   while (word = tp->getWord(), !tp->fail()) {

    // use istringstream to avoid mutiple different words in word which are separated by space
    istringstream ss(word);
    string temp;

    // A loop to output word
    while(ss >> temp){
      cout << temp << endl;
    }
   }

   if (in != &cin) delete in;

   delete tp;
  }
}
