#pragma once

#include <map>
#include "Music.h"

class Program
{
public:
    void run();

public:
    Program();
    ~Program();

private:
    void init();
    void loadDB();

private:
    std::map<int, Music *> m_musicMap;
};
