# $NetBSD$


DISTNAME=	cloudpickle-3.0.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PYPI:=c/cloudpickle/}

MAINTAINER=	matthewd@fastmail.us
HOMEPAGE=	https://github.com/cloudpipe/cloudpickle
COMMENT=	Extended pickling support for Python objects
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel>=0:../../devel/py-wheel
TOOL_DEPENDS+=	${PYPKGPREFIX}-flit_core>=3.9:../../devel/py-flit_core
DEPENDS+=	${PYPKGPREFIX}-charset-normalizer-[0-9]*:../../converters/py-charset-normalizer
DEPENDS+=	${PYPKGPREFIX}-typing-extensions-[0-9]*:../../devel/py-typing-extensions
TEST_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov-[0-9]*:../../devel/py-test-cov
# To test extra features
TEST_DEPENDS+=	${PYPKGPREFIX}-psutil-[0-9]*:../../sysutils/py-psutil
TEST_DEPENDS+=	${PYPKGPREFIX}-numpy>=1.18.5:../../math/py-numpy
TEST_DEPENDS+=	${PYPKGPREFIX}-tornado>=1.18.5:../../www/py-tornado


TEST_ENV+=PYTHONPATH=tests/cloudpickle_testpkg
# We add -s here to not capture stdout - one of the unittests
# demonstrates pickling sys.stdout/sys.stderr, and pytest will redefine them
do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} ${PYTHONBIN} -m pytest -s

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
