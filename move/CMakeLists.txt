set(CMAKE_EXPORT_COMPILE_COMMANDS ON) 
file(GLOB sources CONFIGURE_DEPENDS *.cpp )

foreach(source ${sources})
    get_filename_component(executable_name ${source} NAME_WE) # 获取文件名（不包括扩展名）
    add_executable(${executable_name} ${source})
endforeach()

