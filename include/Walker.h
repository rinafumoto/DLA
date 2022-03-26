#ifndef WALKER_H_
#define WALKER_H_
#include "Image.h"
#include <memory>
#include <string>
#include <random>

class Walker
{
    public:
        Walker(size_t _w, size_t _h);
        Walker(const Walker &) = delete;
        void setImageSeed(size_t _x, size_t _y);
        void saveImage(const std::string &_fname) const;
        void randomImageSeed();
        bool walk(int iterations, bool c, bool r);
        void resetStart();
    
    private:
        int m_xpos;
        int m_ypos;
        std::unique_ptr<Image> m_map;
        std::uniform_int_distribution<> m_xRand;
        std::uniform_int_distribution<> m_yRand;
        void initRNG();
        int m_i;
};

#endif