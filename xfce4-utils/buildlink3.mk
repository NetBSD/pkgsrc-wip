# $NetBSD: buildlink3.mk,v 1.8 2011/07/01 10:41:14 reinoudz70 Exp $

BUILDLINK_TREE+=	xfce4-utils

.if !defined(XFCE4_UTILS_BUILDLINK3_MK)
XFCE4_UTILS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.xfce4-utils+=	xfce4-utils>=4.8.2
BUILDLINK_PKGSRCDIR.xfce4-utils?=	../../wip/xfce4-utils

.endif # XFCE4_UTILS_BUILDLINK3_MK

BUILDLINK_TREE+=	-xfce4-utils
