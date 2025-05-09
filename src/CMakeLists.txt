# 查找所有的 .cpp 文件
file(GLOB SOURCES "*.cpp")

# 创建可执行文件
add_executable(NumberGuessingGame ${SOURCES})

# 删除无效的库链接
# target_link_libraries(NumberGuessingGame PRIVATE some_library)

# 可以指定源文件的路径
# include_directories(${CMAKE_SOURCE_DIR}/src)