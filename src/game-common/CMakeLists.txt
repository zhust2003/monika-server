# CMake build system file
# Author: dalton


SET(TARGET_NAME "game-common")


# 产生可执行文件
ADD_LIBRARY("${TARGET_NAME}" SHARED
            Session.cpp
            SessionMgr.cpp
           )

# 包含目录
INCLUDE_DIRECTORIES(
                    "${CMAKE_SOURCE_DIR}/src"
                   )
