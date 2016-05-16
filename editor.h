#ifndef __EDITOR_H__
#define __EDITOR_H__
#include "textprocess.h"

// Class Editor is a decorator

class Editor : public TextProcessor {						 // Editor inherits from Editor
	protected:
		// Editor has a relationship with TextProcessor
  	TextProcessor *tp;
  	// Constructor
  	Editor(TextProcessor *tp) : tp(tp){}
  	// Destructor
  	~Editor(){ delete tp;}
};

#endif