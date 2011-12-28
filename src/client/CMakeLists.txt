# CMake build system file
# Author: dalton


SET(TARGET_NAME "client")

INCLUDE_DIRECTORIES("${CMAKE_SOURCE_DIR}/src")


# 产生可执行文件
ADD_EXECUTABLE("${TARGET_NAME}"
               Main.cpp
               StatConnection.cpp
               )

# 链接库
TARGET_LINK_LIBRARIES("${TARGET_NAME}" 
                      boost_system 
                      boost_thread 
                      common 
                      game-common
                     )

# 包含目录
INCLUDE_DIRECTORIES("~/boost_1_48_0")

