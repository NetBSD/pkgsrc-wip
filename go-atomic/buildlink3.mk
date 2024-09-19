# $NetBSD$

BUILDLINK_TREE+=	go-atomic

.if !defined(GO_ATOMIC_BUILDLINK3_MK)
GO_ATOMIC_BUILDLINK3_MK:=

BUILDLINK_CONTENTS_FILTER.go-atomic=	${EGREP} gopkg/
BUILDLINK_DEPMETHOD.go-atomic?=		build

BUILDLINK_API_DEPENDS.go-atomic+=	go-atomic>=1.7.0
BUILDLINK_PKGSRCDIR.go-atomic?=	../../wip/go-atomic
.endif	# GO_ATOMIC_BUILDLINK3_MK

BUILDLINK_TREE+=	-go-atomic
