# $NetBSD$

BUILDLINK_TREE+=	go-xxhash

.if !defined(GO_XXHASH_BUILDLINK3_MK)
GO_XXHASH_BUILDLINK3_MK:=

BUILDLINK_CONTENTS_FILTER.go-xxhash=	${EGREP} gopkg/
BUILDLINK_DEPMETHOD.go-xxhash?=		build

BUILDLINK_API_DEPENDS.go-xxhash+=	go-xxhash>=2.0.0
BUILDLINK_PKGSRCDIR.go-xxhash?=		../../wip/go-xxhash
.endif	# GO_XXHASH_BUILDLINK3_MK

BUILDLINK_TREE+=	-go-xxhash
