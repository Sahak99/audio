#include "Program.h"
#include "EventListener.h"
#include "LoadMusic.h"

#include <fstream>
#include <iostream>

const std::string dbPath = "./musicdb.txt";

void Program::run()
{
    init();
    EventListener listener;
    // for (auto [id, music] : m_musicMap)
    // {
    //     std::cout << id << " : " << music->getPath() << std::endl;
    // }
    while (true)
    {
        listener.listen();
    }
}

Program::Program()
{
}

Program::~Program()
{
    std::ofstream ofs;
    ofs.exceptions(std::ofstream::failbit |
                   std::ofstream::badbit);

    try
    {
        ofs.open(dbPath);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    for (auto [id, music] : m_musicMap)
    {
        ofs << music->getPath() << "\n";
    }

    ofs.close();

    for (auto [id, music] : m_musicMap)
    {
        delete music;
    }
}

void Program::loadDB()
{
    std::ifstream ifs;

    try
    {
        ifs.open(dbPath);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    while (!ifs.eof())
    {
        std::string musicPath;
        ifs >> musicPath;
        if (musicPath.empty())
        {
            continue;
        }
        Music *p_newMusic = new Music();
        p_newMusic->setPath(musicPath);
        /**
         * TODO: AVELACNEL FILE-IC METADATAN HAVAQELY
         *
         */
        m_musicMap.insert(std::make_pair(p_newMusic->getId(), p_newMusic));
    }
}

void Program::init()
{
    loadDB();
}
