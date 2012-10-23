# $NetBSD: Makefile,v 1.7 2012/10/23 10:23:06 thomasklausner Exp $
#

DISTNAME=	libdmx-1.1.2
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_XORG:=lib/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	blair.sadewitz@gmail.com
HOMEPAGE=	http://xorg.freedesktop.org/releases/individual/proto/
COMMENT=	Distributed, multi-headed X protocol headers from modular X.org

PKG_INSTALLATION_TYPES=	overwrite pkgviews

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

PKGCONFIG_OVERRIDE+=	dmx.pc.in


.include "../../x11/libXext/buildlink3.mk"
.include "../../wip/dmxproto/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
