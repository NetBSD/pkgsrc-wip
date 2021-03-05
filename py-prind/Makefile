# $NetBSD$

DISTNAME=	PyPrind-2.11.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/Py//:tl}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=P/PyPrind/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/rasbt/pyprind
COMMENT=	Python Progress Bar and Percent Indicator Utility
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-psutil>=5.8.0:../../sysutils/py-psutil

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
