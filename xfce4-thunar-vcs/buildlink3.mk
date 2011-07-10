# $NetBSD: buildlink3.mk,v 1.1 2011/07/10 18:41:04 reinoudz70 Exp $

BUILDLINK_TREE+=	xfce4-thunar-vcs-plugin

.if !defined(XFCE4_THUNAR_VCS_PLUGIN_BUILDLINK3_MK)
XFCE4_THUNAR_VCS_PLUGIN_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.xfce4-thunar-vcs-plugin+=	xfce4-thunar-vcs-plugin>=0.1.4
BUILDLINK_PKGSRCDIR.xfce4-thunar-vcs-plugin?=	../../wip/xfce4-thunar-vcs

.endif	# XFCE4_THUNAR_VCS_PLUGIN_BUILDLINK3_MK

BUILDLINK_TREE+=	-xfce4-thunar-vcs-plugin
