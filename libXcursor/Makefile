# $NetBSD: Makefile,v 1.17 2006/05/19 16:51:21 ykomatsu Exp $
#

DISTNAME=		libXcursor-1.1.5.2
CATEGORIES=		x11 devel
MASTER_SITES=		http://xorg.freedesktop.org/releases/individual/lib/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://xorg.freedesktop.org/
COMMENT=		Client-side cursor loading library for X

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config

PKGCONFIG_OVERRIDE+=	xcursor.pc.in

.include "../../x11/fixesproto/buildlink3.mk"
.include "../../x11/xproto/buildlink3.mk"
.include "../../wip/libX11/buildlink3.mk"
.include "../../wip/libXfixes/buildlink3.mk"
.include "../../wip/libXrender/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
