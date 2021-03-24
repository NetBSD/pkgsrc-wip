# $NetBSD$

BUILDLINK_TREE+=	eventviews

.if !defined(EVENTVIEWS_BUILDLINK3_MK)
EVENTVIEWS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.eventviews+=	eventviews>=20.04.1
BUILDLINK_PKGSRCDIR.eventviews?=	../../wip/eventviews

.include "../../wip/calendarsupport/buildlink3.mk"
.include "../../wip/kdiagram/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.endif	# EVENTVIEWS_BUILDLINK3_MK

BUILDLINK_TREE+=	-eventviews
