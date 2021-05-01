#include "FactoryMachine.h"
#include "FactoryMachineState.h"

FactoryMachine::FactoryMachine(int id) : BaseGameEntity(id)
{
	_sm = new StateMachine<FactoryMachine>(this);
	_sm->SetCurrentState(FactoryMachineState::Instance());
}

FactoryMachine::~FactoryMachine()
{
	delete _sm; _sm = nullptr;
}

void FactoryMachine::Update()
{
	_sm->Update();
}

bool FactoryMachine::HandleEvent(const Event& src_event)
{
	return _sm->HandleEvent(src_event);
}
