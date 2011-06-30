# $NetBSD: buildlink3.mk,v 1.1 2011/06/30 20:47:40 reinoudz70 Exp $

BUILDLINK_TREE+=	xfce4-settings

.if !defined(XFCE4_SETTINGS_BUILDLINK3_MK)
XFCE4_SETTINGS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.xfce4-settings+=	xfce4-settings>=4.8.2
BUILDLINK_PKGSRCDIR.xfce4-settings?=	../../wip/xfce4-settings

.endif	# XFCE4_SETTINGS_BUILDLINK3_MK

BUILDLINK_TREE+=	-xfce4-settings
