# $NetBSD$

BUILDLINK_TREE+=	go-structs

.if !defined(GO_STRUCTS_BUILDLINK3_MK)
GO_STRUCTS_BUILDLINK3_MK:=

BUILDLINK_CONTENTS_FILTER.go-structs=	${EGREP} gopkg/
BUILDLINK_DEPMETHOD.go-structs?=	build

BUILDLINK_API_DEPENDS.go-structs+=	go-structs>=1.1.0
BUILDLINK_PKGSRCDIR.go-structs?=	../../wip/go-structs
.endif	# GO_STRUCTS_BUILDLINK3_MK

BUILDLINK_TREE+=	-go-structs
