# $NetBSD: buildlink3.mk,v 1.1.1.1 2012/05/10 10:44:48 bubuchka Exp $

BUILDLINK_TREE+=	Rgraph

.if !defined(RGRAPH_BUILDLINK3_MK)
RGRAPH_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.Rgraph+=	R-graph>=1.34.0
BUILDLINK_ABI_DEPENDS.Rgraph+=	R-graph>=1.34.0
BUILDLINK_PKGSRCDIR.Rgraph?=	../../wip/R-graph
.endif # RGRAPH_BUILDLINK3_MK

BUILDLINK_TREE+=	-Rgraph
