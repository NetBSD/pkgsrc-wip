# $NetBSD: Makefile,v 1.5 2012/09/24 18:26:52 asau Exp $
#

DISTNAME=		cdogs-sdl-0.4
PKGNAME=		cdogs-0.4
CATEGORIES=		games
MASTER_SITES=		http://offload1.icculus.org/cdogs-sdl/files/
EXTRACT_SUFX=		.tar.bz2
DISTFILES=		cdogs-sdl-current.tar.bz2 \
			cdogs-data-current.tar.bz2

MAINTAINER=		dhowland@users.sourceforge.net
HOMEPAGE=		http://lumaki.com/code/cdogs/
COMMENT=		SDL port of the classic DOS arcade game
LICENSE=		gnu-gpl-v2

WRKSRC=			${WRKDIR}/${DISTNAME}/src

BUILD_TARGET=		cdogs
USE_TOOLS+=		gmake

post-extract:
	mv ${WRKDIR}/cdogs-data-2007-07-06 ${WRKDIR}/${DISTNAME}/data

.include "../../audio/SDL_mixer/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
