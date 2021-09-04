# $NetBSD$

BUILDLINK_TREE+=	kscreenlocker

.if !defined(KSCREENLOCKER_BUILDLINK3_MK)
KSCREENLOCKER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kscreenlocker+=	kscreenlocker>=5.6.3
BUILDLINK_PKGSRCDIR.kscreenlocker?=	../../wip/kscreenlocker

BUILDLINK_FILES.kscreenlocker+=	share/dbus-1/interfaces/kf5_org.freedesktop.ScreenSaver.xml
BUILDLINK_FILES.kscreenlocker+=	share/dbus-1/interfaces/org.kde.screensaver.xml

.include "../../devel/kdeclarative/buildlink3.mk"
.include "../../devel/kidletime/buildlink3.mk"
.include "../../devel/kwayland/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.endif	# KSCREENLOCKER_BUILDLINK3_MK

BUILDLINK_TREE+=	-kscreenlocker
