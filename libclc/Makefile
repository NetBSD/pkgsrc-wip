# $NetBSD$

.include "../../wip/llvm/version.mk"

PKGNAME=	libclc-${LLVM_VERSION}
CATEGORIES=	lang

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://libclc.llvm.org/
COMMENT=	OpenCL library
LICENSE=	apache-2.0

USE_CXX_FEATURES=	c++17
USE_LANGUAGES=		c c++
GCC_REQD+=		7

CMAKE_CONFIGURE_ARGS+=	-DCMAKE_BUILD_TYPE=Release
CMAKE_CONFIGURE_ARGS+=	-DCMAKE_C_COMPILER=${CC:Q}
CMAKE_CONFIGURE_ARGS+=	-DCMAKE_CXX_COMPILER=${CXX:Q}
CMAKE_CONFIGURE_ARGS+=	-DCMAKE_CLC_COMPILER=${BUILDLINK_PREFIX.clang}/bin/clang

LIBCLC_TARGETS=		spirv32-unknown-unknown
LIBCLC_TARGETS+=	spirv64-unknown-unknown

BUILD_DIRS=		${LIBCLC_TARGETS}

PYTHON_FOR_BUILD_ONLY=	yes

.include "../../wip/clang/buildlink3.mk"
.include "../../wip/libunwind/buildlink3.mk"
.include "../../wip/llvm/buildlink3.mk"

PLIST_VARS+=		amdgpu nvptx vulkan
.if ${PKG_BUILD_OPTIONS.llvm:Mllvm-target-amdgpu}
LIBCLC_TARGETS+=	amdgcn-amd-amdhsa
PLIST.amdgpu=		yes
.endif
.if ${PKG_BUILD_OPTIONS.llvm:Mllvm-target-nvptx}
LIBCLC_TARGETS+=	nvptx64-nvidia-cuda
PLIST.nvptx=		yes
.endif
.if ${PKG_BUILD_OPTIONS.llvm:Mllvm-target-spirv}
LIBCLC_TARGETS+=	spirv64-unknown-vulkan
PLIST.vulkan=		yes
.endif

do-configure:
	${RUN} cd ${WRKSRC}/${CONFIGURE_DIR} && \
	for t in ${LIBCLC_TARGETS}; do \
		${SETENV} ${CONFIGURE_ENV} cmake \
		--install-prefix ${PREFIX} \
		-B ${CMAKE_BUILD_DIR}/$$t \
		-G ${_CMAKE_BUILD_SYSTEM:Q} \
		${CMAKE_CONFIGURE_ARGS} \
		-DLLVM_DEFAULT_TARGET_TRIPLE=$$t || exit 1; \
	done

.include "../../devel/cmake/build.mk"
.include "../../lang/python/tool.mk"
.include "../../parallel/spirv-tools/buildlink3.mk"
.include "../../wip/spirv-llvm-translator/buildlink3.mk"
.include "../../mk/atomic64.mk"
.include "../../mk/bsd.pkg.mk"
