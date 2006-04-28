# $NetBSD: Makefile,v 1.17 2006/04/28 06:49:17 jeremy-c-reed Exp $
#

DISTNAME=		libXau-1.0.0
CATEGORIES=		x11 devel
MASTER_SITES=		http://xorg.freedesktop.org/releases/individual/lib/
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
