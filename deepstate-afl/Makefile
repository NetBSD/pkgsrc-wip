# $NetBSD$

PKGNAME=	deepstate-afl-${VERSION}

USE_LANGUAGES=	c99 c++
USE_CMAKE=	yes
AUTO_MKDIRS=	yes

DEPENDS+=	afl-[0-9]*:../../devel/afl
DEPENDS+=	deepstate>=${VERSION}:../../wip/deepstate

CMAKE_ARG_PATH=	${WRKSRC}
CMAKE_ARGS+=	-DPYTHON=${PREFIX}/bin/python${PYVERSSUFFIX}
CMAKE_ARGS+=	-DDEEPSTATE_AFL=ON
CONFIGURE_DIRS=	${WRKSRC}/build
#XXX should work with CONFIGURE_ENV instead
PKGSRC_MAKE_ENV+=	CC=${LOCALBASE}/bin/afl-gcc
PKGSRC_MAKE_ENV+=	CXX=${LOCALBASE}/bin/afl-g++

pre-configure:
	${MKDIR} ${CONFIGURE_DIRS}

do-install:
	${INSTALL_LIB} ${WRKSRC}/build/libdeepstate_AFL.a ${DESTDIR}${PREFIX}/lib

.include "../../wip/deepstate/Makefile.common"
.include "../../lang/python/pyversion.mk"
.include "../../mk/bsd.pkg.mk"
