# $NetBSD$

DISTNAME=	cellulist-0.1.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_PYPI:=c/cellulist/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://github.com/eddiejessup/cellulist
COMMENT=	Periodic cell list
LICENSE=	2-clause-bsd

WRKSRC=		${WRKDIR}/cellulist-0.1.1

USE_LANGUAGES=	c fortran

PYTHON_VERSIONS_ACCEPTED=  34 33 27

.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
