# $NetBSD: buildlink3.mk,v 1.1 2011/07/10 17:42:18 guigui2 Exp $

BUILDLINK_TREE+=	xfce4-thunar-media-tags-plugin

.if !defined(XFCE4_THUNAR_MEDIA_TAGS_PLUGIN_BUILDLINK3_MK)
XFCE4_THUNAR_MEDIA_TAGS_PLUGIN_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.xfce4-thunar-media-tags-plugin+=	xfce4-thunar-media-tags-plugin>=0.1.2
BUILDLINK_PKGSRCDIR.xfce4-thunar-media-tags-plugin?=	../../wip/xfce4-thunar-media-tags

.endif	# XFCE4_THUNAR_MEDIA_TAGS_PLUGIN_BUILDLINK3_MK

BUILDLINK_TREE+=	-xfce4-thunar-media-tags-plugin
