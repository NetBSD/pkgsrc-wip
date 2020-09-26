# $NetBSD$

PKGNAME=	deepstate-libfuzzer-${VERSION}

USE_LANGUAGES=	c99 c++
USE_CMAKE=	yes
AUTO_MKDIRS=	yes

DEPENDS+=	deepstate>=${VERSION}:../../wip/deepstate

CONFIGURE_DIRS=	${WRKSRC}/build
CMAKE_ARG_PATH=	${WRKSRC}

CMAKE_ARGS+=	-DPYTHON=${PREFIX}/bin/python${PYVERSSUFFIX}
CMAKE_ARGS+=	-DDEEPSTATE_LIBFUZZER=ON
CMAKE_ARGS+=	-DCMAKE_C_COMPILER=${CLANGBASE:Q}/bin/clang
CMAKE_ARGS+=	-DCMAKE_CXX_COMPILER=${CLANGBASE:Q}/bin/clang++

pre-configure:
	${MKDIR} ${CONFIGURE_DIRS}

do-install:
	${INSTALL_LIB} ${WRKSRC}/build/libdeepstate_LF.a ${DESTDIR}${PREFIX}/lib

.include "../../mk/compiler/clang.mk"
.include "../../lang/compiler-rt/buildlink3.mk"
.include "../../wip/deepstate/Makefile.common"
.include "../../lang/python/pyversion.mk"
.include "../../mk/bsd.pkg.mk"
