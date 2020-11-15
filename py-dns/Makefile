# $NetBSD$

DISTNAME=	dnspython-2.0.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/dnspython/}
EXTRACT_SUFX=	.zip

MAINTAINER=     kamelderouiche@yahoo.com
HOMEPAGE=	http://www.dnspython.org
COMMENT=	DNS toolkit
LICENSE=	isc

PYTHON_VERSIONS_INCOMPATIBLE=	27

USE_LANGUAGES=	# none

BUILDLINK_API_DEPENDS.py-cython+=       ${PYPKGPREFIX}-cython>=0.12.1
.include "../../devel/py-cython/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
