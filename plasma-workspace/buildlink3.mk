# $NetBSD$

BUILDLINK_TREE+=	plasma-workspace

.if !defined(PLASMA_WORKSPACE_BUILDLINK3_MK)
PLASMA_WORKSPACE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.plasma-workspace+=	plasma-workspace>=5.6.3
BUILDLINK_PKGSRCDIR.plasma-workspace?=		../../wip/plasma-workspace

.include "../../net/knewstuff/buildlink3.mk"
.include "../../x11/kxmlgui/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.endif	# PLASMA_WORKSPACE_BUILDLINK3_MK

BUILDLINK_TREE+=	-plasma-workspace
