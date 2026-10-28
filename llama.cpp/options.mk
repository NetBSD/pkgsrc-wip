# $NetBSD$

PKG_OPTIONS_VAR=		PKG_OPTIONS.llama.cpp
PKG_OPTIONS_OPTIONAL_GROUPS=	backend
PKG_OPTIONS_GROUP.backend+=	cuda ggml vulkan
PKG_SUGGESTED_OPTIONS+=		ggml

.include "../../mk/bsd.options.mk"

PLIST_VARS+=	vulkan
.if !empty(PKG_OPTIONS:Mcuda)
CMAKE_CONFIGURE_ARGS+=	-DGGML_CUDA=ON
CMAKE_CONFIGURE_ARGS+=	-DGGML_NATIVE=ON
CMAKE_CONFIGURE_ARGS+=	-DGGML_CUDA_FA=ON
CMAKE_CONFIGURE_ARGS+=	-DGGML_CUDA_FA_ALL_QUANTS=ON
CMAKE_CONFIGURE_ARGS+=	-DCMAKE_CUDA_COMPILER=/usr/local/cuda/bin/nvcc
.elif !empty(PKG_OPTIONS:Mggml)
CMAKE_CONFIGURE_ARGS+=	-DLLAMA_USE_SYSTEM_GGML=YES

BUILDLINK_API_DEPENDS.ggml+=	ggml>=0.27.0
.include "../../math/ggml/buildlink3.mk"
.elif !empty(PKG_OPTIONS:Mvulkan)
PLIST.vulkan=		yes
CMAKE_CONFIGURE_ARGS+=	-DGGML_VULKAN=ON
CMAKE_CONFIGURE_ARGS+=	-DGGML_OPENMP=OFF

.include "../../graphics/shaderc/buildlink3.mk"
.include "../../graphics/vulkan-loader/buildlink3.mk"
.include "../../parallel/spirv-headers/buildlink3.mk"
.endif
