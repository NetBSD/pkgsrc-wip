# $NetBSD$

BUILDLINK_TREE+=	kdelibs4support

.if !defined(KDELIBS4SUPPORT_BUILDLINK3_MK)
KDELIBS4SUPPORT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kdelibs4support+=	kdelibs4support>=5.21.0
BUILDLINK_PKGSRCDIR.kdelibs4support?=	../../wip/kdelibs4support

.include "../../wip/kemoticons/buildlink3.mk"
.include "../../wip/kitemmodels/buildlink3.mk"
.include "../../wip/kunitconversion/buildlink3.mk"
.include "../../wip/kparts/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.endif	# KDELIBS4SUPPORT_BUILDLINK3_MK

BUILDLINK_TREE+=	-kdelibs4support
