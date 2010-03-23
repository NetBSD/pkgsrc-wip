# $NetBSD: buildlink3.mk,v 1.1 2010/03/23 18:14:48 jihbed Exp $

BUILDLINK_TREE+=	igraph

.if !defined(IGRAPH_BUILDLINK3_MK)
IGRAPH_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.igraph+=	igraph>=0.5.3
BUILDLINK_PKGSRCDIR.igraph?=	../../wip/igraph

.include "../../devel/gmp/buildlink3.mk"
.endif	# IGRAPH_BUILDLINK3_MK

BUILDLINK_TREE+=	-igraph
