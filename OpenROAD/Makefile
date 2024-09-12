# $NetBSD$

GITHUB_TAG=	${PKGVERSION_NOREV}
DISTNAME=	OpenROAD-24Q3
CATEGORIES=	cad
MASTER_SITES=	${MASTER_SITE_GITHUB:=The-OpenROAD-Project/}
GITHUB_PROJECT=	OpenROAD

#GITHUB_SUBMODULES+=	The-OpenROAD-Project OpenSTA v2.2.0 src/sta
GITHUB_SUBMODULES+=	The-OpenROAD-Project abc ef5389d31526003c2ebd7e6d6d6fe3848a20f0a2 third-party/abc

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/The-OpenROAD-Project/OpenROAD/
COMMENT=	ASIC physical design tool
LICENSE=	modified-bsd

USE_LANGUAGES=	c c++
USE_TOOLS+=	bison bash gmake doxygen swig3.0

CXXFLAGS+=	-I${PREFIX}/include/eigen3
GCC_REQD+=	10
FORCE_CXX_STD=	c++20

CMAKE_CONFIGURE_ARGS+=	-DUSE_SYSTEM_OPENSTA=ON
CMAKE_CONFIGURE_ARGS+=	-DOPENSTA_HOME=${PREFIX}

#DATADIR=	${PREFIX}/share/openroad
#DOCSDIR=	${PREFIX}/share/doc/openroad
#EXAMPLESDIR=	${PREFIX}/share/examples/openroad

#INSTALLATION_DIRS=	bin include lib ${PKGMANDIR}/man1 share/doc share/examples

TOOL_DEPENDS+=	doxygen-[0-9]*:../../devel/doxygen

SUBST_SED.compiler=	-e 's|g++|'${CXX:Q}'|g'

.include "../../lang/tcl/buildlink3.mk"
.include "../../lang/python/pyversion.mk"
.include "../../lang/python/tool.mk"
.include "../../wip/or-tools/buildlink3.mk"
.include "../../wip/OpenSTA/buildlink3.mk"
.include "../../wip/nauty/buildlink3.mk"
.include "../../wip/cudd/buildlink3.mk"
.include "../../wip/coin-or-lemon/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/abseil/buildlink3.mk"
.include "../../devel/cmake/build.mk"
.include "../../devel/protobuf/buildlink3.mk"
.include "../../devel/re2/buildlink3.mk"
.include "../../devel/swig3/buildlink3.mk"
.include "../../devel/spdlog/buildlink3.mk"
.include "../../math/coinmp/buildlink3.mk"
.include "../../math/openblas/buildlink3.mk"
.include "../../textproc/fmtlib/buildlink3.mk"
.include "../../wip/ThirdParty-ASL/buildlink3.mk"
.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"
