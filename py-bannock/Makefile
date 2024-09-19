# $NetBSD$

DISTNAME=	bannock-0.5.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PYPI:=b/bannock/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/eddiejessup/bannock
COMMENT=	Agent-based simulations in confined environments
LICENSE=	modified-bsd

WRKSRC=	${WRKDIR}/bannock-0.5.0

.include "../../devel/py-cython/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
