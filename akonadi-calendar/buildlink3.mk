# $NetBSD$

BUILDLINK_TREE+=	akonadi-calendar

.if !defined(AKONADI_CALENDAR_BUILDLINK3_MK)
AKONADI_CALENDAR_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.akonadi-calendar+=	akonadi-calendar>=17.12.1
BUILDLINK_ABI_DEPENDS.akonadi-calendar?=		akonadi-calendar>=20.04.1nb1
BUILDLINK_PKGSRCDIR.akonadi-calendar?=		../../wip/akonadi-calendar

.include "../../wip/akonadi-contacts/buildlink3.mk"
.include "../../wip/kmailtransport/buildlink3.mk"
.include "../../time/kcalutils/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.endif	# AKONADI_CALENDAR_BUILDLINK3_MK

BUILDLINK_TREE+=	-akonadi-calendar
