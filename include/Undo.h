#pragma once

#include "../definitions.h"

class Undo
{
    public:
        Undo();
        virtual ~Undo();

    protected:

    private:
        int m_move;
        int m_en_pas;
        int m_fifty_move;
        int m_castle_permission;
        U64 m_pos_key;

};

