# $NetBSD$

DISTNAME=	spatious-0.1.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_PYPI:=s/spatious/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://github.com/eddiejessup/spatious
COMMENT=	Distance and geometry utilities
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-scipy>=0.7.0:../../math/py-scipy

WRKSRC=	${WRKDIR}/spatious-0.1.2

.include "../../devel/py-cython/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
