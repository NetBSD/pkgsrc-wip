# $NetBSD$

DISTNAME=	msgraph-core-0.2.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	security www python
MASTER_SITES=	${MASTER_SITE_PYPI:=m/msgraph-core/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/microsoftgraph/msgraph-sdk-python-core
COMMENT=	Lightweight wrapper around the Microsoft Graph API
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-azure-core-[0-9]*:../../wip/py-azure-core
DEPENDS+=	${PYPKGPREFIX}-azure-identity-[0-9]*:../../wip/py-azure-identity
DEPENDS+=	${PYPKGPREFIX}-requests-[0-9]*:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-responses-[0-9]*:../../net/py-responses
TEST_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test

USE_LANGUAGES=	# none

# needs credentials for testing; without:
# 22 failed, 37 passed
do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} pytest-${PYVERSSUFFIX}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
