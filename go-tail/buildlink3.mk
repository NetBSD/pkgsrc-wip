# $NetBSD$

BUILDLINK_TREE+=	go-tail

.if !defined(GO_TAIL_BUILDLINK3_MK)
GO_TAIL_BUILDLINK3_MK:=

BUILDLINK_CONTENTS_FILTER.go-tail=	${EGREP} gopkg/
BUILDLINK_DEPMETHOD.go-tail?=		build

BUILDLINK_API_DEPENDS.go-tail+=	go-tail>=1.4.6
BUILDLINK_PKGSRCDIR.go-tail?=	../../wip/go-tail
.endif	# GO_TAIL_BUILDLINK3_MK

BUILDLINK_TREE+=	-go-tail
