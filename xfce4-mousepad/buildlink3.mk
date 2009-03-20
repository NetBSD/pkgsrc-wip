# $NetBSD: buildlink3.mk,v 1.5 2009/03/20 19:43:54 jsonn Exp $

BUILDLINK_TREE+=	xfce4-mousepad

.if !defined(XFCE4_MOUSEPAD_BUILDLINK3_MK)
XFCE4_MOUSEPAD_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.xfce4-mousepad+=	xfce4-mousepad>=0.2.12
BUILDLINK_PKGSRCDIR.xfce4-mousepad?=	../../wip/xfce4-mousepad

.include "../../wip/libxfce4gui/buildlink3.mk"
.include "../../wip/xfce4-dev-tools/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.endif # XFCE4_MOUSEPAD_BUILDLINK3_MK

BUILDLINK_TREE+=	-xfce4-mousepad
