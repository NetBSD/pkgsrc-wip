# $NetBSD$

DISTNAME=	autoflake-1.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	https://files.pythonhosted.org/packages/11/2e/0a7618eb5e69483d62b0f86c8d1eb7fdca2c2781f6f0cd5f3a3286398475/

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/myint/autoflake
COMMENT=	Removes unused imports and unused variables
#LICENSE=	Expat License # TODO: from setup.py; needs to be adjusted

DEPENDS+=	${PYPKGPREFIX}-flakes>=2.2.0:../../devel/py-flakes

USE_LANGUAGES=	# none

do-test:
	${RUN} cd ${WRKSRC}; ${SETENV} ${TEST_ENV} ${PYTHONBIN} test_autoflake.py

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
