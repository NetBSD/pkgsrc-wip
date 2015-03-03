# $NetBSD: Makefile,v 1.19 2015/03/03 17:45:35 tnn2 Exp $

DISTNAME=	mesa-10.5.0-rc3
PKGNAME=	MesaLib-10.5.0rc3
CATEGORIES=	graphics x11
MASTER_SITES=	ftp://ftp.freedesktop.org/pub/mesa/10.5.0/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.mesa3d.org/
COMMENT=	The Mesa 3D Graphics Library
LICENSE=	mit

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config gmake
USE_LANGUAGES=	c99 c++
USE_LIBTOOL=	yes

PKGCONFIG_OVERRIDE+=	src/egl/main/egl.pc.in
PKGCONFIG_OVERRIDE+=	src/egl/wayland/wayland-egl/wayland-egl.pc.in
PKGCONFIG_OVERRIDE+=	src/gallium/targets/d3dadapter9/d3d.pc.in
PKGCONFIG_OVERRIDE+=	src/gallium/targets/osmesa/osmesa.pc.in
PKGCONFIG_OVERRIDE+=	src/gallium/targets/xa/xatracker.pc.in
PKGCONFIG_OVERRIDE+=	src/gbm/main/gbm.pc.in
PKGCONFIG_OVERRIDE+=	src/mapi/es1api/glesv1_cm.pc.in
PKGCONFIG_OVERRIDE+=	src/mapi/es2api/glesv2.pc.in
PKGCONFIG_OVERRIDE+=	src/mapi/vgapi/vg.pc.in
PKGCONFIG_OVERRIDE+=	src/mesa/drivers/dri/dri.pc.in
PKGCONFIG_OVERRIDE+=	src/mesa/drivers/osmesa/osmesa.pc.in
PKGCONFIG_OVERRIDE+=	src/mesa/gl.pc.in

.include "options.mk"

# XXX fix pypkgprefix
PYTHON_FOR_BUILD_ONLY=	yes
BUILD_DEPENDS+=		${PYPKGPREFIX}-mako-[0-9]*:../../devel/py-mako
CONFIGURE_ENV+=		PYTHON2=${PYTHONBIN}
.include "../../lang/python/application.mk"

#.include "../../multimedia/libva/buildlink3.mk"
.include "../../sysutils/libpciaccess/buildlink3.mk"
.include "../../x11/dri2proto/buildlink3.mk"
.include "../../x11/glproto/buildlink3.mk"
.include "../../x11/libXdamage/buildlink3.mk"
.include "../../x11/libXfixes/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libdrm/buildlink3.mk"
.include "../../x11/libxcb/buildlink3.mk"
.include "../../x11/xf86vidmodeproto/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
