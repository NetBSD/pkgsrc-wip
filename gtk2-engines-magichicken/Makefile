# $NetBSD: Makefile,v 1.13 2007/06/04 09:02:54 ekamperi Exp $

PKGNAME=		gtk2-engines-magicchicken
DISTNAME=		gtk2-engines-magicchicken_1.1.1.orig
WRKSRC=                 ${WRKDIR}/gtk2-engines-magicchicken-1.1.1.orig
CATEGORIES=		x11
MASTER_SITES=		ftp://ftp.debian.org/debian/pool/main/g/gtk2-engines-magicchicken/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://art.gnome.org/
COMMENT=		MagicChicken theme engine for GTK+ 2.x

USE_LIBTOOL=		YES
USE_DIRS+=		xdg-1.4
USE_TOOLS+=		gmake
GNU_CONFIGURE=		YES

.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
