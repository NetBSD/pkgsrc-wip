# $NetBSD$

DISTNAME=		wlroots-0.19.0
CATEGORIES=		x11
MASTER_SITE_GITLAB=	https://gitlab.freedesktop.org/
MASTER_SITES=		${MASTER_SITE_GITLAB:=wlroots/}
GITLAB_TAG=		${PKGVERSION_NOREV}

MAINTAINER=	kikadf.01@gmail.com
HOMEPAGE=	https://gitlab.freedesktop.org/wlroots/wlroots
COMMENT=	Wayland compositor library
LICENSE=	mit

USE_TOOLS+=	pkg-config

MESON_ARGS+=	-Dallocators=gbm

.include "../../devel/meson/build.mk"

# new packages
.include "../../wip/glslang/buildlink3.mk"
.include "../../wip/input-headers/buildlink3.mk"
.include "../../wip/libopeninput/buildlink3.mk"
.include "../../wip/libudev-bsd/buildlink3.mk"
.include "../../wip/libliftoff/buildlink3.mk"
.include "../../wip/seatd/buildlink3.mk"
.include "../../wip/vulkan-loader/buildlink3.mk"

# need update
.include "../../wip/wayland/buildlink3.mk"
.include "../../wip/modular-xorg-xwayland/buildlink3.mk"

.include "../../devel/wayland-protocols/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
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
