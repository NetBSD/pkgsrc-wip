# $NetBSD: Makefile,v 1.16 2006/04/18 18:27:50 jeremy-c-reed Exp $
#

DISTNAME=		libXext-0.99.0
CATEGORIES=		x11 devel
MASTER_SITES=		http://xorg.freedesktop.org/X11R7.0-RC0/lib/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://xorg.freedesktop.org/
COMMENT=		X Extension library

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config

PKGCONFIG_OVERRIDE+=	xext.pc.in

.include "../../wip/libX11/buildlink3.mk"
.include "../../wip/libXau/buildlink3.mk"  ## configure didn't check for this
.include "../../x11/xextproto/buildlink3.mk"
.include "../../x11/xproto/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
