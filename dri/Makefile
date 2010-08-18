# $NetBSD: Makefile,v 1.2 2010/08/18 10:28:25 pallegra Exp $
#

.include "../../wip/gl/Makefile.common"

PKGNAME=	${COMPONENT}-${MESA_PKGVERSION}
CATEGORIES=	graphics
EXTRACT_SUFX=	.tar.bz2

COMPONENT=	dri

MAINTAINER=	pallegra@gmail.com
HOMEPAGE=	http://www.mesa3d.org/
COMMENT=	OpenGL hardware acceleration drivers for the DRI
#LICENSE=	mit # ???

CONFLICTS=	MesaLib<=7.6

PKGCONFIG_OVERRIDE+=	src/mesa/drivers/dri/dri.pc.in

CONFIGURE_ARGS+=	--disable-glu
CONFIGURE_ARGS+=	--disable-glut
CONFIGURE_ARGS+=	--disable-glw

BUILD_DIRS=	src/glsl src/mesa
BUILD_TARGET=	default

INSTALL_DIRS=	src/mesa
INSTALL_TARGET=	install-dri

.include "../../wip/gl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
