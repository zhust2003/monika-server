# CMake build system file
# Author: dalton


SET(TARGET_NAME "game-common")


# 产生可执行文件
ADD_LIBRARY("${TARGET_NAME}" SHARED
            Session.cpp
            SessionMgr.cpp
           )

# 链接库
TARGET_LINK_LIBRARIES("${TARGET_NAME}" 
                      boost_system
                      common
                      )

# 包含目录
INCLUDE_DIRECTORIES(
                    "${CMAKE_SOURCE_DIR}/src"
                   )
