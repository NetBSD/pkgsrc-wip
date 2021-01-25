# $NetBSD$

BUILDLINK_TREE+=	go-govaluate

.if !defined(GO_GOVALUATE_BUILDLINK3_MK)
GO_GOVALUATE_BUILDLINK3_MK:=

BUILDLINK_CONTENTS_FILTER.go-govaluate=	${EGREP} gopkg/
BUILDLINK_DEPMETHOD.go-govaluate?=	build

BUILDLINK_API_DEPENDS.go-govaluate+=	go-govaluate>=3.0.0
BUILDLINK_PKGSRCDIR.go-govaluate?=	../../wip/go-govaluate
.endif	# GO_GOVALUATE_BUILDLINK3_MK

BUILDLINK_TREE+=	-go-govaluate
