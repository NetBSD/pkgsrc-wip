# $NetBSD: Makefile,v 1.5 2013/04/16 13:43:59 thomasklausner Exp $
#

DISTNAME=	gbase-0.5
PKGREVISION=	2
CATEGORIES=	math
MASTER_SITES=	http://www.fluxcode.net/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.fluxcode.net/
COMMENT=	GTK program designed to convert between the four common bases
LICENSE=	artistic

USE_TOOLS+=	pkg-config

INSTALLATION_DIRS+=	bin

BUILD_TARGET=	gbase

do-install:
		${INSTALL_PROGRAM} ${WRKSRC}/gbase ${DESTDIR}${PREFIX}/bin/gbase

.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
