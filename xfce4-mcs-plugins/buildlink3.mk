# $NetBSD: buildlink3.mk,v 1.6 2009/03/20 19:43:54 jsonn Exp $

BUILDLINK_TREE+=	xfce4-mcs-plugins

.if !defined(XFCE4_MCS_PLUGINS_BUILDLINK3_MK)
XFCE4_MCS_PLUGINS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.xfce4-mcs-plugins+=	xfce4-mcs-plugins>=4.4.1
BUILDLINK_PKGSRCDIR.xfce4-mcs-plugins?=	../../wip/xfce4-mcs-plugins

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../wip/xfce4-mcs-manager/buildlink3.mk"
.include "../../wip/xfce4-dev-tools/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.endif # XFCE4_MCS_PLUGINS_BUILDLINK3_MK

BUILDLINK_TREE+=	-xfce4-mcs-plugins
