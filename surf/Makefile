# $NetBSD: Makefile,v 1.3 2012/10/07 16:23:18 asau Exp $
#

DISTNAME=	surf-0.3
PKGREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://dl.suckless.org/surf/

MAINTAINER=	pouya@san-serriffe.org
HOMEPAGE=	http://surf.suckless.org/
COMMENT=	Surf is a fast and minimalistic web browser based on WebKit/GTK+
LICENSE=	mit

USE_TOOLS+=		pkg-config

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/surf ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/surf.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../www/webkit-gtk/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
