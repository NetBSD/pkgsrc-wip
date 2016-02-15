# $NetBSD$

BUILDLINK_TREE+=	kxmlgui

.if !defined(KXMLGUI_BUILDLINK3_MK)
KXMLGUI_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kxmlgui+=	kxmlgui>=5.19.0
BUILDLINK_PKGSRCDIR.kxmlgui?=	../../wip/kxmlgui

.include "../../wip/attica-qt5/buildlink3.mk"
.include "../../wip/kglobalaccel/buildlink3.mk"
.include "../../wip/ktextwidgets/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.endif	# KXMLGUI_BUILDLINK3_MK

BUILDLINK_TREE+=	-kxmlgui
