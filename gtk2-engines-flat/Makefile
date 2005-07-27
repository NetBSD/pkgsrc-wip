# $NetBSD: Makefile,v 1.10 2005/07/27 16:25:34 thomasklausner Exp $

DISTNAME=		GTK2-Flat-Engine
PKGNAME=		gtk2-engines-flat-2.0
WRKSRC=			${WRKDIR}/gtk-flat-theme-2.0
CATEGORIES=		x11
MASTER_SITES=		http://ftp.gnome.org/pub/GNOME/teams/art.gnome.org/themes/gtk2/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://art.gnome.org/
COMMENT=		Flat theme engine for GTK+ 2.x

USE_LIBTOOL=		YES
USE_TOOLS+=		gmake
GNU_CONFIGURE=		YES

.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
