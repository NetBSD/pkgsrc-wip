# $NetBSD: Makefile,v 1.5 2012/10/07 14:53:43 asau Exp $
#

DISTNAME=		RealTimeBattle-1.0.7-Std
PKGNAME=		realtimebattle-1.0.7
PKGREVISION=		1
CATEGORIES=		games
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=realtimebattle/}

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://realtimebattle.sourceforge.net/
COMMENT=		Programming robots game

PKG_DESTDIR_SUPPORT=	none

USE_LANGUAGES=		c c++
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
