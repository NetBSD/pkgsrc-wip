# $NetBSD: Makefile,v 1.5 2004/05/09 07:28:48 blef Exp $

DISTNAME=		GTK2-Industrial
PKGNAME=		gtk2-engines-industrial-0
WRKSRC=			${WRKDIR}/GTK2-Industrial-Engine
CATEGORIES=		x11
MASTER_SITES=		http://ftp.gnome.org/pub/GNOME/teams/art.gnome.org/themes/gtk2/

MAINTAINER=		dotz@irc.pl
HOMEPAGE=		http://art.gnome.org/
COMMENT=		Black and white theme for GTK+ 2.x

USE_BUILDLINK3=		YES
USE_LIBTOOL=		YES
USE_GNU_TOOLS+=		make
GNU_CONFIGURE=		YES
CONFIGURE_ARGS=		--prefix=${PREFIX}

.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
