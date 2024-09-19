# $NetBSD: Makefile,v 1.2 2012/09/29 00:50:37 asau Exp $
#

DISTNAME=	gnome-paint-0.3
CATEGORIES=	graphics gnome
MASTER_SITES=	http://gnome-paint.googlecode.com/files/

MAINTAINER=	pkgsrc.gnome@gmail.com
HOMEPAGE=	http://code.google.com/p/gnome-paint/
COMMENT=	Simple, easy to use paint program for GNOME
LICENSE=	gnu-gpl-v3

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config intltool gmake

.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
