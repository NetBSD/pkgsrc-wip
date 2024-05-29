# $NetBSD$

BUILDLINK_TREE+=	lxqt-globalkeys

.if !defined(LXQT_GLOBALKEYS_BUILDLINK3_MK)
LXQT_GLOBALKEYS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.lxqt-globalkeys+=	lxqt-globalkeys>=2.0.0
BUILDLINK_PKGSRCDIR.lxqt-globalkeys?=	../../wip/lxqt-globalkeys

.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../wip/liblxqt/buildlink3.mk"
.endif	# LXQT_GLOBALKEYS_BUILDLINK3_MK

BUILDLINK_TREE+=	-lxqt-globalkeys
