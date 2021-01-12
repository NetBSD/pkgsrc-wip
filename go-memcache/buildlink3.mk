# $NetBSD$

BUILDLINK_TREE+=	go-memcache

.if !defined(GO_MEMCACHE_BUILDLINK3_MK)
GO_MEMCACHE_BUILDLINK3_MK:=

BUILDLINK_CONTENTS_FILTER.go-memcache=	${EGREP} gopkg/
BUILDLINK_DEPMETHOD.go-memcache?=		build

BUILDLINK_API_DEPENDS.go-memcache+=	go-memcache>=20190913
BUILDLINK_PKGSRCDIR.go-memcache?=	../../wip/go-memcache
.endif	# GO_MEMCACHE_BUILDLINK3_MK

BUILDLINK_TREE+=	-go-memcache
