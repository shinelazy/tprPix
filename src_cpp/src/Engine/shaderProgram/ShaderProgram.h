/*
 * ========================= ShaderProgram.h ==========================
 *                          -- tpr --
 *                                        CREATE -- 2018.11.21
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 *   着色器程序 类
 * ----------------------------
 */
#ifndef TPR_SHADER_PROGRAM_H_
#define TPR_SHADER_PROGRAM_H_
//=== *** glad FIRST, glfw SECEND *** ===
#include<glad/glad.h>  

//--- glm - 0.9.9.5 ---
#include "glm_no_warnings.h"

//-------------------- CPP --------------------//
#include <string>
#include <vector>
#include <unordered_map>

//-------------------- Engine --------------------//
#include "tprAssert.h"



class ShaderProgram{
public:
    ShaderProgram() = default;

    //--- init ---//
    void init(  const std::string &_lpathVs, 
                const std::string &_lpathFs );

    //-- 从 着色器程序中 获得 目标变量的 地址
    inline void add_new_uniform( const std::string &_name ){
        tprAssert( this->uniforms.find(_name) == this->uniforms.end() );
        tprAssert( this->is_shaderProgram_set );
        uniforms.insert({ _name, glGetUniformLocation(this->shaderProgram, _name.c_str()) });
    }

    inline GLint get_uniform_location( const std::string &_name ){
        tprAssert( this->uniforms.find(_name) != this->uniforms.end() );
        return this->uniforms.at(_name);
    }

    inline void use_program(){
        if( this->shaderProgram == shaderProgram_current ){
            return;
        }
        glUseProgram( this->shaderProgram );
        shaderProgram_current = this->shaderProgram;
    }

    //-- 将 3个矩阵 的值 传输到 着色器程序。
    inline void send_mat4_model_2_shader( const glm::mat4 &m ){
        this->use_program();
        glUniformMatrix4fv( static_cast<GLint>( this->get_uniform_location( "model" ) ), 
                            1, 
                            GL_FALSE, 
                            static_cast<const GLfloat*>(glm::value_ptr(m)) );
    }

    inline void send_mat4_view_2_shader( const glm::mat4 &v ){
        this->use_program();
        glUniformMatrix4fv( static_cast<GLint>( this->get_uniform_location( "view" ) ),
                            1, 
                            GL_FALSE, 
                            static_cast<const GLfloat*>(glm::value_ptr(v)) );
    }

    inline void send_mat4_projection_2_shader( const glm::mat4 &p ){
        this->use_program();
        glUniformMatrix4fv( static_cast<GLint>( this->get_uniform_location( "projection" ) ),
                            1, 
                            GL_FALSE, 
                            static_cast<const GLfloat*>(glm::value_ptr(p)) );
    }

private:
    void compile( GLuint _shaderObj, const std::string &_sbuf );

    //======== vals ========//
    GLuint       shaderProgram  {0}; 

    //-- 着色器程序中的 uniform 变量们
    std::unordered_map<std::string, GLint> uniforms {}; 

    //======== flags ========//
    bool  is_shaderProgram_set {false};
                                            
    //======== static ========//
    static GLuint shaderProgram_current; //-- 当前被使用的 shaderProgram
};


#endif
