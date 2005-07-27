# $NetBSD: Makefile,v 1.10 2005/07/27 16:25:46 thomasklausner Exp $

DISTNAME=		GTK2-mgicchikn-1.0.2
PKGNAME=		gtk2-engines-magichicken-1.0.2
WRKSRC=			${WRKDIR}/mgicchikn-1.0.2/
CATEGORIES=		x11
MASTER_SITES=		http://ftp.gnome.org/pub/GNOME/teams/art.gnome.org/themes/gtk2/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://art.gnome.org/
COMMENT=		MagicChicken theme engine for GTK+ 2.x

USE_LIBTOOL=		YES
USE_TOOLS+=		gmake
GNU_CONFIGURE=		YES

.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
