# $NetBSD: Makefile,v 1.16 2006/04/18 18:27:50 jeremy-c-reed Exp $
#

DISTNAME=		libXau-0.99.0
CATEGORIES=		x11 devel
MASTER_SITES=		http://xorg.freedesktop.org/X11R7.0-RC0/lib/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		reed@reedmedia.net
HOMEPAGE=		http://xorg.freedesktop.org/
COMMENT=		Authorization Protocol for X from X.org

#CONFLICTS+=		XFree86-libs-[0-9]*

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config

PKGCONFIG_OVERRIDE+=	xau.pc.in

.include "../../x11/xproto/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
