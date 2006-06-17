# $NetBSD: Makefile,v 1.2 2006/06/17 19:08:45 jeremy-c-reed Exp $
#

DISTNAME=		libXxf86vm-1.0.0
CATEGORIES=		x11
MASTER_SITES=		http://xorg.freedesktop.org/releases/individual/lib/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		reed@reedmedia.net
HOMEPAGE=		http://xorg.freedesktop.org/releases/individual/lib/
COMMENT=		Library for the XFree86-VidMode X extension

USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config
GNU_CONFIGURE=		yes

PKGCONFIG_OVERRIDE+=	xxf86vm.pc.in
CONFIGURE_ENV+=		LIB_MAN_SUFFIX=3

.include "../../x11/xproto/buildlink3.mk"
.include "../../wip/libX11/buildlink3.mk"
.include "../../x11/xextproto/buildlink3.mk"
.include "../../wip/xf86vidmodeproto/buildlink3.mk"
.include "../../wip/libXext/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
