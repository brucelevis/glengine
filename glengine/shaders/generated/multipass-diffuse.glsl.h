#pragma once
/*
    #version:1# (machine generated, don't edit!)

    Generated by sokol-shdc (https://github.com/floooh/sokol-tools)

    Overview:

        Shader program 'offscreen_diffuse':
            Get shader desc: offscreen_diffuse_shader_desc()
            Vertex shader: vs_diffuse
                Attribute slots:
                    ATTR_vs_diffuse_vertex_pos = 0
                    ATTR_vs_diffuse_vertex_color = 1
                    ATTR_vs_diffuse_vertex_normal = 2
                Uniform block 'vs_params':
                    C struct: vs_params_t
                    Bind slot: SLOT_vs_params = 0
            Fragment shader: fs_diffuse
                Uniform block 'fs_params':
                    C struct: fs_params_t
                    Bind slot: SLOT_fs_params = 0

        Shader program 'offscreen_diffuse_textured':
            Get shader desc: offscreen_diffuse_textured_shader_desc()
            Vertex shader: vs_diffuse_textured
                Attribute slots:
                    ATTR_vs_diffuse_textured_vertex_pos = 0
                    ATTR_vs_diffuse_textured_vertex_color = 1
                    ATTR_vs_diffuse_textured_vertex_normal = 2
                    ATTR_vs_diffuse_textured_vertex_texcoord = 3
                Uniform block 'vs_params':
                    C struct: vs_params_t
                    Bind slot: SLOT_vs_params = 0
            Fragment shader: fs_diffuse_textured
                Uniform block 'fs_params':
                    C struct: fs_params_t
                    Bind slot: SLOT_fs_params = 0
                Image 'tex_diffuse':
                    Type: SG_IMAGETYPE_2D
                    Component Type: SG_SAMPLERTYPE_FLOAT
                    Bind slot: SLOT_tex_diffuse = 0


    Shader descriptor structs:

        sg_shader offscreen_diffuse = sg_make_shader(offscreen_diffuse_shader_desc());
        sg_shader offscreen_diffuse_textured = sg_make_shader(offscreen_diffuse_textured_shader_desc());

    Vertex attribute locations for vertex shader 'vs_diffuse':

        sg_pipeline pip = sg_make_pipeline(&(sg_pipeline_desc){
            .layout = {
                .attrs = {
                    [ATTR_vs_diffuse_vertex_pos] = { ... },
                    [ATTR_vs_diffuse_vertex_color] = { ... },
                    [ATTR_vs_diffuse_vertex_normal] = { ... },
                },
            },
            ...});

    Vertex attribute locations for vertex shader 'vs_diffuse_textured':

        sg_pipeline pip = sg_make_pipeline(&(sg_pipeline_desc){
            .layout = {
                .attrs = {
                    [ATTR_vs_diffuse_textured_vertex_pos] = { ... },
                    [ATTR_vs_diffuse_textured_vertex_color] = { ... },
                    [ATTR_vs_diffuse_textured_vertex_normal] = { ... },
                    [ATTR_vs_diffuse_textured_vertex_texcoord] = { ... },
                },
            },
            ...});

    Image bind slots, use as index in sg_bindings.vs_images[] or .fs_images[]

        SLOT_tex_diffuse = 0;

    Bind slot and C-struct for uniform block 'vs_params':

        vs_params_t vs_params = {
            .model = ...;
            .view = ...;
            .projection = ...;
        };
        sg_apply_uniforms(SG_SHADERSTAGE_[VS|FS], SLOT_vs_params, &vs_params, sizeof(vs_params));

    Bind slot and C-struct for uniform block 'fs_params':

        fs_params_t fs_params = {
            .color = ...;
        };
        sg_apply_uniforms(SG_SHADERSTAGE_[VS|FS], SLOT_fs_params, &fs_params, sizeof(fs_params));

*/
#include <stdint.h>
#include <stdbool.h>
#if !defined(SOKOL_SHDC_ALIGN)
  #if defined(_MSC_VER)
    #define SOKOL_SHDC_ALIGN(a) __declspec(align(a))
  #else
    #define SOKOL_SHDC_ALIGN(a) __attribute__((aligned(a)))
  #endif
#endif
#define ATTR_vs_diffuse_vertex_pos (0)
#define ATTR_vs_diffuse_vertex_color (1)
#define ATTR_vs_diffuse_vertex_normal (2)
#define ATTR_vs_diffuse_textured_vertex_pos (0)
#define ATTR_vs_diffuse_textured_vertex_color (1)
#define ATTR_vs_diffuse_textured_vertex_normal (2)
#define ATTR_vs_diffuse_textured_vertex_texcoord (3)
#define SLOT_tex_diffuse (0)
#define SLOT_vs_params (0)
#pragma pack(push,1)
SOKOL_SHDC_ALIGN(16) typedef struct vs_params_t {
    math::Matrix4f model;
    math::Matrix4f view;
    math::Matrix4f projection;
} vs_params_t;
#pragma pack(pop)
#define SLOT_fs_params (0)
#pragma pack(push,1)
SOKOL_SHDC_ALIGN(16) typedef struct fs_params_t {
    math::Vector4f color;
} fs_params_t;
#pragma pack(pop)
/*
    #version 330
    
    uniform vec4 vs_params[12];
    out vec3 frag_pos;
    layout(location = 0) in vec4 vertex_pos;
    out vec3 frag_normal;
    layout(location = 2) in vec3 vertex_normal;
    out vec4 proj_pos;
    layout(location = 1) in vec4 vertex_color;
    
    void main()
    {
        mat4 _20 = mat4(vs_params[0], vs_params[1], vs_params[2], vs_params[3]);
        frag_pos = vec3((_20 * vertex_pos).xyz);
        mat4 _33 = transpose(inverse(_20));
        frag_normal = mat3(_33[0].xyz, _33[1].xyz, _33[2].xyz) * vertex_normal;
        gl_Position = ((mat4(vs_params[8], vs_params[9], vs_params[10], vs_params[11]) * mat4(vs_params[4], vs_params[5], vs_params[6], vs_params[7])) * _20) * vertex_pos;
        proj_pos = gl_Position;
    }
    
*/
static const char vs_diffuse_source_glsl330[683] = {
    0x23,0x76,0x65,0x72,0x73,0x69,0x6f,0x6e,0x20,0x33,0x33,0x30,0x0a,0x0a,0x75,0x6e,
    0x69,0x66,0x6f,0x72,0x6d,0x20,0x76,0x65,0x63,0x34,0x20,0x76,0x73,0x5f,0x70,0x61,
    0x72,0x61,0x6d,0x73,0x5b,0x31,0x32,0x5d,0x3b,0x0a,0x6f,0x75,0x74,0x20,0x76,0x65,
    0x63,0x33,0x20,0x66,0x72,0x61,0x67,0x5f,0x70,0x6f,0x73,0x3b,0x0a,0x6c,0x61,0x79,
    0x6f,0x75,0x74,0x28,0x6c,0x6f,0x63,0x61,0x74,0x69,0x6f,0x6e,0x20,0x3d,0x20,0x30,
    0x29,0x20,0x69,0x6e,0x20,0x76,0x65,0x63,0x34,0x20,0x76,0x65,0x72,0x74,0x65,0x78,
    0x5f,0x70,0x6f,0x73,0x3b,0x0a,0x6f,0x75,0x74,0x20,0x76,0x65,0x63,0x33,0x20,0x66,
    0x72,0x61,0x67,0x5f,0x6e,0x6f,0x72,0x6d,0x61,0x6c,0x3b,0x0a,0x6c,0x61,0x79,0x6f,
    0x75,0x74,0x28,0x6c,0x6f,0x63,0x61,0x74,0x69,0x6f,0x6e,0x20,0x3d,0x20,0x32,0x29,
    0x20,0x69,0x6e,0x20,0x76,0x65,0x63,0x33,0x20,0x76,0x65,0x72,0x74,0x65,0x78,0x5f,
    0x6e,0x6f,0x72,0x6d,0x61,0x6c,0x3b,0x0a,0x6f,0x75,0x74,0x20,0x76,0x65,0x63,0x34,
    0x20,0x70,0x72,0x6f,0x6a,0x5f,0x70,0x6f,0x73,0x3b,0x0a,0x6c,0x61,0x79,0x6f,0x75,
    0x74,0x28,0x6c,0x6f,0x63,0x61,0x74,0x69,0x6f,0x6e,0x20,0x3d,0x20,0x31,0x29,0x20,
    0x69,0x6e,0x20,0x76,0x65,0x63,0x34,0x20,0x76,0x65,0x72,0x74,0x65,0x78,0x5f,0x63,
    0x6f,0x6c,0x6f,0x72,0x3b,0x0a,0x0a,0x76,0x6f,0x69,0x64,0x20,0x6d,0x61,0x69,0x6e,
    0x28,0x29,0x0a,0x7b,0x0a,0x20,0x20,0x20,0x20,0x6d,0x61,0x74,0x34,0x20,0x5f,0x32,
    0x30,0x20,0x3d,0x20,0x6d,0x61,0x74,0x34,0x28,0x76,0x73,0x5f,0x70,0x61,0x72,0x61,
    0x6d,0x73,0x5b,0x30,0x5d,0x2c,0x20,0x76,0x73,0x5f,0x70,0x61,0x72,0x61,0x6d,0x73,
    0x5b,0x31,0x5d,0x2c,0x20,0x76,0x73,0x5f,0x70,0x61,0x72,0x61,0x6d,0x73,0x5b,0x32,
    0x5d,0x2c,0x20,0x76,0x73,0x5f,0x70,0x61,0x72,0x61,0x6d,0x73,0x5b,0x33,0x5d,0x29,
    0x3b,0x0a,0x20,0x20,0x20,0x20,0x66,0x72,0x61,0x67,0x5f,0x70,0x6f,0x73,0x20,0x3d,
    0x20,0x76,0x65,0x63,0x33,0x28,0x28,0x5f,0x32,0x30,0x20,0x2a,0x20,0x76,0x65,0x72,
    0x74,0x65,0x78,0x5f,0x70,0x6f,0x73,0x29,0x2e,0x78,0x79,0x7a,0x29,0x3b,0x0a,0x20,
    0x20,0x20,0x20,0x6d,0x61,0x74,0x34,0x20,0x5f,0x33,0x33,0x20,0x3d,0x20,0x74,0x72,
    0x61,0x6e,0x73,0x70,0x6f,0x73,0x65,0x28,0x69,0x6e,0x76,0x65,0x72,0x73,0x65,0x28,
    0x5f,0x32,0x30,0x29,0x29,0x3b,0x0a,0x20,0x20,0x20,0x20,0x66,0x72,0x61,0x67,0x5f,
    0x6e,0x6f,0x72,0x6d,0x61,0x6c,0x20,0x3d,0x20,0x6d,0x61,0x74,0x33,0x28,0x5f,0x33,
    0x33,0x5b,0x30,0x5d,0x2e,0x78,0x79,0x7a,0x2c,0x20,0x5f,0x33,0x33,0x5b,0x31,0x5d,
    0x2e,0x78,0x79,0x7a,0x2c,0x20,0x5f,0x33,0x33,0x5b,0x32,0x5d,0x2e,0x78,0x79,0x7a,
    0x29,0x20,0x2a,0x20,0x76,0x65,0x72,0x74,0x65,0x78,0x5f,0x6e,0x6f,0x72,0x6d,0x61,
    0x6c,0x3b,0x0a,0x20,0x20,0x20,0x20,0x67,0x6c,0x5f,0x50,0x6f,0x73,0x69,0x74,0x69,
    0x6f,0x6e,0x20,0x3d,0x20,0x28,0x28,0x6d,0x61,0x74,0x34,0x28,0x76,0x73,0x5f,0x70,
    0x61,0x72,0x61,0x6d,0x73,0x5b,0x38,0x5d,0x2c,0x20,0x76,0x73,0x5f,0x70,0x61,0x72,
    0x61,0x6d,0x73,0x5b,0x39,0x5d,0x2c,0x20,0x76,0x73,0x5f,0x70,0x61,0x72,0x61,0x6d,
    0x73,0x5b,0x31,0x30,0x5d,0x2c,0x20,0x76,0x73,0x5f,0x70,0x61,0x72,0x61,0x6d,0x73,
    0x5b,0x31,0x31,0x5d,0x29,0x20,0x2a,0x20,0x6d,0x61,0x74,0x34,0x28,0x76,0x73,0x5f,
    0x70,0x61,0x72,0x61,0x6d,0x73,0x5b,0x34,0x5d,0x2c,0x20,0x76,0x73,0x5f,0x70,0x61,
    0x72,0x61,0x6d,0x73,0x5b,0x35,0x5d,0x2c,0x20,0x76,0x73,0x5f,0x70,0x61,0x72,0x61,
    0x6d,0x73,0x5b,0x36,0x5d,0x2c,0x20,0x76,0x73,0x5f,0x70,0x61,0x72,0x61,0x6d,0x73,
    0x5b,0x37,0x5d,0x29,0x29,0x20,0x2a,0x20,0x5f,0x32,0x30,0x29,0x20,0x2a,0x20,0x76,
    0x65,0x72,0x74,0x65,0x78,0x5f,0x70,0x6f,0x73,0x3b,0x0a,0x20,0x20,0x20,0x20,0x70,
    0x72,0x6f,0x6a,0x5f,0x70,0x6f,0x73,0x20,0x3d,0x20,0x67,0x6c,0x5f,0x50,0x6f,0x73,
    0x69,0x74,0x69,0x6f,0x6e,0x3b,0x0a,0x7d,0x0a,0x0a,0x00,
};
/*
    #version 330
    
    uniform vec4 fs_params[1];
    in vec3 frag_normal;
    in vec3 frag_pos;
    layout(location = 0) out vec4 out_frag_color;
    in vec4 proj_pos;
    
    void main()
    {
        out_frag_color = vec4(vec3(0.100000001490116119384765625) + (vec3(1.0) * ((dot(normalize(frag_normal), normalize(vec3(100.0) - frag_pos)) + 1.0) * 0.5)), 1.0) * fs_params[0];
    }
    
*/
static const char fs_diffuse_source_glsl330[342] = {
    0x23,0x76,0x65,0x72,0x73,0x69,0x6f,0x6e,0x20,0x33,0x33,0x30,0x0a,0x0a,0x75,0x6e,
    0x69,0x66,0x6f,0x72,0x6d,0x20,0x76,0x65,0x63,0x34,0x20,0x66,0x73,0x5f,0x70,0x61,
    0x72,0x61,0x6d,0x73,0x5b,0x31,0x5d,0x3b,0x0a,0x69,0x6e,0x20,0x76,0x65,0x63,0x33,
    0x20,0x66,0x72,0x61,0x67,0x5f,0x6e,0x6f,0x72,0x6d,0x61,0x6c,0x3b,0x0a,0x69,0x6e,
    0x20,0x76,0x65,0x63,0x33,0x20,0x66,0x72,0x61,0x67,0x5f,0x70,0x6f,0x73,0x3b,0x0a,
    0x6c,0x61,0x79,0x6f,0x75,0x74,0x28,0x6c,0x6f,0x63,0x61,0x74,0x69,0x6f,0x6e,0x20,
    0x3d,0x20,0x30,0x29,0x20,0x6f,0x75,0x74,0x20,0x76,0x65,0x63,0x34,0x20,0x6f,0x75,
    0x74,0x5f,0x66,0x72,0x61,0x67,0x5f,0x63,0x6f,0x6c,0x6f,0x72,0x3b,0x0a,0x69,0x6e,
    0x20,0x76,0x65,0x63,0x34,0x20,0x70,0x72,0x6f,0x6a,0x5f,0x70,0x6f,0x73,0x3b,0x0a,
    0x0a,0x76,0x6f,0x69,0x64,0x20,0x6d,0x61,0x69,0x6e,0x28,0x29,0x0a,0x7b,0x0a,0x20,
    0x20,0x20,0x20,0x6f,0x75,0x74,0x5f,0x66,0x72,0x61,0x67,0x5f,0x63,0x6f,0x6c,0x6f,
    0x72,0x20,0x3d,0x20,0x76,0x65,0x63,0x34,0x28,0x76,0x65,0x63,0x33,0x28,0x30,0x2e,
    0x31,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x31,0x34,0x39,0x30,0x31,0x31,0x36,0x31,
    0x31,0x39,0x33,0x38,0x34,0x37,0x36,0x35,0x36,0x32,0x35,0x29,0x20,0x2b,0x20,0x28,
    0x76,0x65,0x63,0x33,0x28,0x31,0x2e,0x30,0x29,0x20,0x2a,0x20,0x28,0x28,0x64,0x6f,
    0x74,0x28,0x6e,0x6f,0x72,0x6d,0x61,0x6c,0x69,0x7a,0x65,0x28,0x66,0x72,0x61,0x67,
    0x5f,0x6e,0x6f,0x72,0x6d,0x61,0x6c,0x29,0x2c,0x20,0x6e,0x6f,0x72,0x6d,0x61,0x6c,
    0x69,0x7a,0x65,0x28,0x76,0x65,0x63,0x33,0x28,0x31,0x30,0x30,0x2e,0x30,0x29,0x20,
    0x2d,0x20,0x66,0x72,0x61,0x67,0x5f,0x70,0x6f,0x73,0x29,0x29,0x20,0x2b,0x20,0x31,
    0x2e,0x30,0x29,0x20,0x2a,0x20,0x30,0x2e,0x35,0x29,0x29,0x2c,0x20,0x31,0x2e,0x30,
    0x29,0x20,0x2a,0x20,0x66,0x73,0x5f,0x70,0x61,0x72,0x61,0x6d,0x73,0x5b,0x30,0x5d,
    0x3b,0x0a,0x7d,0x0a,0x0a,0x00,
};
/*
    #version 330
    
    uniform vec4 vs_params[12];
    out vec3 frag_pos;
    layout(location = 0) in vec4 vertex_pos;
    out vec3 frag_normal;
    layout(location = 2) in vec3 vertex_normal;
    out vec2 frag_uv;
    layout(location = 3) in vec2 vertex_texcoord;
    out vec4 proj_pos;
    layout(location = 1) in vec4 vertex_color;
    
    void main()
    {
        mat4 _20 = mat4(vs_params[0], vs_params[1], vs_params[2], vs_params[3]);
        frag_pos = vec3((_20 * vertex_pos).xyz);
        mat4 _33 = transpose(inverse(_20));
        frag_normal = mat3(_33[0].xyz, _33[1].xyz, _33[2].xyz) * vertex_normal;
        frag_uv = vertex_texcoord;
        gl_Position = ((mat4(vs_params[8], vs_params[9], vs_params[10], vs_params[11]) * mat4(vs_params[4], vs_params[5], vs_params[6], vs_params[7])) * _20) * vertex_pos;
        proj_pos = gl_Position;
    }
    
*/
static const char vs_diffuse_textured_source_glsl330[778] = {
    0x23,0x76,0x65,0x72,0x73,0x69,0x6f,0x6e,0x20,0x33,0x33,0x30,0x0a,0x0a,0x75,0x6e,
    0x69,0x66,0x6f,0x72,0x6d,0x20,0x76,0x65,0x63,0x34,0x20,0x76,0x73,0x5f,0x70,0x61,
    0x72,0x61,0x6d,0x73,0x5b,0x31,0x32,0x5d,0x3b,0x0a,0x6f,0x75,0x74,0x20,0x76,0x65,
    0x63,0x33,0x20,0x66,0x72,0x61,0x67,0x5f,0x70,0x6f,0x73,0x3b,0x0a,0x6c,0x61,0x79,
    0x6f,0x75,0x74,0x28,0x6c,0x6f,0x63,0x61,0x74,0x69,0x6f,0x6e,0x20,0x3d,0x20,0x30,
    0x29,0x20,0x69,0x6e,0x20,0x76,0x65,0x63,0x34,0x20,0x76,0x65,0x72,0x74,0x65,0x78,
    0x5f,0x70,0x6f,0x73,0x3b,0x0a,0x6f,0x75,0x74,0x20,0x76,0x65,0x63,0x33,0x20,0x66,
    0x72,0x61,0x67,0x5f,0x6e,0x6f,0x72,0x6d,0x61,0x6c,0x3b,0x0a,0x6c,0x61,0x79,0x6f,
    0x75,0x74,0x28,0x6c,0x6f,0x63,0x61,0x74,0x69,0x6f,0x6e,0x20,0x3d,0x20,0x32,0x29,
    0x20,0x69,0x6e,0x20,0x76,0x65,0x63,0x33,0x20,0x76,0x65,0x72,0x74,0x65,0x78,0x5f,
    0x6e,0x6f,0x72,0x6d,0x61,0x6c,0x3b,0x0a,0x6f,0x75,0x74,0x20,0x76,0x65,0x63,0x32,
    0x20,0x66,0x72,0x61,0x67,0x5f,0x75,0x76,0x3b,0x0a,0x6c,0x61,0x79,0x6f,0x75,0x74,
    0x28,0x6c,0x6f,0x63,0x61,0x74,0x69,0x6f,0x6e,0x20,0x3d,0x20,0x33,0x29,0x20,0x69,
    0x6e,0x20,0x76,0x65,0x63,0x32,0x20,0x76,0x65,0x72,0x74,0x65,0x78,0x5f,0x74,0x65,
    0x78,0x63,0x6f,0x6f,0x72,0x64,0x3b,0x0a,0x6f,0x75,0x74,0x20,0x76,0x65,0x63,0x34,
    0x20,0x70,0x72,0x6f,0x6a,0x5f,0x70,0x6f,0x73,0x3b,0x0a,0x6c,0x61,0x79,0x6f,0x75,
    0x74,0x28,0x6c,0x6f,0x63,0x61,0x74,0x69,0x6f,0x6e,0x20,0x3d,0x20,0x31,0x29,0x20,
    0x69,0x6e,0x20,0x76,0x65,0x63,0x34,0x20,0x76,0x65,0x72,0x74,0x65,0x78,0x5f,0x63,
    0x6f,0x6c,0x6f,0x72,0x3b,0x0a,0x0a,0x76,0x6f,0x69,0x64,0x20,0x6d,0x61,0x69,0x6e,
    0x28,0x29,0x0a,0x7b,0x0a,0x20,0x20,0x20,0x20,0x6d,0x61,0x74,0x34,0x20,0x5f,0x32,
    0x30,0x20,0x3d,0x20,0x6d,0x61,0x74,0x34,0x28,0x76,0x73,0x5f,0x70,0x61,0x72,0x61,
    0x6d,0x73,0x5b,0x30,0x5d,0x2c,0x20,0x76,0x73,0x5f,0x70,0x61,0x72,0x61,0x6d,0x73,
    0x5b,0x31,0x5d,0x2c,0x20,0x76,0x73,0x5f,0x70,0x61,0x72,0x61,0x6d,0x73,0x5b,0x32,
    0x5d,0x2c,0x20,0x76,0x73,0x5f,0x70,0x61,0x72,0x61,0x6d,0x73,0x5b,0x33,0x5d,0x29,
    0x3b,0x0a,0x20,0x20,0x20,0x20,0x66,0x72,0x61,0x67,0x5f,0x70,0x6f,0x73,0x20,0x3d,
    0x20,0x76,0x65,0x63,0x33,0x28,0x28,0x5f,0x32,0x30,0x20,0x2a,0x20,0x76,0x65,0x72,
    0x74,0x65,0x78,0x5f,0x70,0x6f,0x73,0x29,0x2e,0x78,0x79,0x7a,0x29,0x3b,0x0a,0x20,
    0x20,0x20,0x20,0x6d,0x61,0x74,0x34,0x20,0x5f,0x33,0x33,0x20,0x3d,0x20,0x74,0x72,
    0x61,0x6e,0x73,0x70,0x6f,0x73,0x65,0x28,0x69,0x6e,0x76,0x65,0x72,0x73,0x65,0x28,
    0x5f,0x32,0x30,0x29,0x29,0x3b,0x0a,0x20,0x20,0x20,0x20,0x66,0x72,0x61,0x67,0x5f,
    0x6e,0x6f,0x72,0x6d,0x61,0x6c,0x20,0x3d,0x20,0x6d,0x61,0x74,0x33,0x28,0x5f,0x33,
    0x33,0x5b,0x30,0x5d,0x2e,0x78,0x79,0x7a,0x2c,0x20,0x5f,0x33,0x33,0x5b,0x31,0x5d,
    0x2e,0x78,0x79,0x7a,0x2c,0x20,0x5f,0x33,0x33,0x5b,0x32,0x5d,0x2e,0x78,0x79,0x7a,
    0x29,0x20,0x2a,0x20,0x76,0x65,0x72,0x74,0x65,0x78,0x5f,0x6e,0x6f,0x72,0x6d,0x61,
    0x6c,0x3b,0x0a,0x20,0x20,0x20,0x20,0x66,0x72,0x61,0x67,0x5f,0x75,0x76,0x20,0x3d,
    0x20,0x76,0x65,0x72,0x74,0x65,0x78,0x5f,0x74,0x65,0x78,0x63,0x6f,0x6f,0x72,0x64,
    0x3b,0x0a,0x20,0x20,0x20,0x20,0x67,0x6c,0x5f,0x50,0x6f,0x73,0x69,0x74,0x69,0x6f,
    0x6e,0x20,0x3d,0x20,0x28,0x28,0x6d,0x61,0x74,0x34,0x28,0x76,0x73,0x5f,0x70,0x61,
    0x72,0x61,0x6d,0x73,0x5b,0x38,0x5d,0x2c,0x20,0x76,0x73,0x5f,0x70,0x61,0x72,0x61,
    0x6d,0x73,0x5b,0x39,0x5d,0x2c,0x20,0x76,0x73,0x5f,0x70,0x61,0x72,0x61,0x6d,0x73,
    0x5b,0x31,0x30,0x5d,0x2c,0x20,0x76,0x73,0x5f,0x70,0x61,0x72,0x61,0x6d,0x73,0x5b,
    0x31,0x31,0x5d,0x29,0x20,0x2a,0x20,0x6d,0x61,0x74,0x34,0x28,0x76,0x73,0x5f,0x70,
    0x61,0x72,0x61,0x6d,0x73,0x5b,0x34,0x5d,0x2c,0x20,0x76,0x73,0x5f,0x70,0x61,0x72,
    0x61,0x6d,0x73,0x5b,0x35,0x5d,0x2c,0x20,0x76,0x73,0x5f,0x70,0x61,0x72,0x61,0x6d,
    0x73,0x5b,0x36,0x5d,0x2c,0x20,0x76,0x73,0x5f,0x70,0x61,0x72,0x61,0x6d,0x73,0x5b,
    0x37,0x5d,0x29,0x29,0x20,0x2a,0x20,0x5f,0x32,0x30,0x29,0x20,0x2a,0x20,0x76,0x65,
    0x72,0x74,0x65,0x78,0x5f,0x70,0x6f,0x73,0x3b,0x0a,0x20,0x20,0x20,0x20,0x70,0x72,
    0x6f,0x6a,0x5f,0x70,0x6f,0x73,0x20,0x3d,0x20,0x67,0x6c,0x5f,0x50,0x6f,0x73,0x69,
    0x74,0x69,0x6f,0x6e,0x3b,0x0a,0x7d,0x0a,0x0a,0x00,
};
/*
    #version 330
    
    uniform vec4 fs_params[1];
    uniform sampler2D tex_diffuse;
    
    in vec3 frag_normal;
    in vec3 frag_pos;
    in vec2 frag_uv;
    layout(location = 0) out vec4 out_frag_color;
    in vec4 proj_pos;
    
    void main()
    {
        vec4 _65 = texture(tex_diffuse, frag_uv);
        vec4 _67 = fs_params[0] * _65;
        if (_67.w < 0.100000001490116119384765625)
        {
            discard;
        }
        out_frag_color = vec4(vec3(0.100000001490116119384765625) + (vec3(1.0) * ((dot(normalize(frag_normal), normalize(vec3(100.0) - frag_pos)) + 1.0) * 0.5)), 1.0) * _67;
    }
    
*/
static const char fs_diffuse_textured_source_glsl330[539] = {
    0x23,0x76,0x65,0x72,0x73,0x69,0x6f,0x6e,0x20,0x33,0x33,0x30,0x0a,0x0a,0x75,0x6e,
    0x69,0x66,0x6f,0x72,0x6d,0x20,0x76,0x65,0x63,0x34,0x20,0x66,0x73,0x5f,0x70,0x61,
    0x72,0x61,0x6d,0x73,0x5b,0x31,0x5d,0x3b,0x0a,0x75,0x6e,0x69,0x66,0x6f,0x72,0x6d,
    0x20,0x73,0x61,0x6d,0x70,0x6c,0x65,0x72,0x32,0x44,0x20,0x74,0x65,0x78,0x5f,0x64,
    0x69,0x66,0x66,0x75,0x73,0x65,0x3b,0x0a,0x0a,0x69,0x6e,0x20,0x76,0x65,0x63,0x33,
    0x20,0x66,0x72,0x61,0x67,0x5f,0x6e,0x6f,0x72,0x6d,0x61,0x6c,0x3b,0x0a,0x69,0x6e,
    0x20,0x76,0x65,0x63,0x33,0x20,0x66,0x72,0x61,0x67,0x5f,0x70,0x6f,0x73,0x3b,0x0a,
    0x69,0x6e,0x20,0x76,0x65,0x63,0x32,0x20,0x66,0x72,0x61,0x67,0x5f,0x75,0x76,0x3b,
    0x0a,0x6c,0x61,0x79,0x6f,0x75,0x74,0x28,0x6c,0x6f,0x63,0x61,0x74,0x69,0x6f,0x6e,
    0x20,0x3d,0x20,0x30,0x29,0x20,0x6f,0x75,0x74,0x20,0x76,0x65,0x63,0x34,0x20,0x6f,
    0x75,0x74,0x5f,0x66,0x72,0x61,0x67,0x5f,0x63,0x6f,0x6c,0x6f,0x72,0x3b,0x0a,0x69,
    0x6e,0x20,0x76,0x65,0x63,0x34,0x20,0x70,0x72,0x6f,0x6a,0x5f,0x70,0x6f,0x73,0x3b,
    0x0a,0x0a,0x76,0x6f,0x69,0x64,0x20,0x6d,0x61,0x69,0x6e,0x28,0x29,0x0a,0x7b,0x0a,
    0x20,0x20,0x20,0x20,0x76,0x65,0x63,0x34,0x20,0x5f,0x36,0x35,0x20,0x3d,0x20,0x74,
    0x65,0x78,0x74,0x75,0x72,0x65,0x28,0x74,0x65,0x78,0x5f,0x64,0x69,0x66,0x66,0x75,
    0x73,0x65,0x2c,0x20,0x66,0x72,0x61,0x67,0x5f,0x75,0x76,0x29,0x3b,0x0a,0x20,0x20,
    0x20,0x20,0x76,0x65,0x63,0x34,0x20,0x5f,0x36,0x37,0x20,0x3d,0x20,0x66,0x73,0x5f,
    0x70,0x61,0x72,0x61,0x6d,0x73,0x5b,0x30,0x5d,0x20,0x2a,0x20,0x5f,0x36,0x35,0x3b,
    0x0a,0x20,0x20,0x20,0x20,0x69,0x66,0x20,0x28,0x5f,0x36,0x37,0x2e,0x77,0x20,0x3c,
    0x20,0x30,0x2e,0x31,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x31,0x34,0x39,0x30,0x31,
    0x31,0x36,0x31,0x31,0x39,0x33,0x38,0x34,0x37,0x36,0x35,0x36,0x32,0x35,0x29,0x0a,
    0x20,0x20,0x20,0x20,0x7b,0x0a,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x64,0x69,
    0x73,0x63,0x61,0x72,0x64,0x3b,0x0a,0x20,0x20,0x20,0x20,0x7d,0x0a,0x20,0x20,0x20,
    0x20,0x6f,0x75,0x74,0x5f,0x66,0x72,0x61,0x67,0x5f,0x63,0x6f,0x6c,0x6f,0x72,0x20,
    0x3d,0x20,0x76,0x65,0x63,0x34,0x28,0x76,0x65,0x63,0x33,0x28,0x30,0x2e,0x31,0x30,
    0x30,0x30,0x30,0x30,0x30,0x30,0x31,0x34,0x39,0x30,0x31,0x31,0x36,0x31,0x31,0x39,
    0x33,0x38,0x34,0x37,0x36,0x35,0x36,0x32,0x35,0x29,0x20,0x2b,0x20,0x28,0x76,0x65,
    0x63,0x33,0x28,0x31,0x2e,0x30,0x29,0x20,0x2a,0x20,0x28,0x28,0x64,0x6f,0x74,0x28,
    0x6e,0x6f,0x72,0x6d,0x61,0x6c,0x69,0x7a,0x65,0x28,0x66,0x72,0x61,0x67,0x5f,0x6e,
    0x6f,0x72,0x6d,0x61,0x6c,0x29,0x2c,0x20,0x6e,0x6f,0x72,0x6d,0x61,0x6c,0x69,0x7a,
    0x65,0x28,0x76,0x65,0x63,0x33,0x28,0x31,0x30,0x30,0x2e,0x30,0x29,0x20,0x2d,0x20,
    0x66,0x72,0x61,0x67,0x5f,0x70,0x6f,0x73,0x29,0x29,0x20,0x2b,0x20,0x31,0x2e,0x30,
    0x29,0x20,0x2a,0x20,0x30,0x2e,0x35,0x29,0x29,0x2c,0x20,0x31,0x2e,0x30,0x29,0x20,
    0x2a,0x20,0x5f,0x36,0x37,0x3b,0x0a,0x7d,0x0a,0x0a,0x00,
};
#if !defined(SOKOL_GFX_INCLUDED)
  #error "Please include sokol_gfx.h before multipass-diffuse.glsl.h"
#endif
static inline const sg_shader_desc* offscreen_diffuse_shader_desc(void) {
  if (sg_query_backend() == SG_BACKEND_GLCORE33) {
    static sg_shader_desc desc;
    static bool valid;
    if (!valid) {
      valid = true;
      desc.attrs[0].name = "vertex_pos";
      desc.attrs[1].name = "vertex_color";
      desc.attrs[2].name = "vertex_normal";
      desc.vs.source = vs_diffuse_source_glsl330;
      desc.vs.entry = "main";
      desc.vs.uniform_blocks[0].size = 192;
      desc.vs.uniform_blocks[0].uniforms[0].name = "vs_params";
      desc.vs.uniform_blocks[0].uniforms[0].type = SG_UNIFORMTYPE_FLOAT4;
      desc.vs.uniform_blocks[0].uniforms[0].array_count = 12;
      desc.fs.source = fs_diffuse_source_glsl330;
      desc.fs.entry = "main";
      desc.fs.uniform_blocks[0].size = 16;
      desc.fs.uniform_blocks[0].uniforms[0].name = "fs_params";
      desc.fs.uniform_blocks[0].uniforms[0].type = SG_UNIFORMTYPE_FLOAT4;
      desc.fs.uniform_blocks[0].uniforms[0].array_count = 1;
      desc.label = "offscreen_diffuse_shader";
    };
    return &desc;
  }
  return 0;
}
static inline const sg_shader_desc* offscreen_diffuse_textured_shader_desc(void) {
  if (sg_query_backend() == SG_BACKEND_GLCORE33) {
    static sg_shader_desc desc;
    static bool valid;
    if (!valid) {
      valid = true;
      desc.attrs[0].name = "vertex_pos";
      desc.attrs[1].name = "vertex_color";
      desc.attrs[2].name = "vertex_normal";
      desc.attrs[3].name = "vertex_texcoord";
      desc.vs.source = vs_diffuse_textured_source_glsl330;
      desc.vs.entry = "main";
      desc.vs.uniform_blocks[0].size = 192;
      desc.vs.uniform_blocks[0].uniforms[0].name = "vs_params";
      desc.vs.uniform_blocks[0].uniforms[0].type = SG_UNIFORMTYPE_FLOAT4;
      desc.vs.uniform_blocks[0].uniforms[0].array_count = 12;
      desc.fs.source = fs_diffuse_textured_source_glsl330;
      desc.fs.entry = "main";
      desc.fs.uniform_blocks[0].size = 16;
      desc.fs.uniform_blocks[0].uniforms[0].name = "fs_params";
      desc.fs.uniform_blocks[0].uniforms[0].type = SG_UNIFORMTYPE_FLOAT4;
      desc.fs.uniform_blocks[0].uniforms[0].array_count = 1;
      desc.fs.images[0].name = "tex_diffuse";
      desc.fs.images[0].type = SG_IMAGETYPE_2D;
      desc.fs.images[0].sampler_type = SG_SAMPLERTYPE_FLOAT;
      desc.label = "offscreen_diffuse_textured_shader";
    };
    return &desc;
  }
  return 0;
}
