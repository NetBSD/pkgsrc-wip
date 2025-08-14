# $NetBSD$

BUILDLINK_TREE+=	mustache

.if !defined(MUSTACHE_BUILDLINK3_MK)
MUSTACHE_BUILDLINK3_MK:=

BUILDLINK_DEPMETHOD.mustache?=	build

BUILDLINK_API_DEPENDS.mustache+=	mustache>=4.1
BUILDLINK_PKGSRCDIR.mustache?=		../../wip/mustache
.endif	# MUSTACHE_BUILDLINK3_MK

BUILDLINK_TREE+=	-mustache
