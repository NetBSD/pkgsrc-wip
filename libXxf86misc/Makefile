# $NetBSD: Makefile,v 1.1.1.1 2006/04/21 04:17:14 jeremy-c-reed Exp $
#

DISTNAME=		libXxf86misc-1.0.0
CATEGORIES=		x11
MASTER_SITES=		http://xorg.freedesktop.org/releases/individual/lib/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		INSERT_YOUR_MAIL_ADDRESS_HERE
HOMEPAGE=		http://xorg.freedesktop.org/releases/individual/lib/
COMMENT=		Library for the XFree86-Misc X extension

USE_LIBTOOL=		yes
PKGCONFIG_OVERRIDE+=	${WRKSRC}/xxf86misc.pc.in
USE_TOOLS+=		pkg-config
GNU_CONFIGURE=		yes

.include "../../x11/xproto/buildlink3.mk"
.include "../../wip/libX11/buildlink3.mk"
.include "../../x11/xextproto/buildlink3.mk"
.include "../../wip/xf86miscproto/buildlink3.mk"
.include "../../wip/libXext/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
