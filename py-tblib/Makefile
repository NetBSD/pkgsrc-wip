# $NetBSD$

DISTNAME=	tblib-1.7.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_PYPI:=t/tblib/}


MAINTAINER=	matthewd@fastmail.us
HOMEPAGE=	https://github.com/ionelmc/python-tblib/
COMMENT=	Serialization library for Exceptions and Tracebacks
LICENSE=	modified-bsd

BUILD_DEPENDS+=       ${PYPKGPREFIX}-wheel>=0:../../devel/py-wheel
TEST_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test

do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} pytest-${PYVERSSUFFIX}

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
