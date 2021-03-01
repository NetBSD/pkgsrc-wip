# $NetBSD$

DISTNAME=	azure-core-1.11.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=a/azure-core/}
EXTRACT_SUFX=	.zip

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/Azure/azure-sdk-for-python/tree/master/sdk/core/azure-core
COMMENT=	Microsoft Azure Core Library for Python
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-requests>=2.18.4:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-six>=1.11.0:../../lang/py-six

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
