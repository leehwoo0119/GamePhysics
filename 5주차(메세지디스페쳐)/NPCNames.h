#pragma once
#include <string>

enum
{
	ent_Miner_Bob,

	ent_Elsa
};

inline std::string GetNameOfEntity(int n)
{
    switch (n)
    {
    case ent_Miner_Bob:

        return "Miner Bob";

    case ent_Elsa:

        return "Elsa";

    default:

        return "UNKNOWN!";
    }
}

