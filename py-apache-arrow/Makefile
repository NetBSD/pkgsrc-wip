# $NetBSD$
DISTNAME=	apache-arrow-${APACHE_ARROW_VERSION}
PKGNAME=	${PYPKGPREFIX}-apache-arrow-${APACHE_ARROW_VERSION}
CATEGORIES=	devel
MASTER_SITES=	https://dlcdn.apache.org/arrow/arrow-${APACHE_ARROW_VERSION}/


MAINTAINER=	matthewd@fastmail.us
HOMEPAGE=	https://arrow.apache.org/
COMMENT=	Python Bindings for Apache-Arrow
LICENSE=	apache-2.0

.include "../../mk/bsd.prefs.mk"
.include "../../wip/apache-arrow/options.mk"
.include "../../wip/apache-arrow/version.mk"

PYSETUPSUBDIR=	python

USE_LANGUAGES=	c c++
BUILD_DEPENDS+=	cmake-[0-9]*:../../devel/cmake
TEST_DEPENDS+=	${PYPKGPREFIX}-test>=3.8:../../devel/py-test
TEST_DEPENDS+=	${PYPKGPREFIX}-test-runner>=6.0.0:../../devel/py-test-runner
TEST_DEPENDS+=	${PYPKGPREFIX}-pytest-lazy-fixture>=0.6.3:../../wip/py-pytest-lazy-fixture
USE_TOOLS=	cmake gmake pkg-config

do-test:
	# Build the extension inplace, and run tests directly.  Otherwise
	# py-test-runner gets upset about missing imports
	cd ${WRKSRC}/python  && ${SETENV} ${TEST_ENV} ${PYTHONBIN} setup.py build_ext -i
	cd ${WRKSRC}/python  && ${SETENV} ${TEST_ENV} ${PYTHONBIN} -m pytest -s


MAKE_ENV+=	PYARROW_WITH_DATASET=1

.include "../../converters/utf8proc/buildlink3.mk"
.include "../../devel/libthrift/buildlink3.mk"
.include "../../wip/apache-arrow/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
