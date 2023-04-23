#include "LoadMusic.h"

Music *LoadMusic::load(const std::string &musicPath)
{
    Music *p_newMusic = new Music();
    p_newMusic->setPath(musicPath);
    /**
     * TODO: AVELACNEL FILE-IC METADATAN HAVAQELY
     *
     */

    return p_newMusic;
}