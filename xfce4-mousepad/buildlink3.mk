# $NetBSD: buildlink3.mk,v 1.7 2011/07/04 14:16:31 reinoudz70 Exp $

BUILDLINK_TREE+=	xfce4-mousepad

.if !defined(XFCE4_MOUSEPAD_BUILDLINK3_MK)
XFCE4_MOUSEPAD_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.xfce4-mousepad+=	xfce4-mousepad>=0.2.16
BUILDLINK_PKGSRCDIR.xfce4-mousepad?=	../../wip/xfce4-mousepad

.endif # XFCE4_MOUSEPAD_BUILDLINK3_MK

BUILDLINK_TREE+=	-xfce4-mousepad
