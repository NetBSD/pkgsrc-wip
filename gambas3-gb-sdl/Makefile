# $NetBSD$

BUILD_DIRS=	gb.sdl
GB_DEPENDS=	gambas3-gb-image gambas3-gb-image-io
.include "../../wip/gambas3/Makefile.common"

PKGNAME=	gambas3-gb-sdl-${GB_VERSION}
MAINTAINER=	bastiangermann@fishpost.de
COMMENT=	SDL library interface for Gambas (deprecated)

.include "../../devel/SDL/buildlink3.mk"
.include "../../devel/SDL_ttf/buildlink3.mk"
.include "../../graphics/glew/buildlink3.mk"
.include "../../x11/libXcursor/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
