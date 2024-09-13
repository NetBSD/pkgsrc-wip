# $NetBSD$

GITHUB_TAG=	24Q3
DISTNAME=	${GITHUB_TAG}
PKGNAME=	${GITHUB_PROJECT}-${GITHUB_TAG}
CATEGORIES=	cad
MASTER_SITES=	${MASTER_SITE_GITHUB:=The-OpenROAD-Project/}
GITHUB_PROJECT=	OpenROAD

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/The-OpenROAD-Project/OpenROAD/
COMMENT=	ASIC physical design tool
LICENSE=	modified-bsd

USE_LANGUAGES=	c c++
USE_TOOLS+=	bison bash gmake

CXXFLAGS+=	-I${PREFIX}/include/eigen3
CXXFLAGS+=	-I${PREFIX}/include/sta
CXXFLAGS+=	-I${PREFIX}/include/abc
CXXFLAGS+=	-DABC_NAMESPACE=abc
CXXFLAGS+=	-DBOOST_STACKTRACE_GNU_SOURCE_NOT_REQUIRED

GCC_REQD+=	13
FORCE_CXX_STD=	c++20

CMAKE_CONFIGURE_ARGS+=	-DUSE_SYSTEM_OPENSTA=ON
CMAKE_CONFIGURE_ARGS+=	-DUSE_SYSTEM_BOOST=ON
CMAKE_CONFIGURE_ARGS+=	-DUSE_SYSTEM_ABC=ON
CMAKE_CONFIGURE_ARGS+=	-DENABLE_TESTS=OFF
CMAKE_CONFIGURE_ARGS+=	-DOPENSTA_HOME=${PREFIX}/share/sta

TOOL_DEPENDS+=	doxygen-[0-9]*:../../devel/doxygen

LDFLAGS+=	-lcudd

.include "../../lang/tcl/buildlink3.mk"
.include "../../lang/python/pyversion.mk"
.include "../../lang/python/tool.mk"
.include "../../wip/or-tools/buildlink3.mk"
.include "../../wip/abc/buildlink3.mk"
.include "../../wip/OpenSTA/buildlink3.mk"
.include "../../wip/nauty/buildlink3.mk"
.include "../../wip/cudd/buildlink3.mk"
.include "../../wip/coin-or-lemon/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/abseil/buildlink3.mk"
.include "../../devel/cmake/build.mk"
.include "../../devel/protobuf/buildlink3.mk"
.include "../../devel/re2/buildlink3.mk"
.include "../../devel/swig4/buildlink3.mk"
.include "../../devel/spdlog/buildlink3.mk"
.include "../../math/coinmp/buildlink3.mk"
.include "../../math/openblas/buildlink3.mk"
.include "../../textproc/fmtlib/buildlink3.mk"
.include "../../wip/ThirdParty-ASL/buildlink3.mk"
.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"
