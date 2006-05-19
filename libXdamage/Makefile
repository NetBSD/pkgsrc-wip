# $NetBSD: Makefile,v 1.16 2006/05/19 16:51:21 ykomatsu Exp $
#

DISTNAME=		libXdamage-1.0.2.2
CATEGORIES=		x11 devel
MASTER_SITES=		http://xorg.freedesktop.org/releases/individual/lib/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://xorg.freedesktop.org/
COMMENT=		Xdamage extension (Library)

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config

PKGCONFIG_OVERRIDE+=	xdamage.pc.in

.include "../../wip/libX11/buildlink3.mk"
.include "../../wip/damageproto/buildlink3.mk"
.include "../../x11/xproto/buildlink3.mk"
.include "../../wip/libXfixes/buildlink3.mk"
.include "../../x11/fixesproto/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
