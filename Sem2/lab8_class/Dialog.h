#pragma once
#include "list.h"
#include "Event.h"

class Dialog: public List {
public:
	Dialog(void);
public:
	virtual ~Dialog(void);
	virtual void GetEvent(TEvent& event);
	virtual int Excecute();
	virtual void HandleEvent(TEvent& event);
	virtual void ClearEvent(TEvent& event);
	int Valid();
	void EndExec();
protected:
	int EndState;
};

