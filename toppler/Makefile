# $NetBSD: Makefile,v 1.4 2003/08/28 04:46:44 blef Exp $

DISTNAME=		toppler-1.0.2
CATEGORIES=		games
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=toppler/}

MAINTAINER=		snj@pobox.com
HOMEPAGE=		http://topple.sf.net/
COMMENT=		Tower climbing game

USE_BUILDLINK2=		yes
GNU_CONFIGURE=		yes

.include "../../devel/zlib/buildlink2.mk"
.include "../../audio/SDL_mixer/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
