# $NetBSD: Makefile,v 1.3 2015/04/14 11:56:20 thomasklausner Exp $

DISTNAME=	blosc2-2.6.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=b/blosc2/}

MAINTAINER=	matthewda@fastmail.us
HOMEPAGE=	https://github.com/Blosc/python-blosc2
COMMENT=	Python wrapper for the Blosc compression library
LICENSE=	modified-bsd

USE_LANGUAGES+=	c
USE_LANGUAGES+=	c++

PYTHON_VERSIONS_INCOMPATIBLE=	27 38

USE_TOOLS+=	cmake
USE_TOOLS+=	pkg-config

TOOL_DEPENDS+=	${PYPKGPREFIX}-scikit-build>=0:../../devel/py-scikit-build
TOOL_DEPENDS+=	ninja-build-[0-9]*:../../devel/ninja-build

DEPENDS+=	${PYPKGPREFIX}-msgpack>=1.0.8:../../devel/py-msgpack
DEPENDS+=	${PYPKGPREFIX}-numpy>=1.21.2:../../math/py-numpy
DEPENDS+=	${PYPKGPREFIX}-numexpr>=2.9.0:../../math/py-numexpr
DEPENDS+=	${PYPKGPREFIX}-cpuinfo>=9.0.0:../../sysutils/py-cpuinfo
DEPENDS+=	${PYPKGPREFIX}-ndindex>=1.8:../../wip/py-ndindex

LDFLAGS+=	${COMPILER_RPATH_FLAG}${PREFIX}/lib

CMAKE_CONFIGURE_ARGS+=	-DUSE_SYSTEM_BLOSC2:BOOl=TRUE
#  work around RPATH error:   file RPATH_CHANGE could not write new RPATH:
CMAKE_CONFIGURE_ARGS+=	-DCMAKE_BUILD_WITH_INSTALL_RPATH=1

pre-configure:
	${LN} -sf ${PREFIX}/bin/cython-${PYVERSSUFFIX} ${BUILDLINK_DIR}/bin/cython

do-build:
	${RUN} cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${TOOL_PYTHONBIN} \
		setup.py bdist_wheel ${CMAKE_CONFIGURE_ARGS}

TEST_DEPENDS+=	${PYPKGPREFIX}-msgpack>=1.0.8:../../devel/py-msgpack
TEST_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test
TEST_DEPENDS+=	${PYPKGPREFIX}-numpy>=1.21.2:../../math/py-numpy
TEST_DEPENDS+=	${PYPKGPREFIX}-psutil>=5.9.8:../../sysutils/py-psutil

.include "../../devel/blosc2/buildlink3.mk"
.include "../../devel/py-cython/buildlink3.mk"
.include "../../lang/python/wheel.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
