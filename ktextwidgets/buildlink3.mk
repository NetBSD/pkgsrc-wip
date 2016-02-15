# $NetBSD$

BUILDLINK_TREE+=	ktextwidgets

.if !defined(KTEXTWIDGETS_BUILDLINK3_MK)
KTEXTWIDGETS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ktextwidgets+=	ktextwidgets>=5.19.0
BUILDLINK_PKGSRCDIR.ktextwidgets?=	../../wip/ktextwidgets

.include "../../wip/kcompletion/buildlink3.mk"
.include "../../wip/kiconthemes/buildlink3.mk"
.include "../../wip/kservice/buildlink3.mk"
.include "../../wip/sonnet/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.endif	# KTEXTWIDGETS_BUILDLINK3_MK

BUILDLINK_TREE+=	-ktextwidgets
