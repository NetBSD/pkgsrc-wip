# $NetBSD$
#

DISTNAME=	freesynd-0.7.5
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=freesynd/freesynd/freesynd-0.7.5/}

MAINTAINER=	pkgsrc-users@etBSD.org
HOMEPAGE=	http://freesynd.sourceforge.net/
COMMENT=	GPLed reimplementation of the engine for the game Syndicate
LICENSE=	gnu-gpl-v2

#HAS_CONFIGURE=	yes
USE_CMAKE=	yes
USE_LANGUAGES=	c c++

CMAKE_ARGS+=	-DCMAKE_BUILD_TYPE=release
CMAKE_ARGS+=	-DSDLIMAGE_INCLUDE_DIR=${BUILDLINK_PREFIX.SDL_image}/include
CMAKE_ARGS+=	-DSDLMIXER_INCLUDE_DIR=${BUILDLINK_PREFIX.SDL_mixer}/include

.include "../../audio/SDL_mixer/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../graphics/SDL_image/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
