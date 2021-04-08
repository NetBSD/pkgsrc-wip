# $NetBSD$

BUILDLINK_TREE+=	calendarsupport

.if !defined(CALENDARSUPPORT_BUILDLINK3_MK)
CALENDARSUPPORT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.calendarsupport+=	calendarsupport>=20.04.1
BUILDLINK_PKGSRCDIR.calendarsupport?=	../../wip/calendarsupport

.include "../../wip/akonadi-calendar/buildlink3.mk"
#.include "../../wip/kdepim-apps-libs/buildlink3.mk"
.include "../../time/kholidays/buildlink3.mk"
.include "../../wip/pimcommon/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.endif	# CALENDARSUPPORT_BUILDLINK3_MK

BUILDLINK_TREE+=	-calendarsupport
