# $NetBSD$

PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
DISTNAME=	hidapi-0.7.99.post18
MASTER_SITES=	${MASTER_SITE_PYPI:=h/hidapi/}
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Python wrapper for the hidapi
LICENSE=	gnu-gpl-v3 OR modified-bsd

.include "../../devel/libusb1/buildlink3.mk"
.include "../../devel/py-cython/buildlink3.mk"
.include "../../lang/python/distutils.mk"

.include "../../mk/bsd.pkg.mk"
