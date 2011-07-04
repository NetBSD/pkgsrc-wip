# $NetBSD: buildlink3.mk,v 1.9 2011/07/04 11:19:18 reinoudz70 Exp $

BUILDLINK_TREE+=	xfce4-terminal

.if !defined(XFCE4_TERMINAL_BUILDLINK3_MK)
XFCE4_TERMINAL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.xfce4-terminal+=	xfce4-terminal>=0.2.10
BUILDLINK_PKGSRCDIR.xfce4-terminal?=	../../x11/xfce4-terminal

.endif # XFCE4_TERMINAL_BUILDLINK3_MK

BUILDLINK_TREE+=	-xfce4-terminal
