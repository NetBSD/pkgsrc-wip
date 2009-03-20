# $NetBSD: buildlink3.mk,v 1.5 2009/03/20 19:43:53 jsonn Exp $

BUILDLINK_TREE+=	xfce4-dev-tools

.if !defined(XFCE4_DEV_TOOLS_BUILDLINK3_MK)
XFCE4_DEV_TOOLS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.xfce4-dev-tools+=	xfce4-dev-tools>=4.4.0
BUILDLINK_PKGSRCDIR.xfce4-dev-tools?=	../../wip/xfce4-dev-tools
.endif # XFCE4_DEV_TOOLS_BUILDLINK3_MK

BUILDLINK_TREE+=	-xfce4-dev-tools
