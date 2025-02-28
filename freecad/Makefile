# $NetBSD$

VERSION=	1.0.0
DISTNAME=	freecad_source
PKGNAME=	freecad-${VERSION}
CATEGORIES=	cad
MASTER_SITES=	${MASTER_SITE_GITHUB:=FreeCAD/}
GITHUB_PROJECT=	FreeCAD
GITHUB_RELEASE=	${VERSION}

EXTRACT_SUFX=	.tar.gz

MAINTAINER=	rumko@NetBSD.org
HOMEPAGE=	http://www.freecadweb.org/
COMMENT=	General purpose parametric 3D CAD modeler
LICENSE=	gnu-lgpl-v2

WRKSRC=		${WRKDIR}

PYTHON_VERSIONS_ACCEPTED=	311
#USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		c c++
USE_CMAKE=		yes
USE_TOOLS+=		perl

CXXFLAGS.FreeBSD+=	-fPIC
LDFLAGS.FreeBSD+=	-fPIC

CMAKE_CONFIGURE_ARGS+=		-DCMAKE_INSTALL_HOMEDIR:PATH=${PREFIX}/freecad
CMAKE_CONFIGURE_ARGS+=		-DCMAKE_CXX_FLAGS=${CXXFLAGS:Q}
CMAKE_CONFIGURE_ARGS+=		-DCMAKE_SHARED_LINKER_FLAGS=${LDFLAGS:Q}
#CMAKE_CONFIGURE_ARGS+=		-DCMAKE_VERBOSE_MAKEFILE=ON

CMAKE_CONFIGURE_ARGS+=		-DFREECAD_USE_EXTERNAL_KDL=ON

SUBST_CLASSES+=		eol
SUBST_MESSAGE.eol=	Removing DOS line-ends
SUBST_STAGE.eol=	post-extract
SUBST_FILES.eol=	src/App/Application.cpp src/App/FreeCADInit.py src/Main/Main*.cpp src/Mod/Inspection/CMakeLists.txt
SUBST_FILTER_CMD.eol=	${TR} -d '\r'

REPLACE_PYTHON+=	src/Tools/wiki2qhelp.py src/Tools/PythonToCPP.py src/Tools/githubstats.py src/Tools/updatefromcrowdin.py src/Tools/updatecrowdin.py src/Tools/updateppa.py
REPLACE_PYTHON+=	src/Tools/generateBase/generateModel_Module.py src/Tools/generateBase/generateDS.py
REPLACE_PYTHON+=	src/Mod/Test/testmakeWireString.py src/Mod/Test/testPathArray.py src/Mod/Test/testPathArraySel.py src/Mod/Test/unittestgui.py
REPLACE_PYTHON+=	src/Mod/Robot/MovieTool.py src/Mod/OpenSCAD/prototype.py

# TODO - src/Mod/Draft/importDWG.py: teigha = "/usr/bin/TeighaFileConverter"

# Arch module deps
#.include "../../wip/py-pivy/buildlink3.mk"

# Fem module deps
#.include "../../wip/calculix/buildlink3.mk"

# Plot module deps
#DEPENDS+=	${PYPKGPREFIX}-matplotlib-[0-9]*:../../graphics/py-matplotlib
DEPENDS+=	${PYPKGPREFIX}-boost-[0-9]*:../../devel/py-boost

.include "../../devel/cmake/build.mk"

.include "../../lang/python/application.mk"
.include "../../wip/orocos-kdl/buildlink3.mk"
.include "../../cad/occt/buildlink3.mk"
.include "../../wip/py-pyside-setup/buildlink3.mk"
.include "../../wip/soqt/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
#.include "../../x11/qt5-qttools/buildlink3.mk"
.include "../../graphics/Coin/buildlink3.mk"
.include "../../graphics/vtk/buildlink3.mk"
.include "../../math/eigen3/buildlink3.mk"
.include "../../textproc/yaml-cpp/buildlink3.mk"
.include "../../textproc/xerces-c/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
