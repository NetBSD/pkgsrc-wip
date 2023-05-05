# $NetBSD: Makefile,v 1.3 2015/04/14 11:56:20 thomasklausner Exp $

DISTNAME=	blosc-1.11.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=b/blosc/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://python-blosc.blosc.org/
COMMENT=	Python wrapper for the Blosc compression library
LICENSE=	modified-bsd

USE_LANGUAGES+=	c
USE_LANGUAGES+= c++

USE_TOOLS+=	cmake
USE_TOOLS+=	ninja

TOOL_DEPENDS+=	${PYPKGPREFIX}-scikit-build>=0.15.0:../../devel/py-scikit-build
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel>=0:../../devel/py-wheel
MAKE_ENV+=USE_SYSTEM_BLOSC=1
MAKE_ENV+=Blosc_ROOT=${BUILDLINK_PREFIX.blosc}
# Address an erron
PYSETUPARGS+=	-DCMAKE_SKIP_RPATH:BOOL=YES

do-test:
	(cd ${WRKSRC}/${PYSETUPSUBDIR} && ${SETENV} ${TEST_ENV} ${PYTHONBIN} \
	 -m blosc.test)

.include "../../devel/blosc/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
