#include "ChoiceTrash.h"

ChoiceTrash::ChoiceTrash(string c)
{
    this->choice = c;
}

ChoiceTrash::~ChoiceTrash()
{
}

std::string ChoiceTrash::getChoice()
{
    return this->choice;
}
