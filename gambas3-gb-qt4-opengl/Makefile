# $NetBSD$

BUILD_DIRS=	gb.qt4/src/opengl
GB_DEPENDS=	gambas3-gb-qt4 gambas3-gb-opengl
.include "../../wip/gambas3/Makefile.common"

PKGNAME=	gambas3-gb-qt4-opengl-${GB_VERSION}
MAINTAINER=	bastiangermann@fishpost.de
COMMENT=	OpenGL for Gambas applications with Qt4

BUILDLINK_DEPMETHOD.qt4-qdbus=	build

.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../x11/qt4-libs/buildlink3.mk"
.include "../../x11/qt4-qdbus/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
