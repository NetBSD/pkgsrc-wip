# $NetBSD$

DISTNAME=	vcrpy-4.1.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PYPI:=v/vcrpy/}

MAINTAINER=	matthewd@fastmail.us
HOMEPAGE=	https://github.com/kevin1024/vcrpy
COMMENT=	VCR.py simplifies and speeds up tests that make HTTP requests
LICENSE=	mit

TEST_DEPENDS+=	${PYPKGPREFIX}-mock>=3.0.5:../../devel/py-mock
TEST_DEPENDS+=	${PYPKGPREFIX}-test>=6.1.0:../../devel/py-test
TEST_DEPENDS+=	${PYPKGPREFIX}-test-httpbin>=1.0.0:../../www/py-test-httpbin

do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} ${PYTHONBIN} -m pytest -s


.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
