# $NetBSD: Makefile,v 1.5 2004/02/17 02:55:43 blef Exp $

DISTNAME=		GTK2-Smooth-Engine
PKGNAME=		gtk2-engines-smooth-0
WRKSRC=			${WRKDIR}/smooth-engine
CATEGORIES=		x11
MASTER_SITES=		http://ftp.gnome.org/pub/GNOME/teams/art.gnome.org/themes/gtk2/

MAINTAINER=		dotz@irc.pl
HOMEPAGE=		http://art.gnome.org/
COMMENT=		Smooth theme engine for GTK+ 2.x

USE_BUILDLINK2=		YES
USE_LIBTOOL=		YES
USE_GNU_TOOLS+=		make
GNU_CONFIGURE=		YES

.include "../../x11/gtk2/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
