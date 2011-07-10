# $NetBSD: buildlink3.mk,v 1.9 2011/07/10 15:39:27 reinoudz70 Exp $

BUILDLINK_TREE+=	xfce4-orage

.if !defined(XFCE4_ORAGE_BUILDLINK3_MK)
XFCE4_ORAGE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.xfce4-orage+=	xfce4-orage>=4.8.1
BUILDLINK_PKGSRCDIR.xfce4-orage?=	../../wip/xfce4-orage

.endif # XFCE4_ORAGE_BUILDLINK3_MK

BUILDLINK_TREE+=	-xfce4-orage
