# $NetBSD: buildlink3.mk,v 1.5 2009/03/20 19:43:54 jsonn Exp $

BUILDLINK_TREE+=	xfce4-xarchiver

.if !defined(XFCE4_XARCHIVER_BUILDLINK3_MK)
XFCE4_XARCHIVER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.xfce4-xarchiver+=	xfce4-xarchiver>=0.4.6
BUILDLINK_PKGSRCDIR.xfce4-xarchiver?=	../../wip/xfce4-xarchiver

.include "../../wip/libxfce4gui/buildlink3.mk"
.include "../../wip/xfce4-dev-tools/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.endif # XFCE4_XARCHIVER_BUILDLINK3_MK

BUILDLINK_TREE+=	-xfce4-xarchiver
