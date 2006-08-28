# $NetBSD: Makefile,v 1.1.1.1 2006/08/28 14:02:38 poppnk Exp $
#

DISTNAME=		ttr-0.11
CATEGORIES=		wip games
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=ttr/}

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://ttr.sourceforge.net/
COMMENT=		Text Text Revolution

GNU_CONFIGURE=		YES
USE_LANGUAGES=	c
ONLY_FOR_PLATFORM=	Linux-*-* # Because of linuxjoy.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/ttr ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/ttr/
	${INSTALL_DATA} ${WRKSRC}/steps/6jan.step ${PREFIX}/share/ttr/

.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
