# $NetBSD: Makefile,v 1.5 2003/09/27 23:36:45 shattered Exp $

DISTNAME=		toppler-1.0.2
CATEGORIES=		games
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=toppler/}

MAINTAINER=		snj@pobox.com
HOMEPAGE=		http://toppler.sourceforge.net/
COMMENT=		Tower climbing game

USE_BUILDLINK2=		yes
GNU_CONFIGURE=		yes

.include "../../devel/zlib/buildlink2.mk"
.include "../../audio/SDL_mixer/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
