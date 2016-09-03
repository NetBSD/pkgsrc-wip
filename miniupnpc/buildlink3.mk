# $NetBSD$
# $NetBSD buildlink3.mk, v 1.0 2016/09/02 21:46:00 erde74 Exp$

BUILDLINK_TREE+=	miniupnpc

.if !defined(MINIUPNPC_BUILDLINK3_MK)
MINIUPNPC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.miniupnpc+=	miniupnpc>=2.0
BUILDLINK_PKGSRCDIR.miniupnpc?=	../../wip/miniupnpc
.endif	# MINIUPNPC_BUILDLINK3_MK

BUILDLINK_TREE+=	-miniupnpc
