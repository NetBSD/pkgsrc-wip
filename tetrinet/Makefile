# $NetBSD: Makefile,v 1.3 2007/02/04 19:31:42 minskim Exp $

DISTNAME=	tetrinet-0.11
CATEGORIES=	games
MASTER_SITES=	http://tetrinet.or.cz/download/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	david@netbsd-fr.org
HOMEPAGE=	${MASTER_SITES}
COMMENT=	Console tetrinet client

BUILDLINK_TRANSFORM+=	l:ncurses:curses

INSTALLATION_DIRS=	bin share/tetrinet/doc

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tetrinet ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/tetrinet-server ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/tetrinet/doc
	${INSTALL_DATA} ${WRKSRC}/tetrinet.txt ${PREFIX}/share/tetrinet/doc

.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
