# $NetBSD: Makefile,v 1.3 2003/08/23 00:42:14 blef Exp $

DISTNAME=		toppler-1.0.2
CATEGORIES=		games
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=toppler/}

MAINTAINER=		soren@blef.org
HOMEPAGE=		http://topple.sf.net/
COMMENT=		Tower climbing game

USE_BUILDLINK2=		yes
GNU_CONFIGURE=		yes

.include "../../devel/zlib/buildlink2.mk"
.include "../../audio/SDL_mixer/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
