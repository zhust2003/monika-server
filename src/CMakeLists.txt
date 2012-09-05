# CMake build system file
# Author: dalton


SET(TARGET_NAME "monika")

# 设置编译参数
SET(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall")
SET(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g -ggdb")
SET(CMAKE_LIBRARY_PATH ${CMAKE_LIBRARY_PATH} /usr/local/lib)

# 复制配置文件
CONFIGURE_FILE(${CMAKE_CURRENT_SOURCE_DIR}/monika.conf
               ${CMAKE_CURRENT_BINARY_DIR}/monika.conf)


# 产生可执行文件
ADD_EXECUTABLE("${TARGET_NAME}"
               Main.cpp
              )

# 链接库
TARGET_LINK_LIBRARIES("${TARGET_NAME}" 
                      boost_system 
                      boost_thread 
#                      boost_python 
                      boost_date_time
#                      python 
                      lua
                      common
                      game-common
                      )

# 包含目录
INCLUDE_DIRECTORIES(
                    "~/boost_1_48_0"
                    "${CMAKE_SOURCE_DIR}/src"
                   )

# 基本框架
ADD_SUBDIRECTORY(common)

# 游戏通用
ADD_SUBDIRECTORY(game-common)

# 客户端模拟
ADD_SUBDIRECTORY(client)

# 安装
INSTALL(TARGETS "${TARGET_NAME}"
        RUNTIME DESTINATION "bin")
