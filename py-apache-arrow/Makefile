# $NetBSD$
DISTNAME=	apache-arrow-${APACHE_ARROW_VERSION}
PKGNAME=	${PYPKGPREFIX}-apache-arrow-${APACHE_ARROW_VERSION}
CATEGORIES=	devel
MASTER_SITES=	https://dlcdn.apache.org/arrow/arrow-${APACHE_ARROW_VERSION}/

MAINTAINER=	matthewd@fastmail.us
HOMEPAGE=	https://arrow.apache.org/
COMMENT=	Python Bindings for Apache-Arrow
LICENSE=	apache-2.0
DISTINFO_FILE=	${.CURDIR}/../../wip/apache-arrow/distinfo
PATCHDIR=	${.CURDIR}/../../wip/apache-arrow/patches

.include "../../mk/bsd.prefs.mk"
.include "../../wip/apache-arrow/options.mk"
.include "../../wip/apache-arrow/version.mk"

USE_LANGUAGES=	c c++
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm>=0:../../devel/py-setuptools_scm
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=70.0:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel>=0:../../devel/py-wheel

#CONFIGURE_ENV+=	SETUPTOOLS_SCM_PRETEND_VERSION=${APACHE_ARROW_VERSION}

DEPENDS+=	apache-arrow>=${APACHE_ARROW_VERSION}:../../wip/apache-arrow
DEPENDS+=	bash>=5.0:../../shells/bash

TEST_DEPENDS+=	${PYPKGPREFIX}-test>=3.8:../../devel/py-test
TEST_DEPENDS+=	${PYPKGPREFIX}-test-lazy-fixture>=0.6.3:../../devel/py-test-lazy-fixture
TEST_DEPENDS+=	${PYPKGPREFIX}-hypothesis-[0-9]*:../../devel/py-hypothesis
TEST_DEPENDS+=	${PYPKGPREFIX}-pandas>=2.0.0:../../math/py-pandas
USE_TOOLS=	cmake gmake pkg-config

MAKE_ENV+=	PYARROW_PARALLEL=${MAKE_JOBS}
MAKE_ENV+=	PYARROW_WITH_ACERO=1
MAKE_ENV+=	PYARROW_WITH_DATASET=1
# Running make test aborts with flight enabled
MAKE_ENV+=  PYARROW_WITH_FLIGHT=0
MAKE_ENV+=  PYARROW_WITH_PARQUET=1
MAKE_ENV+=  PYARROW_WITH_PARQUET_ENCRYPTION=1
MAKE_ENV+=  PYARROW_WITH_SUBSTRAIT=1


WHEELFILE?=	${WRKSRC}/python/dist/*whl

# libarrow_python.so: ORIGIN Doesn't get passed through correclty
SUBST_CLASSES+=		origin
SUBST_STAGE.origin=	pre-configure
SUBST_FILES.origin=	python/CMakeLists.txt
SUBST_SED.origin=	-e 's|\\$$ORIGIN|${PREFIX}/lib/python${PYVERSSUFFIX}/site-packages/pyarrow|g'

MAKE_ENV+=	SETUPTOOLS_SCM_PRETEND_VERSION=${APACHE_ARROW_VERSION}

REPLACE_BASH=	python/cmake_modules/aws_sdk_cpp_generate_variables.sh
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
.include "../../devel/py-cython/buildlink3.mk"
.include "../../lang/python/wheel.mk"
.include "../../wip/apache-arrow/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
