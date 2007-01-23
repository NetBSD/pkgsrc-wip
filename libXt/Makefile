# $NetBSD: Makefile,v 1.22 2007/01/23 13:40:57 bsadewitz Exp $
#

DISTNAME=	libXt-1.0.4
CATEGORIES=	x11
MASTER_SITES=	http://xorg.freedesktop.org/releases/individual/lib/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	blair.sadewitz@gmail.com
HOMEPAGE=	http://xorg.freedesktop.org/releases/individual/lib/
COMMENT=	X intrinsics library from modular X.org (current version)

CONFIGURE_ARGS+=	--with-appdefaultdir=${PREFIX}/lib/X11/app-defaults
CONFIGURE_ENV+=		APP_MAN_SUFFIX=1 LIB_MAN_SUFFIX=3


GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

PKGCONFIG_OVERRIDE+=	xt.pc.in

.include "../../x11/libSM/buildlink3.mk"
.include "../../wip/libX11/buildlink3.mk"
.include "../../x11/kbproto/buildlink3.mk"
.include "../../x11/xproto/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
