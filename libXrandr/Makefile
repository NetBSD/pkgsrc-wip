# $NetBSD: Makefile,v 1.4 2006/04/18 18:27:51 jeremy-c-reed Exp $
#

DISTNAME=		libXrandr-1.1.0.2
CATEGORIES=		x11 devel
MASTER_SITES=		http://xorg.freedesktop.org/releases/individual/lib/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://xorg.freedesktop.org/
COMMENT=		X RandR Library from X.org

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config

PKGCONFIG_OVERRIDE+=	xrandr.pc.in

.include "../../wip/libX11/buildlink3.mk"
.include "../../x11/randrproto/buildlink3.mk"
.include "../../x11/renderproto/buildlink3.mk"
.include "../../wip/libXext/buildlink3.mk"
.include "../../x11/xextproto/buildlink3.mk"
.include "../../wip/libXrender/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
