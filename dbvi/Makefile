# $NetBSD: Makefile,v 1.1.1.1 2006/06/01 12:48:22 lkundrak Exp $

DISTNAME=		dbvi-0.9.4.1.1
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=dbvi/}


MAINTAINER=		lkundrak@skosi.org
HOMEPAGE=		http://dbvi.sourceforge.net/
COMMENT=		GDB frontend which provides full screen interface with vi

USE_NCURSES=		yes	# uses term.h
BUILD_TARGET=		dbvi

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
