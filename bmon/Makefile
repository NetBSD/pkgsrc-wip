# $NetBSD: Makefile,v 1.1.1.1 2004/07/14 16:55:48 hsaliak Exp $

DISTNAME=	bmon-1.2.1
CATEGORIES=	wip
MASTER_SITES=	http://trash.net/~reeler/bmon/files/

MAINTAINER=	hsaliak@gmail.com
HOMEPAGE=	http://trash.net/~reeler/bmon/files/
COMMENT=	Bmon is an interface bandwidth monitor

GNU_CONFIGURE=	yes
USE_GNU_TOOLS+=	make
USE_BUILDLINK3=	yes

.include "../../mk/bsd.prefs.mk"

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bmon ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/bmon.1 ${PREFIX}/man/man1
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/bmon
	${INSTALL_DATA} ${WRKSRC}/bmonrc ${PREFIX}/share/examples/bmon/bmonrc

.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
