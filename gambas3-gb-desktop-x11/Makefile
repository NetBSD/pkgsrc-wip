# $NetBSD$

BUILD_DIRS=	gb.desktop.x11
GB_DEPENDS=	gambas3-gb-image
.include "../../wip/gambas3/Makefile.common"

PKGNAME=	gambas3-gb-desktop-x11-${GB_VERSION}
MAINTAINER=	bastiangermann@fishpost.de
COMMENT=	X-Window library support for Gambas

.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXtst/buildlink3.mk"
.include "../../x11/xorgproto/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
