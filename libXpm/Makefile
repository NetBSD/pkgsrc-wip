# $NetBSD: Makefile,v 1.3 2006/04/18 18:27:51 jeremy-c-reed Exp $
#

DISTNAME=		libXpm-3.5.4.2
CATEGORIES=		graphics x11
MASTER_SITES=		http://xorg.freedesktop.org/releases/individual/lib/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		reed@reedmedia.net
HOMEPAGE=		http://xorg.freedesktop.org/
COMMENT=		X PixMap Library from modular Xorg X11

CONFLICTS+=		xpm-[0-9]*

# This does not include the sxpm tool for displaying XPM images.

USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config
PKGCONFIG_OVERRIDE+=	${WRKSRC}/xpm.pc.in
GNU_CONFIGURE=		yes
CONFIGURE_ENV+=		APP_MAN_SUFFIX=1

.include "../../x11/xproto/buildlink3.mk"
.include "../../wip/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
