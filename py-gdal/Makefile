# $NetBSD$

# The gdal release tarball does not have swig output for the python
# bindings, and running that requires first running cmake.  This
# package instead uses the bindings release, which is apparently only
# on pypi.
.include "../../geography/gdal-lib/Makefile.common"
DISTNAME=	GDAL-3.9.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	# TODO: add primary category
MASTER_SITES=	${MASTER_SITE_PYPI:=G/GDAL/}

#HOMEPAGE=	https://pypi.org/project/GDAL/
COMMENT=	Translator library for raster geospatial data formats, Python binding
#LICENSE=	# TODO: (see mk/license.mk)

# Reset things in Makefile.common, which are no longer common.
EXTRACT_SUFX=	.tar.gz
PATCHDIR=	patches
DISTINFO_FILE=	distinfo
WRKSRC=		${WRKDIR}/GDAL-${VERSION_BASE}

USE_LANGUAGES+=		c c++
USE_CC_FEATURES+=	c99
USE_CXX_FEATURES+=	c++11

PYTHON_VERSIONS_INCOMPATIBLE=	27 38

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel>=0:../../devel/py-wheel

WHEEL_NAME=		GDAL-${PKGVERSION_NOREV}

BUILDLINK_API_DEPENDS.gdal-lib+=	gdal-lib>=3.9.0
.include "../../geography/gdal-lib/buildlink3.mk"
# \todo Explain why wheel must be before tool (Python.h not found), or fix
# documentation of python/foo.mk.
.include "../../lang/python/wheel.mk"
.include "../../lang/python/tool.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
