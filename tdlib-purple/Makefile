# $NetBSD$

DISTNAME=	tdlib-purple-0.7.7
CATEGORIES=	chat
MASTER_SITES=	${MASTER_SITE_GITHUB:=ars3niy/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	leot@NetBSD.org
HOMEPAGE=	https://github.com/ars3niy/tdlib-purple/
COMMENT=	Libpurple Telegram plugin using tdlib
LICENSE=	gnu-gpl-v2

USE_CMAKE=		yes
USE_TOOLS+=		gettext pkg-config
USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		c++

# Pass STUFF to avoid possible API_ID_PUBLISHED_FLOOD errors and
# building the package similarly to upstream binary packages:
#  https://github.com/ars3niy/tdlib-purple/issues/95
CMAKE_CONFIGURE_ARGS+=	-DSTUFF="AFADBDIyvuCrHF@E@GCC@qAvGus@rIArrGGtIvqC"
CMAKE_CONFIGURE_ARGS+=	-DNoWebp=TRUE
CMAKE_CONFIGURE_ARGS+=	-DNoLottie=TRUE
CMAKE_CONFIGURE_ARGS+=	-DNoVoip=TRUE

PKGCONFIG_OVERRIDE+=	fmt/support/cmake/fmt.pc.in
PKGCONFIG_OVERRIDE+=	rlottie/rlottie.pc.in

.include "../../chat/libpurple/buildlink3.mk"
.include "../../wip/tdlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
