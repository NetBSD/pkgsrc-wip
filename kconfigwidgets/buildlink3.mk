# $NetBSD$

BUILDLINK_TREE+=	kconfigwidgets

.if !defined(KCONFIGWIDGETS_BUILDLINK3_MK)
KCONFIGWIDGETS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kconfigwidgets+=	kconfigwidgets>=5.19.0
BUILDLINK_PKGSRCDIR.kconfigwidgets?=	../../wip/kconfigwidgets

.include "../../wip/kauth/buildlink3.mk"
.include "../../wip/kcodecs/buildlink3.mk"
.include "../../wip/kconfig/buildlink3.mk"
.include "../../wip/kguiaddons/buildlink3.mk"
.include "../../wip/ki18n/buildlink3.mk"
.include "../../wip/kwidgetsaddons/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.endif	# KCONFIGWIDGETS_BUILDLINK3_MK

BUILDLINK_TREE+=	-kconfigwidgets
