# $NetBSD: Makefile,v 1.2 2006/11/11 13:26:33 shattered Exp $
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
INSTALLATION_DIRS+=	share/ttr

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/ttr ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/steps/6jan.step ${PREFIX}/share/ttr/

.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
