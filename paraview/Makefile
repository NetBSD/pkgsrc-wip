# $NetBSD: Makefile,v 1.2 2010/08/21 17:41:58 asau Exp $
#

PKGNAME=	paraview-3.8.0
DISTNAME=	ParaView-3.8.0
CATEGORIES=	graphics
MASTER_SITES=	http://www.paraview.org/files/v3.8/

MAINTAINER=	pouya@san-serriffe.org
HOMEPAGE=	http://www.paraview.org/
COMMENT=	ParaView is a data analysis and scientific visualization application
LICENSE=	paraview-license

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=			c c++ fortran
USE_TOOLS+=				gmake
DEPENDS+=				qt4-sqlite3:../../x11/qt4-sqlite3

USE_CMAKE=				yes

CMAKE_ARGS+=			-DCMAKE_INSTALL_PREFIX:STRING=${PREFIX:Q}
CMAKE_ARGS+=			-DCMAKE_BUILD_TYPE=Release
CMAKE_ARGS+=			-DBUILD_SHARED_LIBS=ON
CMAKE_ARGS+=			-DPARAVIEW_USE_MPI=OFF
CMAKE_ARGS+=			-DPARAVIEW_USE_SYSTEM_HDF5=ON
CMAKE_ARGS+=			-DPARAVIEW_ENABLE_PYTHON=ON
CMAKE_ARGS+=			-DPARAVIEW_BUILD_QT_GUI=ON
CMAKE_ARGS+=			-DPARAVIEW_INSTALL_DEVELOPMENT=ON
CMAKE_ARGS+=			-DPARAVIEW_GENERATE_PROXY_DOCUMENTATION=ON
CMAKE_ARGS+=			-DQT_QMAKE_EXECUTABLE=${QTDIR}/bin/qmake
CMAKE_ARGS+=			-DFREETYPE_INCLUDE_DIR_FTHEADER=${PREFIX}/include/freetype2/freetype
CMAKE_ARGS+=			-DVTK_USE_SYSTEM_PNG=ON \
						-DVTK_USE_SYSTEM_JPEG=ON \
						-DVTK_USE_SYSTEM_TIFF=ON \
						-DVTK_USE_SYSTEM_ZLIB=ON \
						-DVTK_USE_SYSTEM_FREETYPE=ON \
						-DVTK_USE_SYSTEM_EXPAT=ON \
						-DVTK_USE_SYSTEM_LIBXML2=ON \
						-DVTK_USE_X=ON


CMAKE_ARG_PATH= 		..
CONFIGURE_DIRS= 		_ParaView_build

PY_PATCHPLIST=			yes
#PYDISTUTILSPKG=         yes
#PLIST_SUBST+=           PYVERSSUFFIX=${PYVERSSUFFIX}

pre-configure:
	${MKDIR} ${WRKSRC}/_ParaView_build


#.include "../../mk/mpi.buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../x11/qt4-tools/buildlink3.mk"
.include "../../x11/qt4-libs/buildlink3.mk"
.include "../../multimedia/ffmpeg/buildlink3.mk"
.include "../../audio/faad2/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../lang/python/application.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../devel/hdf5/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
#.include "../../databases/sqlite3/buildlink3.mk"


.include "../../mk/bsd.pkg.mk"
