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

USE_LANGUAGES=	c c++
TOOL_DEPENDS+=	cmake-[0-9]*:../../devel/cmake
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm>=0:../../devel/py-setuptools_scm
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel>=0:../../devel/py-wheel

DEPENDS+=	apache-arrow>=${APACHE_ARROW_VERSION}:../../wip/apache-arrow

TEST_DEPENDS+=	${PYPKGPREFIX}-test>=3.8:../../devel/py-test
TEST_DEPENDS+=	${PYPKGPREFIX}-test-runner>=6.0.0:../../devel/py-test-runner
TEST_DEPENDS+=	${PYPKGPREFIX}-test-lazy-fixture>=0.6.3:../../devel/py-test-lazy-fixture
TEST_DEPENDS+=	${PYPKGPREFIX}-hypothesis-[0-9]*:../../devel/py-hypothesis
USE_TOOLS=	cmake gmake pkg-config

MAKE_ENV+=	PYARROW_PARALLEL=${_MAKE_JOBS_N}
WHEELFILE?=	${WRKSRC}/python/dist/pyarrow-${APACHE_ARROW_VERSION}-cp${_PYTHON_VERSION}-cp${_PYTHON_VERSION}-linux_x86_64.whl

# libarrow_python.so: ORIGIN Doesn't get passed through correclty
SUBST_CLASSES+=		origin
SUBST_STAGE.origin=	pre-configure
SUBST_FILES.origin=	python/CMakeLists.txt
SUBST_SED.origin=	-e 's|\\$$ORIGIN|${PREFIX}/lib/python${PYVERSSUFFIX}/site-packages/pyarrow|g'

CONFIGURE_ENV+=	SETUPTOOLS_SCM_PRETEND_VERSION=${APACHE_ARROW_VERSION}
MAKE_ENV+=	SETUPTOOLS_SCM_PRETEND_VERSION=${APACHE_ARROW_VERSION}
do-build:
	${RM} -rf ${WRKSRC}/python/.eggs
	${RUN} cd ${WRKSRC}/python && ${SETENV} ${MAKE_ENV} ${PYTHONBIN} setup.py build_ext --build-type=relwithdebinfo bdist_wheel

do-test:
	# Build the extension inplace, and run tests directly.  Otherwise
	# py-test-runner gets upset about missing imports
	cd ${WRKSRC}/python  && ${SETENV} ${TEST_ENV} ${PYTHONBIN} setup.py build_ext -i
	cd ${WRKSRC}/python  && ${SETENV} ${TEST_ENV} ${PYTHONBIN} -m pytest -s


MAKE_ENV+=	PYARROW_WITH_DATASET=1

.include "../../converters/utf8proc/buildlink3.mk"
.include "../../devel/libthrift/buildlink3.mk"
.include "../../wip/apache-arrow/buildlink3.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
