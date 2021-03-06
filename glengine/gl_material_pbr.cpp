#include "gl_material_pbr.h"

#include "gl_engine.h"
#include "generated/shaders/pbr.glsl.h"

#include "sokol_gfx.h"


namespace glengine {

bool MaterialPBR::init(GLEngine &eng, sg_primitive_type primitive, sg_index_type idx_type) {
    ResourceManager &rm = eng.resource_manager();
    sg_shader offscreen_vertexcolor = rm.get_or_create_shader(*offscreen_pbr_shader_desc(sg_query_backend()));

    const int offscreen_sample_count = sg_query_features().msaa_render_targets ? eng._config.msaa_samples : 1;
    sg_pipeline_desc pip_desc = {0};
    pip_desc.layout.buffers[0].stride = sizeof(Vertex);
    pip_desc.layout.attrs[ATTR_vs_pbr_a_Position].format = SG_VERTEXFORMAT_FLOAT3;
    pip_desc.layout.attrs[ATTR_vs_pbr_a_Color].format = SG_VERTEXFORMAT_UBYTE4N;
    pip_desc.layout.attrs[ATTR_vs_pbr_a_Normal].format = SG_VERTEXFORMAT_FLOAT3;
    pip_desc.layout.attrs[ATTR_vs_pbr_a_UV1].format = SG_VERTEXFORMAT_FLOAT2;
    pip_desc.layout.attrs[ATTR_vs_pbr_a_Tangent].format = SG_VERTEXFORMAT_FLOAT3;
    pip_desc.shader = offscreen_vertexcolor, pip_desc.primitive_type = primitive, pip_desc.index_type = idx_type;
    pip_desc.depth = {.pixel_format = SG_PIXELFORMAT_DEPTH_STENCIL, .compare = SG_COMPAREFUNC_LESS_EQUAL, .write_enabled = true};
    if (eng._config.use_mrt) {
        pip_desc.color_count = 3;
    } else { // only 1 color attachment
        pip_desc.color_count = 1;
    }
    pip_desc.cull_mode = SG_CULLMODE_NONE;
    pip_desc.face_winding = SG_FACEWINDING_CCW;
    pip_desc.sample_count = offscreen_sample_count;
    pip_desc.label = "PBR pipeline";
    pip = rm.get_or_create_pipeline(pip_desc);
    // placeholder textures
    tex_diffuse = rm.default_image(ResourceManager::White);
    tex_metallic_roughness = rm.default_image(ResourceManager::White);
    tex_normal = rm.default_image(ResourceManager::Normal);
    tex_occlusion = rm.default_image(ResourceManager::White);
    tex_emissive = rm.default_image(ResourceManager::Black);
    color = {255, 255, 255, 255};
    return true;
}

void MaterialPBR::update_bindings(sg_bindings &bind) {
    bind.fs_images[SLOT_u_BaseColorSampler] = tex_diffuse;
    bind.fs_images[SLOT_u_MetallicRoughnessSampler] = tex_metallic_roughness;
    bind.fs_images[SLOT_u_NormalSampler] = tex_normal;
    bind.fs_images[SLOT_u_OcclusionSampler] = tex_occlusion;
    bind.fs_images[SLOT_u_EmissiveSampler] = tex_emissive;
}

void MaterialPBR::apply_uniforms(const common_uniform_params_t &params) {
    vs_params_t vs_params{.model = params.model, .view = params.view, .projection = params.projection};
    sg_apply_uniforms(SG_SHADERSTAGE_VS, SLOT_vs_params, SG_RANGE(vs_params));
    Light_t lparams{
        .light_position = {15.0f, 10.0f, 10.0f},
        .light_intensity = 1.0f,
        .light_range = 200.0f,
        .light_color = {1.0f, 1.0f, 1.0f},
        .light_direction = {-0.7398999929428101, 0.19830000400543213, -0.642799973487854},
    };
    sg_apply_uniforms(SG_SHADERSTAGE_FS, SLOT_Light, SG_RANGE(lparams));
    fs_params_t mparams{
        .u_MetallicFactor = metallic_factor,
        .u_RoughnessFactor = roughness_factor,
        .u_BaseColorFactor = {color.r / 255.0f, color.g / 255.0f, color.b / 255.0f, color.a / 255.0f},
        .u_Exposure = 1.0f,
    };
    sg_apply_uniforms(SG_SHADERSTAGE_FS, SLOT_fs_params, SG_RANGE(mparams));
    TextureParams_t tparams{
        .u_NormalScale = 1.0f,
        .u_EmissiveFactor = emissive_factor,
        .u_OcclusionStrength = 1.0f,
        .u_MipCount = 1,
    };
    sg_apply_uniforms(SG_SHADERSTAGE_FS, SLOT_TextureParams, SG_RANGE(tparams));
}

} // namespace glengine
