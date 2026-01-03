# $NetBSD$

.include "Makefile.common"

COMMENT=	wscons(4) and kqueue(2) based port of libinput

USE_TOOLS+=	pkg-config

# undefined reference to libevdev_event_type_from_name and
# libevdev_property_from_name
LDFLAGS+=	-Wl,--warn-unresolved-symbols

.include "../../mk/bsd.prefs.mk"

.if !defined(OPSYS_HAS_KQUEUE)
PKG_SKIP_REASON+=	"Requires a kqueue implementation"
.endif

PKGCONFIG_OVERRIDE+=	src/libinput.pc.in

MESON_ARGS+=	-Dlibwacom=false -Ddocumentation=false
LDFLAGS+=	-levdev

.include "../../devel/meson/build.mk"
.include "../../devel/libepoll-shim/buildlink3.mk"
.include "../../wip/libevdev-openbsd/buildlink3.mk"
.include "../../devel/libudev-bsd/buildlink3.mk"
.include "../../wip/libinput-bsd-headers/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
