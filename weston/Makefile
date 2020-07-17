# $NetBSD$

DISTNAME=	weston-8.0.0
CATEGORIES=	wm
MASTER_SITES=	https://wayland.freedesktop.org/releases/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	nykula@ukr.net
HOMEPAGE=	https://gitlab.freedesktop.org/wayland/weston
COMMENT=	Wayland desktop. Wallpaper, launchers, clock, terminal
LICENSE=	mit

USE_TOOLS+=	pkg-config
MESON_ARGS+=	-Dbackend-drm=true -Dbackend-fbdev=true -Drenderer-gl=true
MESON_ARGS+=	-Dshell-desktop=true -Dsimple-dmabuf-drm=[] -Dsimple-clients=[]

SUBST_CLASSES+=		allno
SUBST_STAGE.allno=	pre-configure
SUBST_FILES.allno=	meson_options.txt
SUBST_SED.allno=	s,true,false,

.include "../../devel/meson/build.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../devel/wayland/buildlink3.mk"
.include "../../devel/wayland-protocols/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../wip/libevdev/buildlink3.mk"
.include "../../wip/libinput/buildlink3.mk"
.include "../../wip/libudev/buildlink3.mk"
.include "../../x11/libdrm/buildlink3.mk"
.include "../../x11/libxkbcommon/buildlink3.mk"
.include "../../x11/pixman/buildlink3.mk"
.include "../../x11/xkeyboard-config/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
