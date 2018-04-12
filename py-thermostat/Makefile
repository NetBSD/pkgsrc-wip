# $NetBSD$

DISTNAME=	thermostat-1.1.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	biology
MASTER_SITES=	https://pypi.python.org/packages/19/2d/181ae49bfe59b604a0fabde3c47f9d88c0187130f2f15b58262b7798e5a5/
EXTRACT_SUFX=	.zip

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://github.com/EPAENERGYSTAR/epathermostat
COMMENT=	Calculate connected thermostat savings
LICENSE=	mit

DEPENDS+=	${PYPREFIX}-pandas>=0.18.1:../../math/py-pandas
DEPENDS+=	${PYPREFIX}-eemter>=0.5.3:../../wip/py-eemter

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
