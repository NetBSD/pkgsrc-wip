# $NetBSD: Makefile,v 1.5 2004/08/17 18:27:27 tvierling Exp $

DISTNAME=		GTK2-LighthouseBlue-0.4
PKGNAME=		gtk2-engines-lighthouseblue-0.4
WRKSRC=			${WRKDIR}/lighthouseblue
CATEGORIES=		x11
MASTER_SITES=		http://ftp.gnome.org/pub/GNOME/teams/art.gnome.org/themes/gtk2/

MAINTAINER=		dotz@irc.pl
HOMEPAGE=		http://art.gnome.org/
COMMENT=		Theme engine for GTK+ 2.x

USE_BUILDLINK3=		YES
USE_LIBTOOL=		YES
LIBTOOL_LA_FILES+=	lib/gtk-2.0/2.4.0/engines/liblighthouseblue.la
USE_GNU_TOOLS+=		make
GNU_CONFIGURE=		YES
CONFIGURE_ARGS=		--disable-gtktest

.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
