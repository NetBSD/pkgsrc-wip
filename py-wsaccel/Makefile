# $NetBSD$

DISTNAME=	wsaccel-0.6.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_PYPI:=w/wsaccel/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/methane/wsaccel
COMMENT=	Accelerator for ws4py and AutobahnPython
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-autobahn>=20.1.2:../../www/py-autobahn
DEPENDS+=       ${PYPKGPREFIX}-tornado>=4.1:../../www/py-tornado

.include "../../devel/py-cython/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
