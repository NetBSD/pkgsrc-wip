# $NetBSD$

GITHUB_TAG=	v${PKGVERSION_NOREV}
DISTNAME=	OpenROAD-2.0
CATEGORIES=	cad
MASTER_SITES=	${MASTER_SITE_GITHUB:=The-OpenROAD-Project/}
GITHUB_PROJECT=	OpenROAD
GITHUB_SUBMODULES+=	The-OpenROAD-Project OpenSTA 42b994d The_OpenROAD_Project_OpenSTA/src/sta

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/The-OpenROAD-Project/OpenROAD/
COMMENT=	ASIC physical design tool
LICENSE=	modified-bsd

USE_LANGUAGES=	c c++
USE_TOOLS+=	bison cmake bash gmake
USE_CMAKE=	yes

CXXFLAGS+=	-I${PREFIX}/include/eigen3 \

DATADIR=	${PREFIX}/share/openroad
DOCSDIR=	${PREFIX}/share/doc/openroad
EXAMPLESDIR=	${PREFIX}/share/examples/openroad

INSTALLATION_DIRS=	bin include lib ${PKGMANDIR}/man1 share/doc share/examples

DEPENDS+=       base64-[0-9]*:../../converters/base64

TOOL_DEPENDS+=  lemon>=1.0:../../devel/lemon
TOOL_DEPENDS+=  swig4-[0-9]*:../../devel/swig4

SUBST_SED.compiler=	-e 's|g++|'${CXX:Q}'|g'

UNRESOLVED_LIB_DEPS= libortools.so:math/or-tools \
		libcudd.so:math/cudd \
		libnauty.so:math/nauty \

.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/abseil/buildlink3.mk"
.include "../../devel/cmake/build.mk"
.include "../../devel/protobuf/buildlink3.mk"
.include "../../devel/re2/buildlink3.mk"
.include "../../devel/spdlog/buildlink3.mk"
.include "../../math/coinmp/buildlink3.mk"
.include "../../math/openblas/buildlink3.mk"
.include "../../textproc/fmtlib/buildlink3.mk"
.include "../../wip/ThirdParty-ASL/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
