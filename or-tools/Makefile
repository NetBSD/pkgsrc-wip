# $NetBSD$

#GITHUB_TAG=	refs/tags/v${PKGVERSION_NOREV}
GITHUB_TAG=	v99bugfix
DISTNAME=	or-tools-99bugfix
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_GITHUB:=google/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/google/or-tools/
COMMENT=	Google's Operations Research tools
LICENSE=	apache-2.0

USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake

FORCE_CXX_STD=	c++20

WRKSRC=		${WRKDIR}/${DISTNAME}

CMAKE_CONFIGURE_ARGS+=	-DUSE_COINOR=OFF
CMAKE_CONFIGURE_ARGS+=	-DBUILD_EXAMPLES=OFF

.include "../../wip/HiGHS/buildlink3.mk"
.include "../../wip/scip/buildlink3.mk"
.include "../../wip/ThirdParty-Mumps/buildlink3.mk"
.include "../../wip/nauty/buildlink3.mk"
.include "../../wip/ThirdParty-ASL/buildlink3.mk"
.include "../../devel/abseil/buildlink3.mk"
.include "../../math/openblas/buildlink3.mk"
.include "../../math/coinmp/buildlink3.mk"
.include "../../math/eigen3/buildlink3.mk"
.include "../../devel/googletest/buildlink3.mk"
.include "../../devel/gflags/buildlink3.mk"
.include "../../devel/protobuf/buildlink3.mk"
.include "../../devel/re2/buildlink3.mk"
.include "../../devel/google-glog/buildlink3.mk"
.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"
