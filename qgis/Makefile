# $NetBSD: Makefile,v 1.197 2024/01/25 06:33:07 adam Exp $

# This is intentionally 3.34 Long Term Release.  Please do not update
# to later branches, and instead discuss whether/how we want multiple
# versions, or to only track one LTR branch.
DISTNAME=	qgis-3.34.3
CATEGORIES=	geography
MASTER_SITES=	https://qgis.org/downloads/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	gdt@NetBSD.org
#MAINTAINER+=	brook@nmsu.edu
#MAINTAINER+=	bouyer@NetBSD.org
HOMEPAGE=	http://www.qgis.org/
COMMENT=	Geographic Information System (GIS)
LICENSE=	gnu-gpl-v2

USE_CMAKE=		yes
USE_LANGUAGES=		c c++ fortran77
USE_CXX_FEATURES=	c++17
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		cmake bison flex perl pkg-config
# Building 3.28.1 fails with BSD make.  One issue seem to be a
# difference of opinion about quoting of $, with gmake wanting
# "$$area" vs bmake perhaps wanting "$$$$area".  Another is filenames
# with spaces, which are \-quoted in Makefiles, but bmake sees them as
# separate files.
USE_TOOLS+=		gmake

PLIST_SRC=		PLIST

DEPENDS+=		qca2-qt5-ossl-[0-9]*:../../security/qca2-qt5-ossl
TOOL_DEPENDS+=		${PYPKGPREFIX}-sip6-[0-9]*:../../x11/py-sip6
TOOL_DEPENDS+=		${PYPKGPREFIX}-qt-builder-[0-9]*:../../x11/py-qt-builder
DEPENDS+=		${PYPKGPREFIX}-qt5-[0-9]*:../../x11/py-qt5
DEPENDS+=		${PYPKGPREFIX}-qt5-qscintilla-[0-9]*:../../x11/py-qt5-qscintilla

# This is needed to find qca2.
CMAKE_PREFIX_PATH+=	${QTDIR}

# This could be used if we want to build pdf doc, which is currently false
#TOOL_DEPENDS+=	txt2tags-[0-9]*:../../wip/txt2tags

# Disable building of QGIS.app.  \todo Consider building it.
SUBST_CLASSES+=			xapple
SUBST_STAGE.xapple=		pre-configure
SUBST_MESSAGE.xapple=		Disabling APPLE App in cmake scripts
xapple_FIND_CMD=		cd ${WRKSRC} && \
				find . -name '*.cmake' -o -name CMakeLists.txt
SUBST_FILES.xapple=		${xapple_FIND_CMD:sh}
SUBST_SED.xapple+=		-e 's,APPLE,XAPPLE,'
SUBST_SED.xapple+=		-e 's,MACOSX_BUNDLE ,,'
SUBST_NOOP_OK.xapple=		yes # since SUBST_FILES is generated

SUBST_CLASSES+=			pyqt1
SUBST_STAGE.pyqt1=		pre-configure
SUBST_MESSAGE.pyqt=		Use versioned py-programs in PyQtMacros
SUBST_FILES.pyqt1=		cmake/PyQtMacros.cmake
SUBST_SED.pyqt1+=		-e '/^ *SET/s,pyuic5,&-${PYVERSSUFFIX},'
SUBST_SED.pyqt1+=		-e '/^ *SET/s,pyrcc5,&-${PYVERSSUFFIX},'

SUBST_CLASSES+=			pyqt2
SUBST_STAGE.pyqt2=		pre-configure
SUBST_MESSAGE.pyqt=		Use versioned py-programs in FindPyQt5
SUBST_FILES.pyqt2=		cmake/FindPyQt5.cmake
SUBST_SED.pyqt2+=		-e '/ *FIND_PROGRAM(__pyuic5 /s,"pyuic5,&-${PYVERSSUFFIX},'

CMAKE_ARGS+=		-DWITH_BINDINGS:BOOL=TRUE
CMAKE_ARGS+=		-DWITH_INTERNAL_MARKUPSAFE=FALSE

# \todo Understand what draco is and perhaps add to pkgsrc.
CMAKE_ARGS+=		-DWITH_DRACO=FALSE
# \todo Understand and probably add.
CMAKE_ARGS+=		-DWITH_3D=FALSE
# \todo Resolve minizip shadowing zip, and minizip needing to be bl3d
# because qgis seems to -lminizip.
CMAKE_ARGS+=		-DWITH_SPATIALITE=FALSE

# Server support is WIP; it has merely been tested that regular use
# has not been broken.
CMAKE_ARGS+=		-DWITH_SERVER:BOOL=TRUE
CMAKE_ARGS+=		-DQGIS_CGIBIN_SUBDIR=libexec/cgi-bin

PYTHON_VERSIONS_INCOMPATIBLE=	27 38

# \todo Consider (optional?) dependency on GRASS.
# \todo Consider (optional?) dependency on SAGA.

DEPENDS+=	${PYPKGPREFIX}-requests-[0-9]*:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-psycopg2-[0-9]*:../../databases/py-psycopg2
DEPENDS+=	${PYPKGPREFIX}-gdal-[0-9]*:../../geography/py-gdal
DEPENDS+=	${PYPKGPREFIX}-jinja2-[0-9]*:../../textproc/py-jinja2
DEPENDS+=	${PYPKGPREFIX}-markupsafe-[0-9]*:../../textproc/py-markupsafe
# for quickosm
DEPENDS+=	${PYPKGPREFIX}-yaml-[0-9]*:../../textproc/py-yaml
# for metasearch
DEPENDS+=	${PYPKGPREFIX}-owslib-[0-9]*:../../geography/py-owslib

CMAKE_ARGS+=	-DWITH_QTWEBKIT=FALSE
CMAKE_ARGS+=	-DQWT_DIR=${QWT_DIR}
# Useful for package development:
#CMAKE_ARGS+=	-DCMAKE_VERBOSE_MAKEFILE=TRUE

CONFIGURE_DIRS=	build
CMAKE_ARG_PATH=	..

pre-configure:
	${MKDIR} ${WRKSRC}/build

# \todo Does qgis properly depend on minizip, or is this a bug in
# libspatialite's bl3?
#.include "../../archivers/minizip/buildlink3.mk"
# \todo Does qgis properly depend on librrtopo, or is this a bug in
# libspatialite's bl3?
#.include "../../geography/librttopo/buildlink3.mk"
#.include "../../geography/libspatialite/buildlink3.mk"

.include "../../lang/python/pyversion.mk"
.include "../../archivers/libzip/buildlink3.mk"
.include "../../archivers/zstd/buildlink3.mk"
##.include "../../devel/qjson/buildlink3.mk"
.include "../../devel/protobuf/buildlink3.mk"
.include "../../geography/gdal-lib/buildlink3.mk"
.include "../../geography/pdal-lib/buildlink3.mk"
.include "../../geography/proj/buildlink3.mk"
.include "../../graphics/exiv2/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../math/gsl/buildlink3.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../www/fcgi/buildlink3.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../geography/spatialindex/buildlink3.mk"
.include "../../security/libtasn1/buildlink3.mk"
.include "../../security/qca2-qt5/buildlink3.mk"
.include "../../security/qt5-qtkeychain/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qttools/buildlink3.mk"
.include "../../x11/qwt6-qt5/buildlink3.mk"
.include "../../x11/qt5-qscintilla/buildlink3.mk"
.include "../../x11/qt5-qtserialport/buildlink3.mk"
.include "../../x11/qt5-qtlocation/buildlink3.mk"
.include "../../mk/pgsql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
