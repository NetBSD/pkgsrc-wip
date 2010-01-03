# $NetBSD: Makefile,v 1.8 2010/01/03 14:54:39 pallegra Exp $
#

.include "../../wip/gl/Makefile.common"

PKGNAME=	${COMPONENT}-${MESA_PKGVERSION}
CATEGORIES=	graphics
EXTRACT_SUFX=	.tar.bz2

COMPONENT=	glu

MAINTAINER=	pallegra@gmail.com
HOMEPAGE=	http://www.mesa3d.org/
COMMENT=	GLU polygon tessellation facility for Mesa
LICENSE=	mit

PKGCONFIG_OVERRIDE+=	src/glu/glu.pc.in
USE_LANGUAGES=		c c++

CONFIGURE_ARGS+=	--enable-glu
CONFIGURE_ARGS+=	--disable-glut
CONFIGURE_ARGS+=	--disable-glw

pre-build:
	cd ${WRKSRC} && ${MKDIR} lib

BUILD_DIRS=		src/glu
BUILD_TARGET=		default

INSTALL_DIRS=		src/glu
INSTALLATION_DIRS+= 	include/GL

post-install:
	${INSTALL_DATA} ${WRKSRC}/include/GL/glu.h \
		${DESTDIR}${PREFIX}/include/GL/glu.h
	${INSTALL_DATA} ${WRKSRC}/include/GL/glu_mangle.h \
		${DESTDIR}${PREFIX}/include/GL/glu_mangle.h

.include "../../wip/gl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
