# $NetBSD$

DISTNAME=	dnspython3-1.15.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_PYPI:=d/dnspython3/}
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.dnspython.org/
COMMENT=	DNS toolkit for Python 3.x
#LICENSE=	# TODO: (see mk/license.mk) # distinct, similar to isc

PYTHON_VERSIONS_INCOMPATIBLE=	27

DEPENDS+=	${PYPKGPREFIX}-dnspython-[0-9]*:../../wip/py-dnspython

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
