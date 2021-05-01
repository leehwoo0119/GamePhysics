#include "Player.h"
#include "PlayerState.h"


Player::Player(int id) : BaseGameEntity(id)
{
	_sm = new StateMachine<Player>(this);
	_sm->SetCurrentState(HomeState::Instance());
	_sm->SetGlobalState(GlobalState::Instance());
}

Player::~Player()
{
	delete _sm; _sm = nullptr;
}

void Player::Update()
{
	_sm->Update();
}

bool Player::HandleEvent(const Event& src_event)
{
	return _sm->HandleEvent(src_event);
}
