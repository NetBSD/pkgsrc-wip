# $NetBSD: Makefile,v 1.2 2012/10/07 20:11:09 asau Exp $
#

DISTNAME=	xf86-input-synaptics-1.2.1
CATEGORIES=	x11
MASTER_SITES=	http://xorg.freedesktop.org/archive/individual/driver/

MAINTAINER=	rga@sdf.lonestar.org
HOMEPAGE=	http://xorg.freedesktop.org/
COMMENT=	Synaptics touchpad driver for X.Org
LICENSE=	mit

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

PKGCONFIG_OVERRIDE+=	xorg-synaptics.pc.in

ONLY_FOR_PLATFORM=	Linux-*-*

post-install:
	${INSTALL_DATA} ${WRKSRC}/fdi/11-x11-synaptics.fdi \
	${PREFIX}/share/hal/fdi/policy/10osvendor/


.include "../../x11/modular-xorg-server/buildlink3.mk"
.include "../../x11/libXtst/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
