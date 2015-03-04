# $NetBSD: Makefile,v 1.24 2015/03/04 23:48:48 tnn2 Exp $

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

# Work around a buildlink and/or libtool bug:
# In the libtool install/relink stage, if we want to link with two static
# archives named libglapi.la but in different directories, bad things happen.
SUBST_CLASSES+=			wrapper-bug
SUBST_STAGE.wrapper-bug=	pre-configure
SUBST_MESSAGE.wrapper-bug=	Renaming glapi-shared/libglapi in Makefiles
SUBST_FILES.wrapper-bug=	src/gbm/Makefile.in
SUBST_FILES.wrapper-bug+=	src/glx/Makefile.in
SUBST_FILES.wrapper-bug+=	src/mapi/Makefile.in
SUBST_FILES.wrapper-bug+=	src/mesa/drivers/x11/Makefile.in
SUBST_SED.wrapper-bug=		-e 's,shared-glapi/libglapi.la,shared-glapi/libglapi_shared.la,g'
SUBST_SED.wrapper-bug+=		-e 's,libglapi.la,libglapi_static.la,g'
SUBST_SED.wrapper-bug+=		-e 's,libglapi_shared.la,libglapi.la,g'

.include "../../mk/bsd.prefs.mk"
.include "options.mk"

PYTHON_FOR_BUILD_ONLY=	yes
BUILD_DEPENDS+=		${PYPKGPREFIX}-mako-[0-9]*:../../devel/py-mako
.include "../../lang/python/tool.mk"

.if !empty(OPSYS:M*BSD)
CONFIGURE_ARGS+=	--with-sha1=libc
.else
.include "../../security/nettle/buildlink3.mk"
CONFIGURE_ARGS+=	--with-sha1=libnettle
.endif


.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libxcb/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
