# $NetBSD: Makefile,v 1.6 2003/11/05 05:29:37 blef Exp $

DISTNAME=		toppler-1.0.3
CATEGORIES=		games
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=toppler/}

MAINTAINER=		snj@pobox.com
HOMEPAGE=		http://toppler.sourceforge.net/
COMMENT=		Tower climbing game

USE_BUILDLINK2=		YES
GNU_CONFIGURE=		YES

.include "../../devel/zlib/buildlink2.mk"
.include "../../audio/SDL_mixer/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
