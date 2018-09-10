# $NetBSD$

BUILD_DIRS=	gb.gtk/src/opengl
GB_DEPENDS=	gambas3-gb-gtk gambas3-gb-opengl
.include "../../wip/gambas3/Makefile.common"

PKGNAME=	gambas3-gb-gtk-opengl-${GB_VERSION}
MAINTAINER=	bastiangermann@fishpost.de
COMMENT=	OpenGL library interface for Gambas

BUILDLINK_DEPMETHOD.cairo=	build
BUILDLINK_DEPMETHOD.librsvg=	build
BUILDLINK_DEPMETHOD.gtk2=	build
BUILDLINK_DEPMETHOD.libICE=	build
BUILDLINK_DEPMETHOD.libSM=	build

.include "../../graphics/cairo/buildlink3.mk"
.include "../../graphics/librsvg/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/libICE/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libXmu/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/gtkglext/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
