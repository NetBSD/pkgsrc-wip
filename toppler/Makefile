# $NetBSD: Makefile,v 1.7 2004/03/07 05:39:32 blef Exp $

DISTNAME=		toppler-1.0.6
CATEGORIES=		games
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=toppler/}

MAINTAINER=		snj@NetBSD.org
HOMEPAGE=		http://toppler.sourceforge.net/
COMMENT=		Tower climbing game

USE_BUILDLINK3=		YES
GNU_CONFIGURE=		YES

.include "../../devel/zlib/buildlink3.mk"
.include "../../audio/SDL_mixer/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
