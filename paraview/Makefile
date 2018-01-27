# $NetBSD: Makefile,v 1.11 2014/08/11 23:10:13 thomasklausner Exp $

VER=		4.0.1
PKGNAME=	paraview-${VER}
DISTNAME=	ParaView-v${VER}-source
PKGREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	http://paraview.org/files/v4.0/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pouya@san-serriffe.org
HOMEPAGE=	http://www.paraview.org/
COMMENT=	ParaView is a data analysis and scientific visualization application
LICENSE=	paraview-license

USE_LANGUAGES=		c c++ fortran
USE_TOOLS+=		gmake
DEPENDS+=		qt4-sqlite3>=4.0:../../x11/qt4-sqlite3

USE_CMAKE=		yes
CHECK_PORTABILITY_SKIP=	Utilities/protobuf/configure

CMAKE_ARGS+=			-DCMAKE_BUILD_TYPE=Release
CMAKE_ARGS+=			-DBUILD_SHARED_LIBS=ON
CMAKE_ARGS+=			-DPARAVIEW_USE_MPI=OFF
CMAKE_ARGS+=			-DVTK_USE_SYSTEM_HDF5=ON

# python related options
CMAKE_ARGS+=			-DPARAVIEW_ENABLE_PYTHON=ON
CMAKE_ARGS+=			-DPYTHON_LIBRARY=${PREFIX}/lib/libpython${PYVERSSUFFIX}.so
CMAKE_ARGS+=			-DPYTHON_INCLUDE_DIR=${PREFIX}/${PYINC}

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

CMAKE_ARG_PATH=			..
CONFIGURE_DIRS=			_ParaView_build

PY_PATCHPLIST=			yes

# to make protoc work during installation
# http://paraview.org/Bug/view.php?id=12852
# 
# For 3.98 it fails to run vtkkwProcessXML-pv3.98
# with the following error message
# _ParaView_build/bin/vtkkwProcessXML-pv3.98: error while loading
# shared libraries: libvtkCommonCore-pv3.98.so.1: cannot open shared
# object file: No such file or directory
# 
# I add ${WRKSRC}/_ParaView_build/lib/ to LD_LIBRARY_PATH to solve it
MAKE_ENV+=			LD_LIBRARY_PATH=${WRKSRC}/_ParaView_build/bin:${WRKSRC}/_ParaView_build/lib/

pre-configure:
	${MKDIR} ${WRKSRC}/_ParaView_build

do-test:
	${RUN} cd ${WRKSRC}/_ParaView_build ; ${SETENV} ${MAKE_ENV} ${MAKE} test

#.include "../../mk/mpi.buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../x11/qt4-tools/buildlink3.mk"
.include "../../x11/qt4-libs/buildlink3.mk"
.include "../../multimedia/ffmpeg1/buildlink3.mk"
.include "../../audio/faad2/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
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
