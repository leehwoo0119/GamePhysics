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
	//������Ʈ �̵�
	void ChangeState(State<T>* new_state)
	{
		//���� ������Ʈ ����
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
	//�۷ι� ���׿�Ʈ
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

