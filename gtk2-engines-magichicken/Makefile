# $NetBSD: Makefile,v 1.6 2004/08/17 18:27:33 tvierling Exp $

DISTNAME=		GTK2-mgicchikn-1.0.2
PKGNAME=		gtk2-engines-magichicken-1.0.2
WRKSRC=			${WRKDIR}/mgicchikn-1.0.2/
CATEGORIES=		x11
MASTER_SITES=		http://ftp.gnome.org/pub/GNOME/teams/art.gnome.org/themes/gtk2/

MAINTAINER=		dotz@irc.pl
HOMEPAGE=		http://art.gnome.org/
COMMENT=		MagicChicken theme engine for GTK+ 2.x

USE_BUILDLINK3=		YES
USE_LIBTOOL=		YES
LIBTOOL_LA_FILES+=	lib/gtk-2.0/2.4.0/engines/libmgicchikn.la
USE_GNU_TOOLS+=		make
GNU_CONFIGURE=		YES

.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
