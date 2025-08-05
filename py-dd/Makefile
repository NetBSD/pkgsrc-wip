# $NetBSD$

DISTNAME=	dd-0.6.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PYPI:=d/dd/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pypi.org/project/dd/
COMMENT=	Binary decision diagrams in Python, wrappers of CUDD, Sylvan, BuDDy
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-astutils>=0.0.5:../../wip/py-astutils
DEPENDS+=	${PYPKGPREFIX}-networkx>=0:../../math/py-networkx
TOOL_DEPENDS+=	${PYPKGPREFIX}-cython>=3.0.0:../../devel/py-cython

USE_LANGUAGES+=	c c++

# test status as of 0.6.0
# needs 'make install'
# 5 errors

.include "../../wip/cudd/buildlink3.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
