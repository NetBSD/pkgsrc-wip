# $NetBSD: Makefile,v 1.5 2010/06/13 22:47:05 thomasklausner Exp $

DISTNAME=				gpicview-0.1.11
PKGREVISION=		3
CATEGORIES=			graphics
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=lxde/}

MAINTAINER=			zecrazytux@zecrazytux.net
HOMEPAGE=				http://lxde.sourceforge.net/gpicview/
COMMENT=				Lightweight image viewer

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_TOOLS+=			pkg-config gmake

.include "../../x11/gtk2/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
