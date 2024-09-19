# $NetBSD: buildlink3.mk,v 1.2 2012/11/16 00:15:30 bubuchka Exp $

BUILDLINK_TREE+=	Rgraph

.if !defined(RGRAPH_BUILDLINK3_MK)
RGRAPH_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.Rgraph+=	R-graph>=1.36.1
BUILDLINK_ABI_DEPENDS.Rgraph+=	R-graph>=1.36.1
BUILDLINK_PKGSRCDIR.Rgraph?=	../../wip/R-graph
.endif # RGRAPH_BUILDLINK3_MK

BUILDLINK_TREE+=	-Rgraph
