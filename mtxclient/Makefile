# $NetBSD$

DISTNAME=	mtxclient-0.10.1
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=Nheko-Reborn/}
GITHUB_TAG=	refs/tags/v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/Nheko-Reborn/mtxclient/
COMMENT=	Client API library for the Matrix protocol
LICENSE=	mit

WRKSRC=	${WRKDIR}/${DISTNAME}

USE_LANGUAGES+=		c c++
USE_CXX_FEATURES+=	c++20

USE_TOOLS+=	pkg-config cmake

CMAKE_CONFIGURE_ARGS+=	-DBUILD_LIB_TESTS=OFF
CMAKE_CONFIGURE_ARGS+=	-DBUILD_LIB_EXAMPLES=OFF

.include "../../devel/cmake/build.mk"
.include "../../devel/meson/build.mk"
USE_BUILTIN.libevent=	no
.include "../../devel/libevent/buildlink3.mk"
.include "../../devel/re2/buildlink3.mk"
.include "../../devel/spdlog/buildlink3.mk"
.include "../../security/olm/buildlink3.mk"
.include "../../textproc/nlohmann-json/buildlink3.mk"
.include "../../wip/coeurl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
