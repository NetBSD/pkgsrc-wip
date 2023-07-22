# $NetBSD$

DISTNAME=	coloredlogs-15.0.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/coloredlogs/}

MAINTAINER=	bacon@NetBSD.org
HOMEPAGE=	https://pypi.org/project/coloredlogs/
COMMENT=	Colored terminal output for Python's logging module
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-humanfriendly>=9.1:../../wip/py-humanfriendly

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
