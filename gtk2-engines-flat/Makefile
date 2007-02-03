# $NetBSD: Makefile,v 1.12 2007/02/03 09:22:19 thomasklausner Exp $

DISTNAME=		GTK2-Flat-Engine
PKGNAME=		gtk2-engines-flat-2.0
WRKSRC=			${WRKDIR}/gtk-flat-theme-2.0
CATEGORIES=		x11
MASTER_SITES=		http://ftp.gnome.org/pub/GNOME/teams/art.gnome.org/themes/gtk2/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://art.gnome.org/
COMMENT=		Flat theme engine for GTK+ 2.x

USE_LIBTOOL=		YES
USE_DIRS+=		xdg-1.4
USE_TOOLS+=		gmake
GNU_CONFIGURE=		YES

.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
