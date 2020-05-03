# $NetBSD$

DISTNAME=	reverse_geocoder-1.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	geography devel
MASTER_SITES=	${MASTER_SITE_PYPI:=r/reverse_geocoder/}

MAINTAINER=	root@zta.lk
HOMEPAGE=	https://github.com/thampiman/reverse-geocoder
COMMENT=	Fast, offline reverse geocoder in Python
LICENSE=	gnu-lgpl-v2

DEPENDS+=	${PYPKGPREFIX}-scipy>=1.3.0:../../math/py-scipy

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
