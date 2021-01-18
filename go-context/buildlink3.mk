# $NetBSD$

BUILDLINK_TREE+=	go-context

.if !defined(GO_CONTEXT_BUILDLINK3_MK)
GO_CONTEXT_BUILDLINK3_MK:=

BUILDLINK_CONTENTS_FILTER.go-context=	${EGREP} gopkg/
BUILDLINK_DEPMETHOD.go-context?=		build

BUILDLINK_API_DEPENDS.go-context+=	go-context>=20190109
BUILDLINK_PKGSRCDIR.go-context?=	../../wip/go-context
.endif	# GO_CONTEXT_BUILDLINK3_MK

BUILDLINK_TREE+=	-go-context
