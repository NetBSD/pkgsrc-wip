# $NetBSD$

DISTNAME=	update_checker-0.18.0
PKGNAME=	${PYPKGPREFIX}-update-checker-0.18.0
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=u/update_checker/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/bboe/update_checker
COMMENT=	Python module that will check for package updates
LICENSE=	modified-bsd

PYTHON_VERSIONS_INCOMPATIBLE=	27

BUILD_DEPENDS+=	${PYPKGPREFIX}-black>=0:../../textproc/py-black
BUILD_DEPENDS+=	${PYPKGPREFIX}-flake8>=0:../../devel/py-flake8
BUILD_DEPENDS+=	${PYPKGPREFIX}-test>=2.7.3:../../devel/py-test
DEPENDS+=	${PYPKGPREFIX}-requests>=2.3.0:../../devel/py-requests

USE_LANGUAGES=	# none

do-test:
	${RUN} cd ${WRKSRC} ; ${SETENV} ${TEST_ENV} ${PYTHONBIN} update_checker_test.py

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
