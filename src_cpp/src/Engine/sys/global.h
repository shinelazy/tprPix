/*
 * ========================= global.h ==========================
 *                          -- tpr --
 *                                        CREATE -- 2018.11.21
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 *   全局变量
 *   使用 cpp 特有的 inline 关键词来 一步到位地 声明+初始化
 * ----------------------------
 */
#ifndef TPR_GLOBAL_H_
#define TPR_GLOBAL_H_

//-------------------- CPP --------------------//
#include <string>


//inline bool is_fst_run {}; //-- 本次运行，是否为 本进程编译后的 首次运行
                            //-- 每次运行时，由函数 check_fst_run() 设置
                            //-- 若为 true，  是 首次运行
                            //-- 若为 false， 不是 首次运行

//----------------------------------------------------//
//                     file
//----------------------------------------------------//
inline int         fd_cwd {};   //-- 项目 主目录 fd

inline std::string path_cwd {}; //-- exe 所在目录的 path
inline std::string path_csharpLibs {}; //-- .../build/bin/csharpLibs/
                
inline std::string path_dataBase {};  //-- .../build/bin/dataBase/
inline std::string path_shaders {}; //-- .../build/bin/shaders/
inline std::string path_textures {}; //-- .../build/bin/textures/

inline std::string path_animFrameSets {}; //-- .../build/bin/textures/animFrameSets
inline std::string path_colliEntSet   {}; //-- .../build/bin/textures/colliEntSet
inline std::string path_fieldBorderSet {}; //-- .../build/bin/textures/fieldBorderSet


//----------------------------------------------------//
//                       OS
//----------------------------------------------------//
//-- 当前身处什么 操作系统 --//
#define OS_NULL  0
#define OS_APPLE 1
#define OS_UNIX  2
#define OS_WIN32 3
inline int current_OS {};


#endif