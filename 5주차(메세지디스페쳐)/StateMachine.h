#pragma once
#include "State.h"
#include "MessageDispatcher.h"

template<class T>

class StateMachine
{
private:
	T* m_currentObject;
	State<T>* m_prevState;
	State<T>* m_nowState;
	State<T>* m_pGlobalState;

public:
	StateMachine(T* val)
	{
		m_currentObject = val;
	}

	~StateMachine()
	{
	}
	void SetPrevState(State<T>* s) { m_prevState = s; }
	void SetnowState(State<T>* s) { m_nowState = s; }
	void SetGlobalState(State<T>* s) { m_pGlobalState = s; }
	
	//State<T>* GetPrevState() { return m_prevState; }
	State<T>* GetnowState() { return m_nowState; }
	//State<T>* GetGlobalState() { return m_pGlobalState; }
	//스테이트 이동
	void ChangeState(State<T>* new_state)
	{
		//이전 스테이트 저장
		m_prevState = m_nowState;

		m_nowState->Exit(m_currentObject);

		m_nowState = new_state;

		m_nowState->Enter(m_currentObject);
	}

	void Update()
	{
		if (m_pGlobalState)   m_pGlobalState->Execute(m_currentObject);

		if (m_nowState) m_nowState->Execute(m_currentObject);

	}
	//글로벌 스테에트
	void  RevertToPreviousState()
	{
		ChangeState(m_prevState);
	}
	bool HandleMessage(const Telegram& msg)
	{
		if (m_nowState && m_nowState->OnMessage(m_currentObject, msg))
		{
			return true;
		}
		return false;
	}
};

