# $NetBSD$

PKGNAME=	${PYPKGPREFIX}-${DISTNAME}

USE_LANGUAGES=	c99 c++
USE_CMAKE=	yes
AUTO_MKDIRS=	yes

DEPENDS+=	deepstate>=${VERSION}:../../wip/deepstate
DEPENDS+=	deepstate-afl>=${VERSION}:../../wip/deepstate-afl
#XXX seems to not build on NetBSD
#DEPENDS+=	deepstate-honggfuzz>=${VERSION}:../../wip/deepstate-honggfuzz
DEPENDS+=	deepstate-libfuzzer>=${VERSION}:../../wip/deepstate-libfuzzer

PYTHON_VERSIONS_ACCEPTED=	37 36

CONFIGURE_DIRS=	build
CMAKE_ARG_PATH=	${WRKSRC}
PYSETUPSUBDIR=	build

pre-configure:
	cd ${WRKSRC} && ${MKDIR} ${CONFIGURE_DIRS}

.include "../../wip/deepstate/Makefile.common"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
