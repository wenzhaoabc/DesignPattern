#include "ChoiceManager.h"
#include "ChoiceTrash.h"

ChoiceManager::ChoiceManager()
{
}

ChoiceManager::~ChoiceManager()
{
}

void ChoiceManager::add(string trash)
{
    choice_list.push_back(*(new ChoiceTrash(trash)));
}

ChoiceTrash ChoiceManager::get(int index)
{
    std::list<ChoiceTrash>::iterator it = choice_list.begin();
    while (index-1>0)
    {
        index--;
        it++;
    }
    return *it;
}
