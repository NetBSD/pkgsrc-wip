# $NetBSD: Makefile,v 1.5 2004/08/17 18:27:15 tvierling Exp $

DISTNAME=		gtk-engines-dwerg-0.6
PKGNAME=		${DISTNAME:S/gtk/gtk2/}
CATEGORIES=		x11
MASTER_SITES=		http://ftp.gnome.org/pub/GNOME/teams/art.gnome.org/themes/gtk2/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		dotz@irc.pl
HOMEPAGE=		http://art.gnome.org/
COMMENT=		Theme engine for GTK+ 2.x

USE_BUILDLINK3=		YES
USE_LIBTOOL=		YES
LIBTOOL_LA_FILES+=	lib/gtk-2.0/2.4.0/engines/libdwerg.la
USE_GNU_TOOLS+=		make
GNU_CONFIGURE=		YES

.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
