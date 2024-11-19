# $NetBSD$

DISTNAME=	libglvnd-v1.7.0
PKGNAME=	${DISTNAME:S,-v,-,}
CATEGORIES=	# TODO: add primary category
MASTER_SITES=	https://gitlab.freedesktop.org/glvnd/libglvnd/-/archive/v1.7.0/

MAINTAINER=	INSERT_YOUR_MAIL_ADDRESS_HERE # or use pkgsrc-users@NetBSD.org
HOMEPAGE=	https://gitlab.freedesktop.org/glvnd/libglvnd/-/archive/v1.7.0/
COMMENT=	TODO: Short description of the package
#LICENSE=	# TODO: (see mk/license.mk)

USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

PKGCONFIG_OVERRIDE+=	libglvnd.pc.in
PKGCONFIG_OVERRIDE+=	src/EGL/egl.pc.in
PKGCONFIG_OVERRIDE+=	src/GL/gl.pc.in
PKGCONFIG_OVERRIDE+=	src/GLESv1/glesv1_cm.pc.in
PKGCONFIG_OVERRIDE+=	src/GLESv2/glesv2.pc.in
PKGCONFIG_OVERRIDE+=	src/GLX/glx.pc.in
PKGCONFIG_OVERRIDE+=	src/OpenGL/opengl.pc.in

.include "../../devel/meson/build.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/xorgproto/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
