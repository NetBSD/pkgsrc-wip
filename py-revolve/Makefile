# $NetBSD$

DISTNAME=	pyrevolve-2.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S//py/}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pyrevolve/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/devitocodes/pyrevolve
COMMENT=	Python wrapper for Revolve checkpointing
LICENSE=	mit

#DEPENDS+=	${PYPKGPREFIX}-versioneer>=0.28:../../wip/py-versioneer

USE_LANGUAGES=	c c++

.include "../../devel/py-cython/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
