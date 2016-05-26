# $NetBSD: buildlink3.mk,v 1.1 2015/05/22 23:28:40 krytarowski Exp $

BUILDLINK_TREE+=	pcmanfm-qt

.if !defined(PCMANFM_QT_BUILDLINK3_MK)
PCMANFM_QT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.pcmanfm-qt+=	pcmanfm-qt>=0.9.0
BUILDLINK_PKGSRCDIR.pcmanfm-qt?=	../../wip/pcmanfm-qt

.include "../../sysutils/menu-cache/buildlink3.mk"
.include "../../sysutils/libfm/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qttools/buildlink3.mk"
.include "../../x11/qt5-qtx11extras/buildlink3.mk"
.endif	# PCMANFM_QT_BUILDLINK3_MK

BUILDLINK_TREE+=	-pcmanfm-qt
