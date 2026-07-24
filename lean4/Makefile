# $NetBSD$

DISTNAME=	lean4-4.32.1
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_GITHUB:=leanprover/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/leanprover/lean4/
COMMENT=	Programming language for theorem proving
LICENSE=	apache-2.0

TOOL_DEPENDS+=	leantar-[0-9]*:../../wip/leantar
DEPENDS+=	cadical-[0-9]*:../../wip/cadical

USE_LANGUAGES=	c c++
USE_TOOLS+=	bash:run gmake pkg-config

# needed for stage0 tools that are called during build and installation
MAKE_ENV+=	LD_LIBRARY_PATH=${WRKSRC}/${CMAKE_BUILD_DIR}/stage0/lib/lean:${WRKSRC}/${CMAKE_BUILD_DIR}/stage0/lib
INSTALL_ENV+=	LD_LIBRARY_PATH=${WRKSRC}/${CMAKE_BUILD_DIR}/stage0/lib/lean:${WRKSRC}/${CMAKE_BUILD_DIR}/stage0/lib

INSTALLATION_DIRS+=	share/lean4

CMAKE_CONFIGURE_ARGS+=	-DUSE_MIMALLOC=no
# stage0/stage1 options need to be passed explicitly
CMAKE_CONFIGURE_ARGS+=	-DSTAGE0_CMAKE_PREFIX_PATH=${BUILDLINK_DIR}
CMAKE_CONFIGURE_ARGS+=	-DSTAGE1_CMAKE_INSTALL_PREFIX=${PREFIX}
# LDFLAGS from environment are ignored
CMAKE_CONFIGURE_ARGS+=	-DTOOLCHAIN_SHARED_LINKER_FLAGS=${LDFLAGS:Q}

LDFLAGS+=	${COMPILER_RPATH_FLAG}${PREFIX}/lib/lean

REPLACE_BASH+=	src/bin/leanmake
REPLACE_BASH+=	stage0/src/bin/leanmake

# as of 4.32.1: "Only makefile generators are supported"
CMAKE_GENERATORS_INCOMPATIBLE=	ninja

post-install:
	${RM} ${DESTDIR}${PREFIX}/bin/cadical
	${MV} ${DESTDIR}${PREFIX}/LICENSE* ${DESTDIR}${PREFIX}/share/lean4

.include "../../devel/cmake/build.mk"
.include "../../devel/libuv/buildlink3.mk"
.include "../../devel/gmp/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
