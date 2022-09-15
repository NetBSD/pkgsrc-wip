# $NetBSD$

DISTNAME=	msal-1.18.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	security net python
MASTER_SITES=	${MASTER_SITE_PYPI:=m/msal/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/AzureAD/microsoft-authentication-library-for-python
COMMENT=	Python library to access the Microsoft Cloud
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-requests>=2.0.03:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-JWT>=1.0.03:../../textproc/py-JWT
DEPENDS+=	${PYPKGPREFIX}-cryptography>=0.6:../../security/py-cryptography

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
