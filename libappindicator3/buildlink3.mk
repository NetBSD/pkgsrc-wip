# $NetBSD: buildlink3.mk,v 1.2 2015/04/10 19:06:32 krytarowski Exp $

BUILDLINK_TREE+=	libappindicator3

.if !defined(LIBAPPINDICATOR3_BUILDLINK3_MK)
LIBAPPINDICATOR3_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libappindicator3+=	libappindicator3>=12.10.0
BUILDLINK_PKGSRCDIR.libappindicator3?=		../../wip/libappindicator3

.include "../../wip/libindicator3/buildlink3.mk"
.include "../../wip/libdbusmenu-gtk3/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.endif	# LIBAPPINDICATOR3_BUILDLINK3_MK

BUILDLINK_TREE+=	-libappindicator3
