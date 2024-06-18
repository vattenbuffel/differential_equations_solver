#include "output.hpp"

int Output::send(std::string str)
{
    std::cout << "message type: " << type << "\n"
              << str;

    return 0;
}

void Output::message_type_set(MESSAGE_TYPE message_type)
{
    type = message_type;
}

Output::Output(/* args */)
{
}

Output::~Output()
{
}