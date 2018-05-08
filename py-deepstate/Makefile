# $NetBSD$

PKGNAME=	${PYPKGPREFIX}-${DISTNAME}

USE_LANGUAGES=	c99 c++
USE_CMAKE=	yes
AUTO_MKDIRS=	yes

DEPENDS+=	deepstate-[0-9]*:../../wip/deepstate

PYTHON_VERSIONS_ACCEPTED=	27

CMAKE_ARG_PATH=	${WRKSRC}
CONFIGURE_DIRS=	${WRKSRC}/build
PYSETUPSUBDIR=	build

pre-configure:
	${MKDIR} ${WRKSRC}/build

.include "../../wip/deepstate/Makefile.common"
.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
