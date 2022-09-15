# $NetBSD$

DISTNAME=	azure-identity-1.10.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=a/azure-identity/}
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/Azure/azure-sdk-for-python/tree/main/sdk/identity/azure-identity
COMMENT=	Microsoft Azure Identity Library for Python
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-azure-core>=1.11.0:../../wip/py-azure-core
DEPENDS+=	${PYPKGPREFIX}-cryptography>=2.5:../../security/py-cryptography
DEPENDS+=	${PYPKGPREFIX}-msal>=1.12:../../wip/py-msal
DEPENDS+=	${PYPKGPREFIX}-msal-extensions>=0.3:../../wip/py-msal-extensions
DEPENDS+=	${PYPKGPREFIX}-six>=1.12.0:../../lang/py-six

USE_LANGUAGES=	# none

# tests fail

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
