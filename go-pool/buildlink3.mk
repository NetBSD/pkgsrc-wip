# $NetBSD$

BUILDLINK_TREE+=	go-pool

.if !defined(GO_POOL_BUILDLINK3_MK)
GO_POOL_BUILDLINK3_MK:=

BUILDLINK_CONTENTS_FILTER.go-pool=	${EGREP} gopkg/
BUILDLINK_DEPMETHOD.go-pool?=		build

BUILDLINK_API_DEPENDS.go-pool+=	go-pool>=0.2.1
BUILDLINK_PKGSRCDIR.go-pool?=	../../wip/go-pool
.endif	# GO_POOL_BUILDLINK3_MK

BUILDLINK_TREE+=	-go-pool
