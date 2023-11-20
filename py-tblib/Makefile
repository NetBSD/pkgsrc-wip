# $NetBSD$

DISTNAME=	tblib-3.0.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_PYPI:=t/tblib/}


MAINTAINER=	matthewd@fastmail.us
HOMEPAGE=	https://github.com/ionelmc/python-tblib/
COMMENT=	Serialization library for Exceptions and Tracebacks
LICENSE=	modified-bsd

PYTHON_VERSIONS_INCOMPATIBLE= 27
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=68.2:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel>=0.41:../../devel/py-wheel
TEST_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test

do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} pytest-${PYVERSSUFFIX}

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
