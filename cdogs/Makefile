# $NetBSD: Makefile,v 1.1.1.1 2006/08/17 13:49:26 dhowland Exp $
#

DISTNAME=		cdogs-sdl-0.3
PKGNAME=		cdogs-0.3
CATEGORIES=		games
MASTER_SITES=		http://offload1.icculus.org/cdogs-sdl/files/
EXTRACT_SUFX=		.tar.bz2
DISTFILES=		cdogs-sdl-current.tar.bz2 \
			cdogs-data-current.tar.bz2

MAINTAINER=		dhowland@users.sourceforge.net
HOMEPAGE=		http://members.optusnet.com.au/~lmartinking/hacks/cdogs/
COMMENT=		SDL port of the classic DOS arcade game

WRKSRC=			${WRKDIR}/${DISTNAME}/src

BUILD_TARGET=		cdogs
USE_TOOLS+=		gmake

post-extract:
	${MV} ${WRKDIR}/cdogs-data-2006-08-16 ${WRKDIR}/${DISTNAME}/data

.include "../../audio/SDL_mixer/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
