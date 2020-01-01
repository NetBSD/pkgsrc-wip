# $NetBSD: Makefile,v 1.1 2014/06/05 23:55:47 yrmt Exp $

DISTNAME=	herbstluftwm-0.7.2
CATEGORIES=	wm
MASTER_SITES=	http://herbstluftwm.org/tarballs/

MAINTAINER=	jake.slazenger@yandex.com
HOMEPAGE=	http://herbstluftwm.org/
COMMENT=	Manual tiling window manager for X11 using Xlib and Glib
LICENSE=	modified-bsd

USE_CMAKE=	yes
USE_TOOLS+=	gmake
USE_LANGUAGES+=	c c++
CONFIGURE_DIRS=	build
CMAKE_ARG_PATH=	..
CFLAGS.NetBSD+=	-D_NETBSD_SOURCE

pre-configure:
	${MKDIR} -p ${WRKSRC}/build

.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXinerama/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
