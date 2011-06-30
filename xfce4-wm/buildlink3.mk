# $NetBSD: buildlink3.mk,v 1.10 2011/06/30 20:18:24 reinoudz70 Exp $

BUILDLINK_TREE+=	xfce4-wm

.if !defined(XFCE4_WM_BUILDLINK3_MK)
XFCE4_WM_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.xfce4-wm+=	xfce4-wm>=4.8.1
BUILDLINK_PKGSRCDIR.xfce4-wm?=	../../wip/xfce4-wm

.endif # XFCE4_WM_BUILDLINK3_MK

BUILDLINK_TREE+=	-xfce4-wm
