# $NetBSD$

GITHUB_TAG=	refs/tags/v${PKGVERSION_NOREV}
DISTNAME=	or-tools-9.10
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_GITHUB:=google/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/google/or-tools/
COMMENT=	Google's Operations Research tools
LICENSE=	apache-2.0

USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake

.include "../../wip/ThirdParty-Mumps/buildlink3.mk"
.include "../../wip/ThirdParty-ASL/buildlink3.mk"
.include "../../devel/abseil/buildlink3.mk"
.include "../../math/openblas/buildlink3.mk"
.include "../../devel/gflags/buildlink3.mk"
.include "../../devel/protobuf/buildlink3.mk"
.include "../../devel/re2/buildlink3.mk"
.include "../../devel/google-glog/buildlink3.mk"
.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"

# from dbsd ports
# LIB_DEPENDS=	OK libabsl_base.so:devel/abseil \
# 		OK libcoinasl.so:math/asl \
# 		OK libcoinmumps.so:math/coin-or-mumps \
# 		OK libgflags.so:devel/gflags \
# 		OK libglog.so:devel/glog \
# 		OK libopenblas.so:math/openblas \
# 		OK libprotobuf.so:devel/protobuf \
# 		OK libre2.so:devel/re2
#
# 		libnauty.so:math/nauty \
# 		libCbc.so:math/cbc \
# 		libCgl.so:math/cgl \
# 		libCoinUtils.so:math/coinutils \
# 		libOsi.so:math/osi \
# 		libOsiClp.so:math/clp \
#
# USES=		blaslapack cmake:testing compiler:c++17-lang eigen:3 pkgconfig
