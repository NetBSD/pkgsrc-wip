# $NetBSD: Makefile,v 1.1.1.1 2010/01/03 14:38:27 pallegra Exp $
#

.include "../../wip/gl/Makefile.common"

EXTRACT_SUFX=	.tar.bz2

COMPONENT=	glw

MAINTAINER=	pallegra@gmail.com
HOMEPAGE=	http://www.mesa3d.org/
COMMENT=	GL widget library for Mesa
#LICENSE=	sgi-license

CONFLICTS=	MesaLib<=7.6

PKGCONFIG_OVERRIDE+=	src/glw/glw.pc.in

CONFIGURE_ARGS+=	--disable-glu
CONFIGURE_ARGS+=	--disable-glut
CONFIGURE_ARGS+=	--enable-glw

pre-build:
	cd ${WRKSRC} && ${MKDIR} lib

BUILD_DIRS=		src/glw
BUILD_TARGET=		default

INSTALL_DIRS=		src/glw
INSTALLATION_DIRS+= 	include/GL

.include "../../wip/gl/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
