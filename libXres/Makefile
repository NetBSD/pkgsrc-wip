# $NetBSD: Makefile,v 1.19 2007/01/23 13:39:05 bsadewitz Exp $
#

DISTNAME=	libXres-1.0.3
CATEGORIES=	x11
MASTER_SITES=	http://xorg.freedesktop.org/releases/individual/lib/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	blair.sadewitz@gmail.com
HOMEPAGE=	http://xorg.freedesktop.org/
COMMENT=                X Resource Information Extension Library

PKG_DESTDIR_SUPPORT=    user-destdir

USE_LIBTOOL=            yes
GNU_CONFIGURE=          yes
USE_TOOLS+=             pkg-config

PKGCONFIG_OVERRIDE+=    xres.pc.in

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

PKGCONFIG_OVERRIDE+=	xres.pc.in

.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/resourceproto/buildlink3.mk"
.include "../../x11/xextproto/buildlink3.mk"
.include "../../x11/xproto/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
