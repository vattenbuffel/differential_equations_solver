#pragma once
#include <iostream>

enum MESSAGE_TYPE
{
    FIRST,
    SUBSEQUENT,
    FINAL,
};

class Output
{
private:
    MESSAGE_TYPE type = MESSAGE_TYPE::FIRST;

public:
    int send(std::string str);
    void message_type_set(MESSAGE_TYPE message_type);
    Output(/* args */);
    ~Output();
};
