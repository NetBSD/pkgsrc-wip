# $NetBSD: Makefile,v 1.4 2012/10/07 16:42:54 asau Exp $

DISTNAME=	tetrinet-0.11
CATEGORIES=	games
MASTER_SITES=	http://tetrinet.or.cz/download/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	david@netbsd-fr.org
HOMEPAGE=	http://tetrinet.or.cz/download/
COMMENT=	Console tetrinet client

BUILDLINK_TRANSFORM+=	l:ncurses:curses

INSTALLATION_DIRS=	bin share/tetrinet/doc

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tetrinet ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/tetrinet-server ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/tetrinet/doc
	${INSTALL_DATA} ${WRKSRC}/tetrinet.txt ${DESTDIR}${PREFIX}/share/tetrinet/doc

.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
