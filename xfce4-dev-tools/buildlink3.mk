# $NetBSD: buildlink3.mk,v 1.8 2012/02/19 16:45:59 guigui2 Exp $

BUILDLINK_TREE+=	xfce4-dev-tools

.if !defined(XFCE4_DEV_TOOLS_BUILDLINK3_MK)
XFCE4_DEV_TOOLS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.xfce4-dev-tools+=	xfce4-dev-tools>=4.8.0
BUILDLINK_PKGSRCDIR.xfce4-dev-tools?=	../../wip/xfce4-dev-tools
BUILDLINK_DEPMETHOD.xfce4-dev-tools?=	build
.endif # XFCE4_DEV_TOOLS_BUILDLINK3_MK

BUILDLINK_TREE+=	-xfce4-dev-tools
