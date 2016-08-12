#pragma once


#include "Observer.hpp"
#include <list>

//base class for subjects (observer pattern)
class CSubject
{
public:

	void AddObserver(CObserver *_observer){ m_pObserverList.push_back(_observer); }
	void RemoveObserver(CObserver *_observer);

	//notifies an action to all the observers
	void Notify(int _subject, int _action, int _object);

protected:

	//a list with all the observers
	std::list<CObserver*> m_pObserverList;

};


