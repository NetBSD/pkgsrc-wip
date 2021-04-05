# $NetBSD$

DISTNAME=	xwallpaper-0.6.6
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_GITHUB:=stoeckmann/xwallpaper/releases/download/v0.6.6/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	tpaul@NetBSD.org
HOMEPAGE=	https://github.com/stoeckmann/xwallpaper/releases/download/v0.6.6/
COMMENT=	Wallpaper setting utility for X
LICENSE=	isc

GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config

.include "options.mk"

.include "../../x11/pixman/buildlink3.mk"
.include "../../x11/xcb-util/buildlink3.mk"
.include "../../x11/xcb-util-image/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
