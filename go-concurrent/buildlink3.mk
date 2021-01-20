# $NetBSD$

BUILDLINK_TREE+=	go-concurrent

.if !defined(GO_CONCURRENT_BUILDLINK3_MK)
GO_CONCURRENT_BUILDLINK3_MK:=

BUILDLINK_CONTENTS_FILTER.go-concurrent=	${EGREP} gopkg/
BUILDLINK_DEPMETHOD.go-concurrent?=		build

BUILDLINK_API_DEPENDS.go-concurrent+=	go-concurrent>=1.0.3
BUILDLINK_PKGSRCDIR.go-concurrent?=	../../wip/go-concurrent
.endif	# GO_CONCURRENT_BUILDLINK3_MK

BUILDLINK_TREE+=	-go-concurrent
