# $NetBSD: Makefile,v 1.12 2006/09/27 19:41:59 rillig Exp $

DISTNAME=		toppler-1.1.2a
PKGNAME=		toppler-1.1.2
#PKGREVISION=		1
CATEGORIES=		games
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=toppler/}

MAINTAINER=		snj@NetBSD.org
HOMEPAGE=		http://toppler.sourceforge.net/
COMMENT=		Tower climbing game

GNU_CONFIGURE=		YES
USE_LANGUAGES=		c c++

WRKSRC=			${WRKDIR}/toppler-1.1.2
LIBS+=			${BUILDLINK_LDADD.gettext}

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../audio/SDL_mixer/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
