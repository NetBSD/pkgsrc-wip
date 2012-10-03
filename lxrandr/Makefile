# $NetBSD: Makefile,v 1.7 2012/10/03 09:10:45 asau Exp $

DISTNAME=		lxrandr-0.1.2
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=lxde/}

MAINTAINER=		zecrazytux@zecrazytux.net
HOMEPAGE=		http://lxde.org/
COMMENT=		Simple graphical front end to the xrandr extension

GNU_CONFIGURE=	yes
USE_TOOLS+=		gmake intltool pkg-config

.include "../../x11/gtk2/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
