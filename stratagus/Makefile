# $NetBSD$

DISTNAME=	stratagus-2.4.2
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GITHUB:=Wargus/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	charlotte@NetBSD.org
HOMEPAGE=	https://github.com/Wargus/stratagus
COMMENT=	Real-time strategy gaming engine
LICENSE=	gnu-gpl-v2

EXTRACT_USING=	gtar
USE_CMAKE=	yes
USE_LANGUAGES=	c c++

TOOL_DEPENDS+=	tolua++-[0-9]*:../../wip/tolua++

CMAKE_CONFIGURE_ARGS+=	-DENABLE_DEV=ON
CMAKE_CONFIGURE_ARGS+=	-DWANT_METASERVER=OFF
CMAKE_CONFIGURE_ARGS+=	-DWITH_RENDERER=NativeSDL

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../audio/fluidsynth/buildlink3.mk"
.include "../../audio/libmikmod/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../graphics/mng/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../lang/lua51/buildlink3.mk"
.include "../../multimedia/libtheora/buildlink3.mk"
.include "../../wip/tolua++/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
