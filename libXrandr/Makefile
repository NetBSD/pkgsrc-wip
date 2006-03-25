# $NetBSD: Makefile,v 1.3 2006/03/25 01:40:20 jeremy-c-reed Exp $
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
.include "../../wip/randrproto/buildlink3.mk"
.include "../../wip/renderproto/buildlink3.mk"
.include "../../wip/libXext/buildlink3.mk"
.include "../../wip/xextproto/buildlink3.mk"
.include "../../wip/libXrender/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
