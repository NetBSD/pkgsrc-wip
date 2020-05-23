# $NetBSD$

BUILDLINK_TREE+=	jsonrpc-glib

.if !defined(JSONRPC_GLIB_BUILDLINK3_MK)
JSONRPC_GLIB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.jsonrpc-glib+=	jsonrpc-glib>=3.34.0
BUILDLINK_PKGSRCDIR.jsonrpc-glib?=	../../wip/jsonrpc-glib

.endif	# JSONRPC_GLIB_BUILDLINK3_MK

BUILDLINK_TREE+=	-jsonrpc-glib
