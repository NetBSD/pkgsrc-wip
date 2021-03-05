# $NetBSD$

DISTNAME=	azure-common-1.1.26
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	category python
MASTER_SITES=	${MASTER_SITE_PYPI:=a/azure-common/}
EXTRACT_SUFX=	.zip

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/Azure/azure-sdk-for-python
COMMENT=	Microsoft Azure Client Library for Python
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-azure-core>=1.11.0:../../wip/py-azure-core

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
