# $NetBSD$

BUILD_DIRS=	gb.opengl
GB_DEPENDS=	gambas3-gb-image
.include "../../wip/gambas3/Makefile.common"

PKGNAME=	gambas3-gb-opengl-${GB_VERSION}
MAINTAINER=	bastiangermann@fishpost.de
COMMENT=	OpenGL library interface for Gambas

.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/glew/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
