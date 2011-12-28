# CMake build system file
# Author: dalton


SET(TARGET_NAME "common")


# 产生可执行文件
ADD_LIBRARY("${TARGET_NAME}" SHARED
            Config.cpp
            Logger.cpp
            TcpServer.cpp
            Connection.cpp
            ServicePool.cpp
            Time.cpp
            )

# 链接库
TARGET_LINK_LIBRARIES("${TARGET_NAME}" 
                      boost_date_time
                      )
# 包含目录
INCLUDE_DIRECTORIES("~/boost_1_48_0")
