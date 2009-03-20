# $NetBSD: buildlink3.mk,v 1.2 2009/03/20 19:43:49 jsonn Exp $
#

BUILDLINK_TREE+=	miniupnpc

.if !defined(MINIUPNPC_BUILDLINK3_MK)
MINIUPNPC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.miniupnpc+=	miniupnpc>=1.0nb11
BUILDLINK_PKGSRCDIR.miniupnpc?=	../../wip/miniupnpc
.endif # MINIUPNPC_BUILDLINK3_MK

BUILDLINK_TREE+=	-miniupnpc
