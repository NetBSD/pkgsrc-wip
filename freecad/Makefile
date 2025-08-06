# $NetBSD$

VERSION=	1.0.2
DISTNAME=	freecad_source
PKGNAME=	freecad-${VERSION}
CATEGORIES=	cad
MASTER_SITES=	${MASTER_SITE_GITHUB:=FreeCAD/}
GITHUB_PROJECT=	FreeCAD
GITHUB_RELEASE=	${VERSION}
DIST_SUBDIR=	${PKGNAME_NOREV}

MAINTAINER=	rumko@NetBSD.org
HOMEPAGE=	http://www.freecadweb.org/
COMMENT=	General purpose parametric 3D CAD modeler
LICENSE=	gnu-lgpl-v2

WRKSRC=		${WRKDIR}

USE_LANGUAGES=			c c++
USE_TOOLS+=			perl
USE_TOOLS+=			gmake
USE_CXX_FEATURES=		c++17
BUILDLINK_TRANSFORM.NetBSD+=	rm:-ldl
ICON_THEMES=			yes

CXXFLAGS.FreeBSD+=	-fPIC
LDFLAGS.FreeBSD+=	-fPIC

CMAKE_CONFIGURE_ARGS+=		-DCMAKE_INSTALL_HOMEDIR:PATH=${PREFIX}/freecad
CMAKE_CONFIGURE_ARGS+=		-DCMAKE_CXX_FLAGS=${CXXFLAGS:Q}
CMAKE_CONFIGURE_ARGS+=		-DCMAKE_SHARED_LINKER_FLAGS=${LDFLAGS:Q}
CMAKE_CONFIGURE_ARGS+=		-DFREECAD_QT_VERSION="6"
CMAKE_CONFIGURE_ARGS+=		-DPYTHON_PACKAGES_PATH=${PYSITELIB}
CMAKE_CONFIGURE_ARGS+=		-DXDG_DATADIR="${PREFIX}/share"
CMAKE_CONFIGURE_ARGS+=		-DXDG_DATADIR="${PREFIX}/share"
CMAKE_CONFIGURE_ARGS+=		-DBUILD_ASSEMBLY="ON"
CMAKE_CONFIGURE_ARGS+=		-DBUILD_DESIGNER_PLUGIN="ON"
CMAKE_CONFIGURE_ARGS+=		-DBUILD_FLAT_MESH="ON"
CMAKE_CONFIGURE_ARGS+=		-DBUILD_TEST="OFF"
# Conflicts with devel/googletest, which is too old to use.
CMAKE_CONFIGURE_ARGS+=		-DENABLE_DEVELOPER_TESTS=OFF
CMAKE_CONFIGURE_ARGS+=		-DBUILD_VR="OFF"
CMAKE_CONFIGURE_ARGS+=		-DFREECAD_LIBPACK_USE="OFF"
CMAKE_CONFIGURE_ARGS+=		-DFREECAD_USE_EXTERNAL_FMT="ON"
CMAKE_CONFIGURE_ARGS+=		-DFREECAD_CREATE_MAC_APP="OFF"
CMAKE_CONFIGURE_ARGS+=		-DFREECAD_FREECAD_LIBPACK_USE="OFF"
CMAKE_CONFIGURE_ARGS+=		-DFREECAD_USE_EXTERNAL_KDL="OFF"
CMAKE_CONFIGURE_ARGS+=		-DFREECAD_USE_EXTERNAL_SMESH="OFF"
CMAKE_CONFIGURE_ARGS+=		-DFREECAD_USE_FREETYPE="ON"
CMAKE_CONFIGURE_ARGS+=		-DFREECAD_USE_PYBIND11="ON"
CMAKE_CONFIGURE_ARGS+=		-DUSE_CUDA="OFF"
CMAKE_CONFIGURE_ARGS+=		-DUSE_OPENCV="OFF"
CMAKE_CONFIGURE_ARGS+=		-Dpybind11_DIR=${PREFIX}/${PYSITELIB}/pybind11/share/cmake/pybind11

# Workaround for med's hdf5_110 version requirement, borrowed from freebsd ports.
CMAKE_CONFIGURE_ARGS+=		-DHDF5_CFLAGS="-I${BUILDLINK_DIR}/include"
CMAKE_CONFIGURE_ARGS+=		-DHDF5_FOUND=TRUE
CMAKE_CONFIGURE_ARGS+=		-DHDF5_VERSION="1.10.11"
CMAKE_CONFIGURE_ARGS+=		-DHDF5_INCLUDE_DIRS="${BUILDLINK_DIR}/include/hdf5-110"
CMAKE_CONFIGURE_ARGS+=		-DHDF5_LIBRARIES="-L${BUILDLINK_DIR}/lib -lhdf5-110"
CMAKE_CONFIGURE_ARGS+=		-DHDF5_LIBRARY_DIRS="${BUILDLINK_DIR}/lib"

SUBST_CLASSES+=		eol
SUBST_MESSAGE.eol=	Removing DOS line-ends
SUBST_STAGE.eol=	post-extract
SUBST_FILES.eol=	src/App/Application.cpp src/App/FreeCADInit.py src/Main/Main*.cpp src/Mod/Inspection/CMakeLists.txt
SUBST_FILTER_CMD.eol=	${TR} -d '\r'

REPLACE_PYTHON+=	src/Tools/wiki2qhelp.py src/Tools/PythonToCPP.py src/Tools/githubstats.py src/Tools/updatefromcrowdin.py src/Tools/updatecrowdin.py src/Tools/updateppa.py
REPLACE_PYTHON+=	src/Tools/generateBase/generateModel_Module.py src/Tools/generateBase/generateDS.py
REPLACE_PYTHON+=	src/Mod/Test/testmakeWireString.py src/Mod/Test/testPathArray.py src/Mod/Test/testPathArraySel.py src/Mod/Test/unittestgui.py
REPLACE_PYTHON+=	src/Mod/Robot/MovieTool.py src/Mod/OpenSCAD/prototype.py

PLIST_SUBST+=		PYSITELIB=${PYSITELIB}

SUBST_CLASSES+=		datadir
SUBST_MESSAGE.datadir=	Install data files to XDG_DATADIR
SUBST_STAGE.datadir=	post-extract
SUBST_FILES.datadir+=	src/XDGData/CMakeLists.txt
SUBST_FILES.datadir+=	src/Gui/CMakeLists.txt
SUBST_SED.datadir=	-e "s|CMAKE_INSTALL_DATAROOTDIR|XDG_DATADIR|g"

# TODO - src/Mod/Draft/importDWG.py: teigha = "/usr/bin/TeighaFileConverter"

.include "../../devel/cmake/build.mk"

# Fem module deps
#.include "../../wip/calculix/buildlink3.mk"

# Plot module deps
#DEPENDS+=	${PYPKGPREFIX}-matplotlib-[0-9]*:../../graphics/py-matplotlib
DEPENDS+=	${PYPKGPREFIX}-boost-[0-9]*:../../devel/py-boost

.include "../../cad/occt/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/py-boost/buildlink3.mk"
.include "../../devel/py-pybind11/buildlink3.mk"
.include "../../devel/qt6-qttools/buildlink3.mk"
.include "../../devel/swig4/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../wip/Coin/buildlink3.mk"
.include "../../graphics/freeimage/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/qt6-qtsvg/buildlink3.mk"
.include "../../graphics/vtk/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../math/eigen3/buildlink3.mk"
.include "../../textproc/fmtlib/buildlink3.mk"
.include "../../textproc/xerces-c/buildlink3.mk"
.include "../../textproc/yaml-cpp/buildlink3.mk"
.include "../../wip/hdf5_110/buildlink3.mk"
.include "../../wip/med/buildlink3.mk"
.include "../../wip/orocos-kdl/buildlink3.mk"
.include "../../wip/py-pyside6/buildlink3.mk"
.include "../../wip/py-pivy/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
