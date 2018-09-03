# $NetBSD$

BUILD_DIRS=	gb.v4l
.include "../../wip/gambas3/Makefile.common"

PKGNAME=		gambas3-gb-v4l-${GB_VERSION}
MAINTAINER=		bastiangermann@fishpost.de
COMMENT=		Video capture for Gambas (deprecated)
ONLY_FOR_PLATFORM=	Linux-*-*

.include "../../graphics/libv4l/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
