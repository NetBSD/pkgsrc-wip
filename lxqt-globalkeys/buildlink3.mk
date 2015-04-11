# $NetBSD: buildlink3.mk,v 1.1 2015/04/11 15:59:30 krytarowski Exp $

BUILDLINK_TREE+=	lxqt-globalkeys

.if !defined(LXQT_GLOBALKEYS_BUILDLINK3_MK)
LXQT_GLOBALKEYS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.lxqt-globalkeys+=	lxqt-globalkeys>=0.9.0
BUILDLINK_PKGSRCDIR.lxqt-globalkeys?=	../../wip/lxqt-globalkeys

.include "../../wip/liblxqt/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.endif	# LXQT_GLOBALKEYS_BUILDLINK3_MK

BUILDLINK_TREE+=	-lxqt-globalkeys
