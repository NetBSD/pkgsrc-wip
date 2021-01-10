# $NetBSD$

BUILDLINK_TREE+=	go-stack

.if !defined(GO_STACK_BUILDLINK3_MK)
GO_STACK_BUILDLINK3_MK:=

BUILDLINK_CONTENTS_FILTER.go-stack=	${EGREP} gopkg/
BUILDLINK_DEPMETHOD.go-stack?=		build

BUILDLINK_API_DEPENDS.go-stack+=	go-stack>=1.8.0
BUILDLINK_PKGSRCDIR.go-stack?=	../../wip/go-stack
.endif	# GO_STACK_BUILDLINK3_MK

BUILDLINK_TREE+=	-go-stack
