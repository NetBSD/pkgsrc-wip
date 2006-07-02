# $NetBSD: Makefile,v 1.10 2006/07/02 00:58:18 rillig Exp $

DISTNAME=		toppler-1.0.6
PKGREVISION=		1
CATEGORIES=		games
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=toppler/}

MAINTAINER=		snj@NetBSD.org
HOMEPAGE=		http://toppler.sourceforge.net/
COMMENT=		Tower climbing game

GNU_CONFIGURE=		YES
USE_LANGUAGES=		c c++

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../audio/SDL_mixer/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
