# $NetBSD: Makefile,v 1.13 2007/02/03 09:22:19 thomasklausner Exp $

DISTNAME=		dwerg-default-${DWERG_VERSION}
DWERG_VERSION=		0.8
PKGNAME=		gtk2-engines-dwerg-${DWERG_VERSION}
CATEGORIES=		x11
MASTER_SITES=		http://download.freshmeat.net/themes/dwerg/
EXTRACT_SUFX=		.tar.gz
WRKSRC=	${WRKDIR}/gtk-engines-dwerg-${DWERG_VERSION}/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://themes.freshmeat.net/projects/dwerg/
COMMENT=		Theme engine for GTK+ 2.x

USE_LIBTOOL=		YES
USE_DIRS+=		xdg-1.4
USE_TOOLS+=		gmake
GNU_CONFIGURE=		YES

.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
