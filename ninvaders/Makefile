# $NetBSD: Makefile,v 1.1.1.1 2004/06/01 20:53:28 poppnk Exp $
#

DISTNAME=		ninvaders-0.1.1
CATEGORIES=		wip games
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=ninvaders/}

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://ninvaders.sourceforge.net/
COMMENT=		ncurses based invaders game

WRKSRC=		${WRKDIR}/*
USE_BUILDLINK3=		yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/nInvaders ${PREFIX}/bin/

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
