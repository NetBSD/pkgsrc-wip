# $NetBSD$

BUILD_DIRS=	gb.opengl/src/sge
GB_DEPENDS=	gambas3-gb-opengl
.include "../../wip/gambas3/Makefile.common"

PKGNAME=	gambas3-gb-opengl-sge-${GB_VERSION}
MAINTAINER=	bastiangermann@fishpost.de
COMMENT=	Simple OpenGL game engine for Gambas based on MD2 format

.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/glew/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
