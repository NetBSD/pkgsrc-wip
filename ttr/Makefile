# $NetBSD: Makefile,v 1.3 2012/10/07 17:08:30 asau Exp $
#

DISTNAME=		ttr-0.11
CATEGORIES=		games
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=ttr/}

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://ttr.sourceforge.net/
COMMENT=		Text Text Revolution

GNU_CONFIGURE=		YES
USE_LANGUAGES=		c
ONLY_FOR_PLATFORM=	Linux-*-* # Because of linuxjoy.c
INSTALLATION_DIRS+=	bin share/ttr

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/ttr ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/steps/6jan.step ${DESTDIR}${PREFIX}/share/ttr/

.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
