# $NetBSD: Makefile,v 1.3 2005/11/02 18:00:24 thomasklausner Exp $
#

DISTNAME=		ninvaders-0.1.1
CATEGORIES=		games
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=ninvaders/}

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://ninvaders.sourceforge.net/
COMMENT=		ncurses based invaders game

WRKSRC=		${WRKDIR}/*

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/nInvaders ${PREFIX}/bin/

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
