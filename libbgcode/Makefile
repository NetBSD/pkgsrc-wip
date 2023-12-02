# $NetBSD$

DISTNAME=	libbgcode-20231123
CATEGORIES=	cad
MASTER_SITES=	${MASTER_SITE_GITHUB:=prusa3d/}
GITHUB_PROJECT=	libbgcode
GITHUB_TAG=	bc390aab4427589a6402b4c7f65cf4d0a8f987ec

MAINTAINER=	stix@stix.id.au
HOMEPAGE=	https://www.github.com/prusa3d/libbgcode
COMMENT=	XXX
LICENSE=	gnu-agpl-v3

USE_LANGUAGES=	c c++
USE_TOOLS+=	cmake gmake
USE_CMAKE=	yes
#CMAKE_ARGS+=	-DLibBGCode_BUILD_DEPS=on

# CMake goes looking for this binary. Make it happy.
pre-configure:
	${LN} -s ${PREFIX}/bin/heatshrink ${BUILDLINK_DIR}/bin/

.include "../../mk/bsd.prefs.mk"

.include "../../devel/boost-headers/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/catch2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../wip/heatshrink/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
