# $NetBSD$

DISTNAME=	ParaView-v5.12.1
PKGNAME=	${DISTNAME:S/ParaView-v/paraview-/1}
CATEGORIES=	math
MASTER_SITES=	https://www.paraview.org/files/v5.12/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.paraview.org/
COMMENT=	VTK-based Data Analysis and Visualization Application
#LICENSE=	# TODO: (see mk/license.mk)

USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		c c++ fortran
FORCE_CXX_STD+=		c++14

WRKSRC=		${WRKDIR}/${DISTNAME}

CMAKE_ARGS+=	-DCMAKE_BUILD_TYPE=Release
CMAKE_ARGS+=	-DPARAVIEW_USE_PYTHON=ON
CMAKE_ARGS+=	-DPARAVIEW_USE_MPI=OFF
CMAKE_ARGS+=	-DVTK_MODULE_USE_EXTERNAL_ParaView_protobuf=ON
CMAKE_ARGS+=	-DVTK_MODULE_USE_EXTERNAL_VTK_cgns=OFF
CMAKE_ARGS+=	-DVTK_MODULE_USE_EXTERNAL_VTK_cli11=OFF
CMAKE_ARGS+=	-DVTK_MODULE_USE_EXTERNAL_VTK_doubleconversion=ON
CMAKE_ARGS+=	-DVTK_MODULE_USE_EXTERNAL_VTK_eigen=ON
CMAKE_ARGS+=	-DVTK_MODULE_USE_EXTERNAL_VTK_expat=ON
CMAKE_ARGS+=	-DVTK_MODULE_USE_EXTERNAL_VTK_exprtk=OFF
CMAKE_ARGS+=	-DVTK_MODULE_USE_EXTERNAL_VTK_fmt=ON
CMAKE_ARGS+=	-DVTK_MODULE_USE_EXTERNAL_VTK_freetype=ON
CMAKE_ARGS+=	-DVTK_MODULE_USE_EXTERNAL_VTK_gl2ps=ON
CMAKE_ARGS+=	-DVTK_MODULE_USE_EXTERNAL_VTK_glew=ON
CMAKE_ARGS+=	-DVTK_MODULE_USE_EXTERNAL_VTK_hdf5=ON
CMAKE_ARGS+=	-DVTK_MODULE_USE_EXTERNAL_VTK_ioss=OFF
CMAKE_ARGS+=	-DVTK_MODULE_USE_EXTERNAL_VTK_jpeg=ON
CMAKE_ARGS+=	-DVTK_MODULE_USE_EXTERNAL_VTK_jsoncpp=ON
CMAKE_ARGS+=	-DVTK_MODULE_USE_EXTERNAL_VTK_libharu=ON
CMAKE_ARGS+=	-DVTK_MODULE_USE_EXTERNAL_VTK_libproj=ON
CMAKE_ARGS+=	-DVTK_MODULE_USE_EXTERNAL_VTK_libxml2=ON
CMAKE_ARGS+=	-DVTK_MODULE_USE_EXTERNAL_VTK_lz4=ON
CMAKE_ARGS+=	-DVTK_MODULE_USE_EXTERNAL_VTK_lzma=ON
CMAKE_ARGS+=	-DVTK_MODULE_USE_EXTERNAL_VTK_netcdf=ON
CMAKE_ARGS+=	-DVTK_MODULE_USE_EXTERNAL_VTK_nlohmannjson=ON
CMAKE_ARGS+=	-DVTK_MODULE_USE_EXTERNAL_VTK_ogg=ON
CMAKE_ARGS+=	-DVTK_MODULE_USE_EXTERNAL_VTK_png=ON
CMAKE_ARGS+=	-DVTK_MODULE_USE_EXTERNAL_VTK_pugixml=ON
CMAKE_ARGS+=	-DVTK_MODULE_USE_EXTERNAL_VTK_sqlite=ON
CMAKE_ARGS+=	-DVTK_MODULE_USE_EXTERNAL_VTK_theora=ON
CMAKE_ARGS+=	-DVTK_MODULE_USE_EXTERNAL_VTK_tiff=ON
CMAKE_ARGS+=	-DVTK_MODULE_USE_EXTERNAL_VTK_utf8=ON
CMAKE_ARGS+=	-DVTK_MODULE_USE_EXTERNAL_VTK_verdict=OFF
CMAKE_ARGS+=	-DVTK_MODULE_USE_EXTERNAL_VTK_zlib=ON
CMAKE_ARGS+=	-DVTK_SMP_ENABLE_OPENMP=ON

DEPENDS+=	${PYPKGPREFIX}-matplotlib-[0-9]*:../../graphics/py-matplotlib
#DEPENDS+=	${PYPKGPREFIX}-mpi4py-[0-9]*:../../wip/py-mpi4py

PY_PATCHPLIST=	yes

.include "../../devel/cmake/build.mk"

MAKE_ENV+=	LD_LIBRARY_PATH=${WRKSRC}/${CMAKE_BUILD_DIR}/lib

PRINT_PLIST_AWK+=	{gsub(/5.12/, "$${PV_VER}");}

PLIST_SUBST+=	PV_VER=5.12

.include "../../lang/python/extension.mk"

.include "../../archivers/lz4/buildlink3.mk"
.include "../../archivers/lzmalib/buildlink3.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../devel/hdf5/buildlink3.mk"
.include "../../devel/netcdf-cxx/buildlink3.mk"
.include "../../devel/protobuf/buildlink3.mk"
.include "../../geography/proj/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/gl2ps/buildlink3.mk"
.include "../../graphics/glew/buildlink3.mk"
.include "../../graphics/graphviz/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../math/double-conversion/buildlink3.mk"
.include "../../math/eigen3/buildlink3.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../multimedia/libogg/buildlink3.mk"
.include "../../multimedia/libtheora/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../textproc/fmtlib/buildlink3.mk"
.include "../../textproc/jsoncpp/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../textproc/nlohmann-json/buildlink3.mk"
.include "../../textproc/pugixml/buildlink3.mk"
.include "../../textproc/utf8-cpp/buildlink3.mk"
.include "../../wip/libharu/buildlink3.mk"
.include "../../x11/libXaw/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qtx11extras/buildlink3.mk"
.include "../../x11/qt5-qttools/buildlink3.mk"
.include "../../x11/qt5-qtxmlpatterns/buildlink3.mk"
.include "../../x11/qt5-qtsvg/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/mpi.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
