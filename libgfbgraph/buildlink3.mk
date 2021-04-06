# $NetBSD$

BUILDLINK_TREE+=	libgfbgraph

.if !defined(LIBGFBGRAPH_BUILDLINK3_MK)
LIBGFBGRAPH_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libgfbgraph+=	libgfbgraph>=0.2.4
BUILDLINK_PKGSRCDIR.libgfbgraph?=	../../wip/libgfbgraph

.include "../../net/gnome-online-accounts/buildlink3.mk"
.endif	# LIBGFBGRAPH_BUILDLINK3_MK

BUILDLINK_TREE+=	-libgfbgraph
