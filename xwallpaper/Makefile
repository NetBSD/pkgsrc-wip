# $NetBSD$

GITHUB_RELEASE=	${PKGVERSION_NOREV}
DISTNAME=	xwallpaper-0.7.3
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_GITHUB:=stoeckmann/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	tpaul@NetBSD.org
HOMEPAGE=	https://github.com/stoeckmann/xwallpaper
COMMENT=	Wallpaper setting utility for X
LICENSE=	isc

GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config

.include "options.mk"

.include "../../x11/pixman/buildlink3.mk"
.include "../../x11/xcb-util/buildlink3.mk"
.include "../../x11/xcb-util-image/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
