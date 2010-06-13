# $NetBSD: Makefile,v 1.5 2010/06/13 22:47:11 thomasklausner Exp $

DISTNAME=		lxrandr-0.1.1
PKGREVISION=		1
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=lxde/}

MAINTAINER=		zecrazytux@zecrazytux.net
HOMEPAGE=		http://lxde.org/
COMMENT=		Simple graphical front end to the xrandr extension

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_TOOLS+=		pkg-config gmake

.include "../../x11/gtk2/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
