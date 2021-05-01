#ifndef __STATEMACHINE_H_
#define __STATEMACHINE_H_
#include "State.h"
#include "Event.h"

template<class T>

class StateMachine
{
public:
	StateMachine(T* val)
	{
		m_currentObject = val;
	}
	virtual ~StateMachine() {};
private:
	T* m_currentObject;

	State<T>* m_currentState;
	State<T>* m_prevState;
	State<T>* m_pGlobalState;

public:
	void SetPrevState(State<T>* src_state)
	{
		m_prevState = src_state;
	}
	void SetCurrentState(State<T>* src_state)
	{
		m_currentState = src_state;
	}
	void SetGlobalState(State<T>* src_state)
	{
		m_pGlobalState = src_state;
	}

	State<T>* GetCurrnetState()
	{
		return m_currentState;
	}

	void ChangeState(State<T>* target_state)
	{
		m_prevState = m_currentState;

		m_currentState->Exit();

		m_currentState = target_state;

		m_currentState->Enter();
	}

	bool HandleEvent(const Event& src_event)
	{
		if (m_currentState && m_currentState->OnEvent(m_currentObject, src_event))
		{
			return true;
		}
		return false;
	}

	void  RevertToPreviousState()
	{
		ChangeState(m_prevState);
	}

public:
	void Update()
	{
		if (m_pGlobalState)   m_pGlobalState->Execute(m_currentObject);

		if (m_currentState) m_currentState->Execute(m_currentObject);
	}
};

#endif
