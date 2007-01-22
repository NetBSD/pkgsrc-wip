# $NetBSD: Makefile,v 1.23 2007/01/22 10:06:23 bsadewitz Exp $
#

DISTNAME=	libICE-1.0.3
CATEGORIES=	x11
MASTER_SITES=	http://xorg.freedesktop.org/releases/individual/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	blair.sadewitz@gmail.com
HOMEPAGE=	http://xorg.freedesktop.org/releases/individual/
COMMENT=	Inter-client exchange (ICE) library for modular X.org

PKG_INSTALLATION_TYPES= overwrite pkgviews
PKG_DESTDIR_SUPPORT=    user-destdir

CPPFLAGS+=	-D_NETBSD_SOURCE

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

PKGCONFIG_OVERRIDE+=	ice.pc.in

.include "../../x11/xproto/buildlink3.mk"
.include "../../x11/xtrans/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
