# $NetBSD: Makefile,v 1.25 2016/01/10 20:01:05 markd Exp $

DISTNAME=	kwin-${PLASMAVER}
CATEGORIES=	x11

HOMEPAGE=	https://kde.org/plasma-desktop/
COMMENT=	X11 window manager for KDE Plasma Desktops
LICENSE=	gnu-gpl-v2 AND gnu-lgpl-v2

.include "../../meta-pkgs/kde/plasma6.mk"

# std::ranges::to<QList>
USE_CXX_FEATURES+=	c++23

# undefined reference to libinput_tablet_tool_config_pressure_range_set,
# libinput_tablet_tool_config_pressure_range_is_available,
# libinput_event_tablet_pad_get_dial_delta_v120,
# libinput_event_tablet_pad_get_dial_number,
# libinput_device_get_id_bustype, libinput_device_tablet_pad_get_num_dials,
# libinput_tablet_pad_mode_group_has_dial
LDFLAGS+=	-Wl,--warn-unresolved-symbols

# for pipewire
CFLAGS.NetBSD+=	-D__LOCALE_C_ONLY

TOOL_DEPENDS+=	kf6-kdoctools>=6.18.0:../../devel/kf6-kdoctools

USE_TOOLS+=	msgmerge pkg-config

CMAKE_CONFIGURE_ARGS+=	-DBUILD_TESTING=OFF

# generation of module.moc fails when ${PREFIX}/include in the moc include path
SUBST_CLASSES+=		fix-moc
SUBST_STAGE.fix-moc=	post-configure
SUBST_MESSAGE.fix-moc=	Cleaning up MOC includes
SUBST_FILES.fix-moc=	_KDE_build/*/CMakeFiles/*_autogen.dir/AutogenInfo.json
SUBST_NOOP_OK.fix-moc=	yes
SUBST_SED.fix-moc=	-e 's;"${PREFIX}/include",;;g'

.include "../../devel/kf6-kcmutils/buildlink3.mk"
.include "../../devel/kf6-kconfig/buildlink3.mk"
.include "../../devel/kf6-kcoreaddons/buildlink3.mk"
.include "../../devel/kf6-kcrash/buildlink3.mk"
.include "../../devel/kf6-kdeclarative/buildlink3.mk"
.include "../../devel/kf6-ki18n/buildlink3.mk"
.include "../../devel/kf6-kio/buildlink3.mk"
.include "../../devel/kf6-kservice/buildlink3.mk"
.include "../../devel/libudev-bsd/buildlink3.mk"
.include "../../devel/plasma-wayland-protocols/buildlink3.mk"
.include "../../devel/plasma6-kwayland/buildlink3.mk"
.include "../../devel/qt6-qt5compat/buildlink3.mk"
.include "../../devel/qt6-qtwayland/buildlink3.mk"
.include "../../devel/wayland/buildlink3.mk"
.include "../../devel/wayland-protocols/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/kf6-ksvg/buildlink3.mk"
.include "../../graphics/lcms2/buildlink3.mk"
.include "../../graphics/plasma6-aurorae/buildlink3.mk"
.include "../../graphics/plasma6-breeze/buildlink3.mk"
.include "../../graphics/qt6-qtsvg/buildlink3.mk"
.include "../../lang/qt6-qtdeclarative/buildlink3.mk"
.include "../../misc/qt6-qtsensors/buildlink3.mk"
.include "../../wip/pipewire/buildlink3.mk"
.include "../../net/kf6-knewstuff/buildlink3.mk"
.include "../../security/kf6-kauth/buildlink3.mk"
.include "../../sysutils/kf6-kdbusaddons/buildlink3.mk"
.include "../../time/plasma6-knighttime/buildlink3.mk"
.include "../../x11/kf6-kconfigwidgets/buildlink3.mk"
.include "../../x11/kf6-kglobalaccel/buildlink3.mk"
.include "../../x11/kf6-kguiaddons/buildlink3.mk"
.include "../../x11/kf6-kwidgetsaddons/buildlink3.mk"
.include "../../x11/kf6-kwindowsystem/buildlink3.mk"
.include "../../x11/kf6-kxmlgui/buildlink3.mk"
.include "../../x11/libdisplay-info/buildlink3.mk"
.include "../../wip/libinput-bsd/buildlink3.mk"
.include "../../x11/libxcvt/buildlink3.mk"
.include "../../x11/plasma6-kdecoration/buildlink3.mk"
.include "../../x11/plasma6-kglobalacceld/buildlink3.mk"
.include "../../x11/plasma6-kscreenlocker/buildlink3.mk"
.include "../../x11/plasma6-plasma-activities/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../x11/xcb-util-cursor/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
