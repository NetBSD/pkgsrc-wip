# $NetBSD: buildlink3.mk,v 1.1.1.1 2009/06/24 22:19:34 yhardy Exp $

BUILDLINK_TREE+=	OpenSceneGraph

.if !defined(OPENSCENEGRAPH_BUILDLINK3_MK)
OPENSCENEGRAPH_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.OpenSceneGraph+=	OpenSceneGraph>=2.8.1
BUILDLINK_PKGSRCDIR.OpenSceneGraph?=	../../local/openscenegraph

.endif	# OPENSCENEGRAPH_BUILDLINK3_MK

BUILDLINK_TREE+=	-OpenSceneGraph
