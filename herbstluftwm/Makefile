# $NetBSD: Makefile,v 1.1 2014/06/05 23:55:47 yrmt Exp $

DISTNAME=	herbstluftwm-0.7.0
CATEGORIES=	wm
MASTER_SITES=	http://herbstluftwm.org/tarballs/

MAINTAINER=	jake.slazenger@yandex.com
HOMEPAGE=	http://herbstluftwm.org/
COMMENT=	Manual tiling window manager for X11 using Xlib and Glib
LICENSE=	modified-bsd

USE_TOOLS+=	gmake
USE_LANGUAGES+=	c c++
MAKEFLAGS+=	PREFIX=${PREFIX}
MAKEFLAGS+=	SYSCONFDIR=${PREFIX}/share
MAKEFLAGS+=	MANDIR=${PREFIX}/${PKGMANDIR}

CFLAGS.NetBSD+= -D_NETBSD_SOURCE
CFLAGS+= -I${PREFIX}/include/glib/glib-2.0
CFLAGS+= -I${PREFIX}/lib/glib-2.0/include
CFLAGS+= ${X11_LDFLAGS}
CFLAGS+= -L${PREFIX}/lib -lglib-2.0 -R${PREFIX}/lib
LDFLAGS+= -lglib-2.0 -L${PREFIX}/lib -R${PREFIX}/lib

.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXinerama/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
