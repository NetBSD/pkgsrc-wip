# $NetBSD$

BUILD_DIRS=	gb.sdl2/src/audio
.include "../../wip/gambas3/Makefile.common"

PKGNAME=	gambas3-gb-sdl2-audio-${GB_VERSION}
MAINTAINER=	bastiangermann@fishpost.de
COMMENT=	SDL2 audio component interface for Gambas

BUILDLINK_DEPMETHOD.SDL2_ttf=	build
BUILDLINK_DEPMETHOD.SDL2_image=	build

.include "../../devel/SDL2/buildlink3.mk"
.include "../../fonts/SDL2_ttf/buildlink3.mk"
.include "../../graphics/SDL2_image/buildlink3.mk"
.include "../../audio/SDL2_mixer/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
