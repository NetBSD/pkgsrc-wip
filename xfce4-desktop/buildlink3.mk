# $NetBSD: buildlink3.mk,v 1.9 2011/06/30 21:38:41 reinoudz70 Exp $

BUILDLINK_TREE+=	xfce4-desktop

.if !defined(XFCE4_DESKTOP_BUILDLINK3_MK)
XFCE4_DESKTOP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.xfce4-desktop+=	xfce4-desktop>=4.8.2
BUILDLINK_PKGSRCDIR.xfce4-desktop?=	../../wip/xfce4-desktop

.endif # XFCE4_DESKTOP_BUILDLINK3_MK

BUILDLINK_TREE+=	-xfce4-desktop
