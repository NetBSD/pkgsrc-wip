# $NetBSD$

DISTNAME=	pyrevolve-2.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S//py/}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pyrevolve/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/devitocodes/pyrevolve
COMMENT=	Python wrapper for Revolve checkpointing
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-cython>=0.17:../../devel/py-cython
TOOL_DEPENDS+=	${PYPKGPREFIX}-versioneer>=0.28:../../devel/py-versioneer

USE_LANGUAGES=	c c++

.include "../../devel/py-cython/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
