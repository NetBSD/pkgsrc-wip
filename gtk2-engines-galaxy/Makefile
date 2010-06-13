# $NetBSD: Makefile,v 1.15 2010/06/13 22:47:06 thomasklausner Exp $

DISTNAME=		GTK2-Galaxy
PKGNAME=		gtk2-engines-galaxy-0
WRKSRC=			${WRKDIR}/galaxy-0.2
PKGREVISION=		1
CATEGORIES=		x11
MASTER_SITES=		http://ftp.gnome.org/pub/GNOME/teams/art.gnome.org/themes/gtk2/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://art.gnome.org/
COMMENT=		Another theme engine for GTK+ 2.x

USE_LIBTOOL=		YES
USE_TOOLS+=		gmake
GNU_CONFIGURE=		YES
CONFIGURE_ARGS=		--disable-gtktest  --disable-gdk_pixbuftest

.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
