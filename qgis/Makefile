# $NetBSD: Makefile,v 1.267 2026/02/06 10:04:56 wiz Exp $

# This package tracks what ought to be a/b/rc of 4.0.
DISTNAME=	qgis-3.99.0
CATEGORIES=	geography
#MASTER_SITES=	https://qgis.org/downloads/
MASTER_SITES=	${MASTER_SITE_GITHUB:=qgis/}
GITHUB_PROJECT=	QGIS
GITHUB_TAG=	a6644ddc2e269e32f6e622f327e5c000774d4759
DIST_SUBDIR=	qgis-snapshot

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	https://www.qgis.org/
COMMENT=	Geographic Information System (GIS)
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=		c c++ fortran77
USE_CXX_FEATURES=	c++20

USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
# 3.40.7 fails with BSD make. \todo File upstream.
# \todo Only set this if CMAKE_GENERATOR=make.
USE_TOOLS+=		gmake
USE_TOOLS+=		bison flex perl pkg-config
.include "../../devel/cmake/build.mk"

# minizip/zip.h shadows zip.h (from libzip)
BUILDLINK_TRANSFORM+=	rm:-I${PREFIX}/include/minizip

TOOL_DEPENDS+=		${PYPKGPREFIX}-sip6-[0-9]*:../../x11/py-sip6
TOOL_DEPENDS+=		${PYPKGPREFIX}-qt-builder-[0-9]*:../../x11/py-qt-builder

# \todo Grasp/fix.
#DEPENDS+=		qca2-qt6-ossl-[0-9]*:../../security/qca2-qt6-ossl
DEPENDS+=		${PYPKGPREFIX}-qt6-[0-9]*:../../x11/py-qt6
DEPENDS+=		${PYPKGPREFIX}-qt6-qscintilla-[0-9]*:../../x11/py-qt6-qscintilla

# This is needed to find qca2.
CMAKE_PREFIX_PATH+=	${QTDIR}

# This could be used if we want to build pdf doc, which is currently false
#TOOL_DEPENDS+=	txt2tags-[0-9]*:../../wip/txt2tags

# \todo Adapt to upstream rototill of mac bundle in 4.0. This is
# likely just one file now.
# Disable building of QGIS.app.  \todo Consider building it.
SUBST_CLASSES+=		xapple
SUBST_STAGE.xapple=	pre-configure
SUBST_MESSAGE.xapple=	Disabling APPLE App in cmake scripts
xapple_FIND_CMD=	cd ${WRKSRC} && \
			find . -name '*.cmake' -o -name CMakeLists.txt
SUBST_FILES.xapple=	${xapple_FIND_CMD:sh}
SUBST_SED.xapple+=	-e 's,APPLE,XAPPLE,'
SUBST_SED.xapple+=	-e 's,MACOSX_BUNDLE ,,'
SUBST_NOOP_OK.xapple=	yes # since SUBST_FILES is generated

SUBST_CLASSES+=		pyqt
SUBST_STAGE.pyqt=	pre-configure
SUBST_MESSAGE.pyqt=	Use correct python version for PyQt6 programs
SUBST_FILES.pyqt=	cmake/FindPyQt6.cmake
SUBST_SED.pyqt+=	-e '/^ *SET/s,pyuic6,&-${PYVERSSUFFIX},'
# pyrcc??
#SUBST_SED.pyqt+=	-e '/^ *SET/s,pyrcc6,&-${PYVERSSUFFIX},'
SUBST_SED.pyqt+=	-e '/ *FIND_PROGRAM(__pyuic6 /s,"pyuic6,&-${PYVERSSUFFIX},'

# Optimize for understandability when the build output is examined,
# because it is only examined when there are failures.
CMAKE_CONFIGURE_ARGS+=		-DCMAKE_VERBOSE_MAKEFILE=TRUE

# qgis looks for ccache and uses it, which does not play well with wrappers.
# Plus, there's something buggy about ccache, precompiled headers, and gcc.
CMAKE_CONFIGURE_ARGS+=		-DUSE_CCACHE:BOOL=FALSE

# Precompiled headers are buggy in the presence of ASLR.
#   https://gcc.gnu.org/bugzilla/show_bug.cgi?id=71934
#   https://gnats.netbsd.org/cgi-bin/query-pr-single.pl?number=59746
CMAKE_CONFIGURE_ARGS+=		-DUSE_PRECOMPILED_HEADERS:BOOL=FALSE

CMAKE_CONFIGURE_ARGS+=		-DWITH_BINDINGS:BOOL=TRUE

CMAKE_CONFIGURE_ARGS+=		-DWITH_INTERNAL_MARKUPSAFE=FALSE
CMAKE_CONFIGURE_ARGS+=		-DWITH_INTERNAL_NLOHMANN_JSON=OFF

# \todo Find/package qwt and re-enable.
# We patch cmake to look only in QWT_DIR, so provide it.
#CMAKE_CONFIGURE_ARGS+=		-DQWT_DIR=${QWT_DIR}

# \todo Understand and fix
CMAKE_CONFIGURE_ARGS+=		-DWITH_QTWEBENGINE=FALSE
# ? DEPENDS+= ../../www/qt6-qtwebengine

# \todo gc if not needed
#CMAKE_CONFIGURE_ARGS+=		-DWITH_QTWEBKIT=FALSE

CMAKE_CONFIGURE_ARGS+=		-DWITH_SERVER:BOOL=TRUE
# Upstream installs in an OS-specific place by default, but
# we want the pkgsrc place on all systems.
CMAKE_CONFIGURE_ARGS+=		-DQGIS_CGIBIN_SUBDIR=libexec/cgi-bin

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

.include "../../lang/python/pyversion.mk"
# qgis 4 has not been tested with 311, 312, 314.
PYTHON_VERSIONS_INCOMPATIBLE=	310

.include "../../mk/pgsql.buildlink3.mk"

# ? DEPENDS+= ../../not-in-pkgsrc/laz-perf

.include "../../archivers/libzip/buildlink3.mk"
.include "../../archivers/zstd/buildlink3.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../devel/protobuf/buildlink3.mk"
.include "../../devel/qt6-qttools/buildlink3.mk"
.include "../../geography/draco/buildlink3.mk"
.include "../../geography/gdal-lib/buildlink3.mk"
.include "../../geography/libspatialite/buildlink3.mk"
.include "../../geography/pdal-lib/buildlink3.mk"
.include "../../geography/proj/buildlink3.mk"
.include "../../geography/qt6-qtpositioning/buildlink3.mk"
.include "../../geography/spatialindex/buildlink3.mk"
.include "../../graphics/exiv2/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/qt6-qt3d/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../math/gsl/buildlink3.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../multimedia/qt6-qtmultimedia/buildlink3.mk"
.include "../../security/libtasn1/buildlink3.mk"
.include "../../security/qca2-qt6/buildlink3.mk"
.include "../../security/qt6-qtkeychain/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../textproc/nlohmann-json/buildlink3.mk"
.include "../../www/fcgi/buildlink3.mk"
.include "../../x11/qt6-qscintilla/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../x11/qt6-qtserialport/buildlink3.mk"
# \todo Package?
#.include "../../x11/qwt6-qt6/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
