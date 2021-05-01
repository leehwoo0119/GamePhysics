#include "Merchant.h"
#include "MerchantState.h"

Merchant::Merchant(int id) : BaseGameEntity(id)
{
	_sm = new StateMachine<Merchant>(this);
	_sm->SetCurrentState(StoreState::Instance());
	//_sm->SetGlobalState(FactoryGlobalState::Instance());
}

Merchant::~Merchant()
{
	delete _sm; _sm = nullptr;
}

void Merchant::Update()
{
	_sm->Update();
}

bool Merchant::HandleEvent(const Event& src_event)
{
	return _sm->HandleEvent(src_event);
}
