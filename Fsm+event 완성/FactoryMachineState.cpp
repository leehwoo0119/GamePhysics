#include <iostream>
#include "FactoryMachineState.h"
#include "FactoryMachine.h"
#include "Event.h"
using namespace std;

void FactoryMachineState::Enter()
{
   
}

void FactoryMachineState::Execute(FactoryMachine* player)
{
    if (isFactoryMachine_PowerOn)
    {
        cout << "장비를 동작 중..." << endl;
    }
  
}

void FactoryMachineState::Exit()
{
    
}

bool FactoryMachineState::OnEvent(FactoryMachine* agent, const Event& event_src)
{
    switch (event_src.etType)
    {
    case ET_Machine_Power_Up:
        isFactoryMachine_PowerOn = true;
        break;
    case ET_Machine_Power_Down:
        isFactoryMachine_PowerOn = false;
        break;
    default:
        break;
    }

       

    return false;
}
