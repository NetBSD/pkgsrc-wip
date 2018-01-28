# $NetBSD: Makefile,v 1.5 2012/10/07 20:11:09 asau Exp $
#

DISTNAME=	xf86-video-geode-2.11.4
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_XORG:=driver/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	joerg@NetBSD.org
HOMEPAGE=	http://wiki.x.org/wiki/GeodeDriver
COMMENT=	Modular Xorg AMD Geode GX/LX driver

# http://bugs.freedesktop.org/show_bug.cgi?id=23590
ONLY_FOR_PLATFORM=	*-*-i386

USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config

.include "../../x11/modular-xorg-server/buildlink3.mk"
.include "../../x11/fontsproto/buildlink3.mk"
.include "../../x11/xf86dgaproto/buildlink3.mk"
.include "../../x11/xproto/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
