# $NetBSD$

BUILDLINK_TREE+=	apr-util

.if !defined(APR_UTIL_BUILDLINK3_MK)
APR_UTIL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.apr-util+=	apr-util>=1.5.4
BUILDLINK_ABI_DEPENDS.apr-util+=	apr-util>=1.5.4
BUILDLINK_PKGSRCDIR.apr-util?=		../../wip/unimrcp-aprutil

.endif	# APR_UTIL_BUILDLINK3_MK

BUILDLINK_TREE+=	-apr-util
