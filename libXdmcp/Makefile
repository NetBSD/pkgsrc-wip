# $NetBSD: Makefile,v 1.6 2007/01/22 09:37:55 bsadewitz Exp $
#

DISTNAME=	libXdmcp-1.0.2
CATEGORIES=	x11
MASTER_SITES=	http://xorg.freedesktop.org/releases/individual/lib/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	blair.sadewitz@gmail.com
HOMEPAGE=	http://xorg.freedesktop.org/releases/individual/lib/
COMMENT=	X Display Management Control Protocol from modular X.org

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

PKGCONFIG_OVERRIDE+=	xdmcp.pc.in

.include "../../x11/xproto/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
