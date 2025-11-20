# $NetBSD$

DISTNAME=	swiftshader-20251119
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=google/}
GITHUB_TAG=	d7bc95730bdda6c88b45c00b1bfece8a5cd99ea5

DISTFILES+=	${DISTNAME}-${GITHUB_TAG}${EXTRACT_SUFX}

#CPPDAP_VER=	1fd23dda91e01550be1a421de307e6fedb2035a9
#GTEST_VER=	e2239ee6043f73722e7aa812a459f54a28552929
#NJSON_VER=	ed5541440a36bf7dc1a544f9a84fa3e5ae97b71f
#LIBBT_VER=	5a99ff7fed66b8ea8f09c9805c138524a7035ece
#NSDK_VER=	409c9d54fdaffe68565283e38dcbbe6c58535925
#BENCHM_VER=	dfc8a92abc88a9d630a9f8e01c678fedde4c3090
#GLSLANG_VER=	2b2523fb951f63f072cfba514c26f2feea5f4329

#GITHUB_SUBMODULES=	google cppdap ${CPPDAP_VER} third_party/cppdap
#GITHUB_SUBMODULES+=	google googletest ${GTEST_VER} third_party/googletest
#GITHUB_SUBMODULES+=	nlohmann json ${NJSON_VER} third_party/json
#GITHUB_SUBMODULES+=	ianlancetaylor libbacktrace ${LIBBT_VER} third_party/libbacktrace/src
#GITHUB_SUBMODULES+=	powervr-graphics Native_SDK ${NSDK_VER} third_party/PowerVR_Examples
#GITHUB_SUBMODULES+=	google benchmark ${BENCHM_VER} third_party/benchmark
#GITHUB_SUBMODULES+=	KhronosGroup glslang ${GLSLANG_VER} third_party/glslang

MAINTAINER=	kikadf.01@gmail.com
HOMEPAGE=	https://swiftshader.googlesource.com/SwiftShader
COMMENT=	High-performance CPU-based implementation of the Vulkan graphics API
LICENSE=	apache-2.0

USE_LANGUAGES=	c c++
WRKSRC=		${WRKDIR}/swiftshader-${GITHUB_TAG}

SUBST_CLASSES+=		path
SUBST_STAGE.path=	pre-configure
SUBST_MESSAGE.path=	Fixing pathes
SUBST_FILES.path+=	src/Vulkan/CMakeLists.txt
SUBST_VARS.path+=	PREFIX

# To use ninja
CMAKE_GENERATORS_INCOMPATIBLE=	make
CMAKE_CONFIGURE_ARGS+=		-DCMAKE_BUILD_TYPE=Release
CMAKE_CONFIGURE_ARGS+=		-DCMAKE_POLICY_VERSION_MINIMUM=3.5
CMAKE_CONFIGURE_ARGS+=		-DSWIFTSHADER_WARNINGS_AS_ERRORS=false
CMAKE_CONFIGURE_ARGS+=		-DSWIFTSHADER_BUILD_TESTS=false

INSTALLATION_DIRS+=	lib
INSTALLATION_DIRS+=	share/vulkan/icd.d

.include "../../mk/bsd.prefs.mk"

do-install:
	${INSTALL_LIB} ${WRKSRC}/${CMAKE_BUILD_DIR}/${OPSYS}/libvk_swiftshader.so \
		${DESTDIR}${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/${CMAKE_BUILD_DIR}/${OPSYS}/vk_swiftshader_icd.json \
		${DESTDIR}${PREFIX}/share/vulkan/icd.d

.include "../../mk/dlopen.buildlink3.mk"
BUILDLINK_TRANSFORM+=	opt:-ldl:${BUILDLINK_LDADD.dl:Q}
.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"
