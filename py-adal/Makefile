# $NetBSD$

DISTNAME=	adal-1.2.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	security python
MASTER_SITES=	https://files.pythonhosted.org/packages/82/43/a1e4b7368eec9653660ee91f023af36056028cea97e3550f85866a0c3f2f/

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/AzureAD/azure-activedirectory-library-for-python
COMMENT=	Microsoft Azure Active Directory Authentication Library for Python
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-requests>=2.21.0:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-cryptography>=2.6.1:../../security/py-cryptography
DEPENDS+=	${PYPKGPREFIX}-JWT>=1.7.1:../../textproc/py-JWT
DEPENDS+=	${PYPKGPREFIX}-dateutil>=2.8.0:../../time/py-dateutil

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
