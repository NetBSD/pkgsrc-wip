# $NetBSD$

BUILDLINK_TREE+=	miniupnpc

.if !defined(MINIUPNPC_BUILDLINK3_MK)
MINIUPNPC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.miniupnpc+=	miniupnpc>=2.0
BUILDLINK_PKGSRCDIR.miniupnpc?=	../../wip/miniupnpc
.endif	# MINIUPNPC_BUILDLINK3_MK

BUILDLINK_TREE+=	-miniupnpc
