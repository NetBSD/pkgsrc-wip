# $NetBSD$

DISTNAME=	warsow_21_sdk
PKGNAME=	warsow-2.1.2
CATEGORIES=	games
MASTER_SITES=	http://sebastian.network/warsow/

MAINTAINER=	cfkoch@edgebsd.org
HOMEPAGE=	https://warsow.net
COMMENT=	Free fast-paced first-person shooter
LICENSE=	gnu-gpl-v2

WRKSRC=		${WRKDIR}/${DISTNAME}/source/source
USE_CMAKE=	yes
USE_LANGUAGES=	c c++

CMAKE_ARGS+=	-DUSE_SDL:BOOL=ON

.include "../../audio/libvorbis/buildlink3.mk"
.include "../../devel/SDL2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../multimedia/libogg/buildlink3.mk"
.include "../../multimedia/libtheora/buildlink3.mk"
.include "../../wip/angelscript/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
