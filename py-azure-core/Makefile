# $NetBSD$

DISTNAME=	azure-core-1.25.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=a/azure-core/}
EXTRACT_SUFX=	.zip

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/Azure/azure-sdk-for-python/tree/main/sdk/core/azure-core
COMMENT=	Microsoft Azure Core Library for Python
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-requests>=2.18.4:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-six>=1.11.0:../../lang/py-six
DEPENDS+=	${PYPKGPREFIX}-typing-extensions>=4.0.1:../../devel/py-typing-extensions
#TEST_DEPENDS+=	${PYPKGPREFIX}-aiohttp>=0:../../www/py-aiohttp
#TEST_DEPENDS+=	${PYPKGPREFIX}-trio>=0:../../devel/py-trio
#TEST_DEPENDS+=	${PYPKGPREFIX}-msrest>=0:../../wip/py-msrest
#TEST_DEPENDS+=	${PYPKGPREFIX}-test>=0:../../devel/py-test

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

# tests not intended to be run from pypi
# https://github.com/Azure/azure-sdk-for-python/issues/9616
do-test:
	# cd ${WRKSRC} && ${SETENV} ${TEST_ENV} pytest-${PYVERSSUFFIX}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
