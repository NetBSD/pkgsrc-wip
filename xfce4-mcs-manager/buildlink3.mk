# $NetBSD: buildlink3.mk,v 1.6 2009/03/20 19:43:53 jsonn Exp $

BUILDLINK_TREE+=	xfce4-mcs-manager

.if !defined(XFCE4_MCS_MANAGER_BUILDLINK3_MK)
XFCE4_MCS_MANAGER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.xfce4-mcs-manager+=	xfce4-mcs-manager>=4.4.1
BUILDLINK_PKGSRCDIR.xfce4-mcs-manager?=	../../wip/xfce4-mcs-manager

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../wip/libxfce4gui/buildlink3.mk"
.include "../../wip/libxfce4mcs/buildlink3.mk"
.include "../../wip/xfce4-dev-tools/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.endif # XFCE4_MCS_MANAGER_BUILDLINK3_MK

BUILDLINK_TREE+=	-xfce4-mcs-manager
