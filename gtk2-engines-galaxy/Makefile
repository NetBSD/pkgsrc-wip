# $NetBSD: Makefile,v 1.2 2003/11/27 03:02:57 mpasternak Exp $

DISTNAME=		GTK2-Galaxy
PKGNAME=		gtk2-engines-galaxy-0
WRKSRC=			${WRKDIR}/galaxy-0.2
CATEGORIES=		x11
MASTER_SITES=		http://ftp.gnome.org/pub/GNOME/teams/art.gnome.org/themes/gtk2/

MAINTAINER=		dotz@irc.pl
HOMEPAGE=		http://art.gnome.org/
COMMENT=		Theme engine for GTK+ 2.x

USE_BUILDLINK2=		YES
USE_LIBTOOL=		YES
USE_GMAKE=		YES
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
GNU_CONFIGURE=		YES
CONFIGURE_ARGS=		--disable-gtktest  --disable-gdk_pixbuftest

.include "../../x11/gtk2/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
