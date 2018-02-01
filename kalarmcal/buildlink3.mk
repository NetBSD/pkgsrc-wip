# $NetBSD$

BUILDLINK_TREE+=	kalarmcal

.if !defined(KALARMCAL_BUILDLINK3_MK)
KALARMCAL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kalarmcal+=	kalarmcal>=17.12.1
BUILDLINK_PKGSRCDIR.kalarmcal?=	../../wip/kalarmcal

.include "../../wip/akonadi/buildlink3.mk"
.include "../../wip/kcalcore/buildlink3.mk"
.include "../../wip/kholidays/buildlink3.mk"
.include "../../wip/kidentitymanagement/buildlink3.mk"
.include "../../x11/kdelibs4support/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.endif	# KALARMCAL_BUILDLINK3_MK

BUILDLINK_TREE+=	-kalarmcal
