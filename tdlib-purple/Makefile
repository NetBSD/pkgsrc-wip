# $NetBSD$

DISTNAME=	tdlib-purple-0.7.4
CATEGORIES=	chat
MASTER_SITES=	${MASTER_SITE_GITHUB:=ars3niy/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ars3niy/tdlib-purple/
COMMENT=	Libpurple Telegram plugin using tdlib
LICENSE=	gnu-gpl-v2

USE_CMAKE=		yes
USE_TOOLS+=		gettext pkg-config
USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		c++

CMAKE_ARGS+=	-DNoWebp=TRUE
CMAKE_ARGS+=	-DNoLottie=TRUE
CMAKE_ARGS+=	-DNoVoip=TRUE

PKGCONFIG_OVERRIDE+=	fmt/support/cmake/fmt.pc.in
PKGCONFIG_OVERRIDE+=	rlottie/rlottie.pc.in

.include "../../chat/libpurple/buildlink3.mk"
.include "../../wip/tdlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
