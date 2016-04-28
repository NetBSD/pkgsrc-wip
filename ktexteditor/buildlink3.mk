# $NetBSD$

BUILDLINK_TREE+=	ktexteditor

.if !defined(KTEXTEDITOR_BUILDLINK3_MK)
KTEXTEDITOR_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ktexteditor+=	ktexteditor>=5.21.0
BUILDLINK_PKGSRCDIR.ktexteditor?=	../../wip/ktexteditor

#.include "../../devel/libgit2/buildlink3.mk"
.include "../../wip/kparts/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.endif	# KTEXTEDITOR_BUILDLINK3_MK

BUILDLINK_TREE+=	-ktexteditor
