# $NetBSD: buildlink3.mk,v 1.6 2009/03/20 19:43:54 jsonn Exp $

BUILDLINK_TREE+=	xfce4-utils

.if !defined(XFCE4_UTILS_BUILDLINK3_MK)
XFCE4_UTILS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.xfce4-utils+=	xfce4-utils>=4.4.1
BUILDLINK_PKGSRCDIR.xfce4-utils?=	../../wip/xfce4-utils

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../wip/xfce4-mcs-plugins/buildlink3.mk"
.include "../../wip/xfce4-dev-tools/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.endif # XFCE4_UTILS_BUILDLINK3_MK

BUILDLINK_TREE+=	-xfce4-utils
