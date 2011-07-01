# $NetBSD: buildlink3.mk,v 1.9 2011/07/01 09:51:02 reinoudz70 Exp $

BUILDLINK_TREE+=	xfce4-appfinder

.if !defined(XFCE4_APPFINDER_BUILDLINK3_MK)
XFCE4_APPFINDER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.xfce4-appfinder+=	xfce4-appfinder>=4.8.0
BUILDLINK_PKGSRCDIR.xfce4-appfinder?=	../../wip/xfce4-appfinder

.endif # XFCE4_APPFINDER_BUILDLINK3_MK

BUILDLINK_TREE+=	-xfce4-appfinder
