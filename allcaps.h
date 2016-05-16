#ifndef __ALLCAPS_H__
#define __ALLCAPS_H__
#include <iostream>
#include <string>
#include "editor.h"

// Class AllCaps is a concrete decorator

class AllCaps: public Editor {									// AllCaps inherits from Editor
	public:
		// Constructor
		AllCaps(TextProcessor *tp);
		// set input source
		void setSource(std::istream *inp);
		// get the word and change all its letters to capital
		std::string getWord();
		// is reading input fail?
		bool fail() const;
};

#endif