# $NetBSD: Makefile,v 1.3 2010/09/15 20:38:06 pallegra Exp $
#

.include "Makefile.common"

PKGNAME=	${COMPONENT}-${MESA_PKGVERSION}
CATEGORIES=	graphics
EXTRACT_SUFX=	.tar.bz2

COMPONENT=	gl

MAINTAINER=	pallegra@gmail.com
HOMEPAGE=	http://www.mesa3d.org/
COMMENT=	Graphics library similar to SGI's OpenGL
LICENSE=	mit

CONFLICTS=	MesaLib<=7.6

PKGCONFIG_OVERRIDE+=	src/mesa/gl.pc.in
PKGCONFIG_OVERRIDE+=	src/mesa/osmesa.pc.in

CONFIGURE_ARGS+=	--disable-glu
CONFIGURE_ARGS+=	--disable-glut
CONFIGURE_ARGS+=	--disable-glw

# BUILD_DIRS= src/glx doesn't work if -dri
SUBST_CLASSES+=		rm_mesa
SUBST_FILES.rm_mesa=	configs/current
SUBST_MESSAGE.rm_mesa=	Removing libmesa.a
SUBST_SED.rm_mesa=	-e 's,SRC_DIRS = glsl mesa glew glx,SRC_DIRS = glx,'
SUBST_STAGE.rm_mesa=	post-configure

SUBST_CLASSES+=		rm_mesa2
SUBST_FILES.rm_mesa2=	src/mesa/Makefile
SUBST_MESSAGE.rm_mesa2=	Removing libmesa.a part 2
SUBST_SED.rm_mesa2=	-e 's,install-libgl: default,install-libgl:,'
SUBST_STAGE.rm_mesa2=	pre-install

pre-install:
	${RM} -f ${WRKSRC}/include/GL/glu*.h
	${RM} -f ${WRKSRC}/include/GL/*gl*w*.h

INSTALL_DIRS=	src/mesa
INSTALL_TARGET=	install-libgl

.include "options.mk"

.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/xextproto/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
