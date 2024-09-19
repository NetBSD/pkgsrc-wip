# $NetBSD$

VERSION=	0.1.11
DISTNAME=	${GITHUB_TAG}
PKGNAME=	colobot-${VERSION}
MASTER_SITES=	${MASTER_SITE_GITHUB:=colobot/}
GITHUB_PROJECT=	colobot
GITHUB_TAG=	colobot-gold-${VERSION}-alpha
CATEGORIES=	games

MAINTANER=	charlotte@NetBSD.org
HOMEPAGE=	https://colobot.info/
COMMENT=	Real-time strategy game
LICENSE=	gnu-gpl-v3

EXTRACT_USING=	gtar
USE_CMAKE=	yes
USE_LANGUAGES+=	c c++

.include "../../audio/flac/buildlink3.mk"
.include "../../audio/libsndfile/buildlink3.mk"
.include "../../audio/openal-soft/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/physfs/buildlink3.mk"
.include "../../devel/SDL2/buildlink3.mk"
.include "../../fonts/SDL2_ttf/buildlink3.mk"
.include "../../graphics/glew/buildlink3.mk"
.include "../../graphics/librsvg/buildlink3.mk"
.include "../../graphics/SDL2_image/buildlink3.mk"
.include "../../multimedia/libogg/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
