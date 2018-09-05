# $NetBSD$

BUILD_DIRS=	gb.sdl2
GB_DEPENDS=	gambas3-gb-image
.include "../../wip/gambas3/Makefile.common"

PKGNAME=	gambas3-gb-sdl2-${GB_VERSION}
MAINTAINER=	bastiangermann@fishpost.de
COMMENT=	SDL2 component interface for Gambas

.include "../../devel/SDL2/buildlink3.mk"
.include "../../fonts/SDL2_ttf/buildlink3.mk"
.include "../../graphics/SDL2_image/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
