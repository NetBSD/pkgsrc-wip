# $NetBSD: Makefile,v 1.4 2004/05/09 07:30:47 blef Exp $

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
USE_GNU_TOOLS+=		make
GNU_CONFIGURE=		YES
CONFIGURE_ARGS=		--disable-gtktest

.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
