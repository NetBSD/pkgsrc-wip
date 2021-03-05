# $NetBSD$

DISTNAME=	msrest-0.6.21
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=m/msrest/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/Azure/msrest-for-python
COMMENT=	AutoRest swagger generator Python client runtime
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-requests>=2.16>=0:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-requests-oauthlib>=1.3.0:../../security/py-requests-oauthlib
DEPENDS+=	${PYPKGPREFIX}-isodate>=0.6.0:../../time/py-isodate
DEPENDS+=	${PYPKGPREFIX}-certifi>=2017.4.17:../../security/py-certifi


.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
