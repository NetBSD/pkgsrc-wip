# $NetBSD: Makefile,v 1.1 2014/06/05 23:55:47 yrmt Exp $

DISTNAME=	herbstluftwm-0.6.2
CATEGORIES=	wm
MASTER_SITES=	http://herbstluftwm.org/tarballs/

MAINTAINER=	youri.mout@gmail.com
HOMEPAGE=	http://herbstluftwm.org/
COMMENT=	Manual tiling window manager for X11 using Xlib and Glib
LICENSE=	modified-bsd

USE_TOOLS+=	gmake
MAKEFLAGS+=	PREFIX=${PREFIX} SYSCONFDIR=${PREFIX}/share MANDIR=${PREFIX}/${PKGMANDIR}

.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXinerama/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
