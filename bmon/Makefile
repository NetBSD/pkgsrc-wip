# $NetBSD: Makefile,v 1.4 2004/08/05 03:32:19 minskim Exp $

DISTNAME=	bmon-1.2.1
CATEGORIES=	wip net
MASTER_SITES=	http://trash.net/~reeler/bmon/files/

MAINTAINER=	hsaliak@gmail.com
HOMEPAGE=	http://trash.net/~reeler/bmon/
COMMENT=	Bmon is an interface bandwidth monitor

PKG_INSTALLATION_TYPES=	overwrite pkgviews

GNU_CONFIGURE=	yes
USE_BUILDLINK3=	yes
USE_GNU_TOOLS+=	make

INSTALLATION_DIRS= bin man/man1
do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bmon ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/bmon.1 ${PREFIX}/man/man1
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/bmon
	${INSTALL_DATA} ${WRKSRC}/bmonrc ${PREFIX}/share/examples/bmon/bmonrc

.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
