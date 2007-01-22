# $NetBSD: Makefile,v 1.20 2007/01/22 10:08:38 bsadewitz Exp $
#

DISTNAME=	libSM-1.0.2
CATEGORIES=	x11
MASTER_SITES=	http://xorg.freedesktop.org/releases/individual/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	blair.sadewitz@gmail.com
HOMEPAGE=	http://xorg.freedesktop.org/releases/individual/
COMMENT=	Session Management library from modular X.org

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

PKGCONFIG_OVERRIDE+=	sm.pc.in

CPPFLAGS+=	-D_NETBSD_SOURCE

.include "../../wip/libICE/buildlink3.mk"
.include "../../x11/xproto/buildlink3.mk"
.include "../../x11/xtrans/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
