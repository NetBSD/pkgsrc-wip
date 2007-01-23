# $NetBSD: Makefile,v 1.1 2007/01/23 08:44:10 bsadewitz Exp $
#

DISTNAME=	libdmx-1.0.2
CATEGORIES=	wip
MASTER_SITES=	http://xorg.freedesktop.org/releases/individual/proto/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	blair.sadewitz@gmail.com
HOMEPAGE=	http://xorg.freedesktop.org/releases/individual/proto/
COMMENT= 	Distributed, multi-headed X protocol headers from modular X.org	

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

PKGCONFIG_OVERRIDE+=	dmx.pc.in


.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/xextproto/buildlink3.mk"
.include "../../wip/dmxproto/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
