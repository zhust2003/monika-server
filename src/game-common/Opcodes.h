#ifndef _OPCODES_H
#define _OPCODES_H

// 后期此文件应该由原型文件生成
// 协议由服务+动作组成，共两个字节，服务及动作各占一个字节

// 所有服务
enum Services {
    SERVICE_ACCOUNT     = 0x01
    SERVICE_CHARACTER   = 0x02
    SERVICE_CHAT        = 0x03
    SERVICE_ACCOUNT     = 0x04
};

// 所有服务下的子协议


// 账号相关
enum AccountService {
    CMSG_ACCOUNT_CREATE
    SMSG_ACCOUNT_CREATE
};

// 角色相关
enum CharacterService {
    CMSG_CHARACTER_CREATE
    SMSG_CHARACTER_CREATE
    CMSG_CHARACTER_DELETE
    SMSG_CHARACTER_DELETE
};

#endif
