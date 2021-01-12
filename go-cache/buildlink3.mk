# $NetBSD$

BUILDLINK_TREE+=	go-cache

.if !defined(GO_CACHE_BUILDLINK3_MK)
GO_CACHE_BUILDLINK3_MK:=

BUILDLINK_CONTENTS_FILTER.go-cache=	${EGREP} gopkg/
BUILDLINK_DEPMETHOD.go-cache?=		build

BUILDLINK_API_DEPENDS.go-cache+=	go-cache>=20190904
BUILDLINK_PKGSRCDIR.go-cache?=		../../wip/go-cache
.endif	# GO_CACHE_BUILDLINK3_MK

BUILDLINK_TREE+=	-go-cache
