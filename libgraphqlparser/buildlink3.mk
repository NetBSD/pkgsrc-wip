# $NetBSD$

BUILDLINK_TREE+=	libgraphqlparser

.if !defined(LIBGRAPHQLPARSER_BUILDLINK3_MK)
LIBGRAPHQLPARSER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libgraphqlparser+=	libgraphqlparser>=0.4.1
BUILDLINK_PKGSRCDIR.libgraphqlparser?=		../../wip/libgraphqlparser
.endif	# LIBGRAPHQLPARSER_BUILDLINK3_MK

BUILDLINK_TREE+=	-libgraphqlparser
