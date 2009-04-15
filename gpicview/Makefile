# $NetBSD: Makefile,v 1.1.1.1 2009/04/15 01:21:43 zecrazytux Exp $

DISTNAME= gpicview-0.1.11
PKGREVISION=	1
CATEGORIES= graphics	
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=lxde/}

MAINTAINER= zecrazytux@zecrazytux.net
HOMEPAGE=	http://lxde.sourceforge.net/gpicview/
COMMENT= Lightweight image viewer

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config gmake
USE_DIRS+= xdg-1.4

.include "../../x11/gtk2/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
