# $NetBSD: Makefile,v 1.2 2009/08/09 22:09:36 thomasklausner Exp $
#

DISTNAME=	xf86-video-geode-2.11.3
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_XORG:=driver/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	joerg@NetBSD.org
HOMEPAGE=	http://cgit.freedesktop.org/xorg/driver/xf86-video-geode/
COMMENT=	Modular Xorg AMD Geode GX/LX driver

PKG_DESTDIR_SUPPORT=    user-destdir

USE_LIBTOOL=    yes
GNU_CONFIGURE=  yes
USE_TOOLS+=     pkg-config

.include "../../x11/modular-xorg-server/buildlink3.mk"
.include "../../x11/fontsproto/buildlink3.mk"
.include "../../x11/xf86dgaproto/buildlink3.mk"
.include "../../x11/xproto/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
