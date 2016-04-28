# $NetBSD$

BUILDLINK_TREE+=	kdeclarative

.if !defined(KDECLARATIVE_BUILDLINK3_MK)
KDECLARATIVE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kdeclarative+=	kdeclarative>=5.21.0
BUILDLINK_PKGSRCDIR.kdeclarative?=	../../wip/kdeclarative

.include "../../graphics/libepoxy/buildlink3.mk"
.include "../../wip/kio/buildlink3.mk"
.include "../../wip/kpackage/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.endif	# KDECLARATIVE_BUILDLINK3_MK

BUILDLINK_TREE+=	-kdeclarative
