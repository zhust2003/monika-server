#ifndef _WORLDPACKET_H
#define _WORLDPACKET_H

#include "ByteBuffer.h"

class Packet : public ByteBuffer
{
    public:
        struct Header {
            uint16 size;
            uint16 cmd;
        };

        explicit Packet(uint16 opcode, size_t res = 200) : ByteBuffer(res), opcode(opcode)
        {
        }
        
        uint16 getOpcode() const {
            return opcode;
        }

        void setOpcode(uint16 opcode) {
            opcode = opcode;
        }

        void reset(uint16 opcode, size_t res = 200) {
            clear();
            _storage.reserve(res);
            opcode = opcode;
        }

    private:
        uint16 opcode;
};

#endif /* _WORLDPACKET_H */
