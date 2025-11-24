# $NetBSD$

DISTNAME=		wlroots-0.19.2
CATEGORIES=		x11
MASTER_SITE_GITLAB=	https://gitlab.freedesktop.org/
MASTER_SITES=		${MASTER_SITE_GITLAB:=wlroots/}
GITLAB_TAG=		${PKGVERSION_NOREV}

MAINTAINER=		kikadf.01@gmail.com
HOMEPAGE=		https://gitlab.freedesktop.org/wlroots/wlroots
COMMENT=		Wayland compositor library
LICENSE=		mit

USE_TOOLS+=		pkg-config

MESON_ARGS+=		-Dallocators=gbm

SUBST_CLASSES+=		path
SUBST_STAGE.path=	pre-configure
SUBST_MESSAGE.path=	Fixing pathes
SUBST_FILES.path+=	xcursor/xcursor.c
SUBST_VARS.path+=	PREFIX X11BASE

PLIST_VARS+=		xwayland

.include "../../devel/meson/build.mk"

# new packages
.include "../../wip/glslang/buildlink3.mk"
.include "../../wip/libopeninput/buildlink3.mk"
.include "../../wip/libudev-bsd/buildlink3.mk"
.include "../../wip/libliftoff/buildlink3.mk"
.include "../../wip/seatd/buildlink3.mk"
.include "../../wip/vulkan-loader/buildlink3.mk"

.if ${X11_TYPE} != "modular"
PLIST.xwayland=		yes
# need update
.include "../../wip/modular-xorg-xwayland/buildlink3.mk"
.endif

.include "../../devel/wayland/buildlink3.mk"
.include "../../devel/wayland-protocols/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
PREFER.MesaLib=	pkgsrc	# glesv2
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/lcms2/buildlink3.mk"
.include "../../sysutils/hwdata/buildlink3.mk"
.include "../../x11/libdisplay-info/buildlink3.mk"
.include "../../x11/libdrm/buildlink3.mk"
.include "../../x11/libxkbcommon/buildlink3.mk"
.include "../../x11/pixman/buildlink3.mk"
.include "../../x11/xcb-util-errors/buildlink3.mk"
.include "../../x11/xcb-util-renderutil/buildlink3.mk"
.include "../../x11/xcb-util-wm/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
