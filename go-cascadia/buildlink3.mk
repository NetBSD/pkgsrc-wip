# $NetBSD$

BUILDLINK_TREE+=	go-cascadia

.if !defined(GO_CASCADIA_BUILDLINK3_MK)
GO_CASCADIA_BUILDLINK3_MK:=

BUILDLINK_CONTENTS_FILTER.go-cascadia=	${EGREP} gopkg/
BUILDLINK_DEPMETHOD.go-cascadia?=	build

BUILDLINK_API_DEPENDS.go-cascadia+=	go-cascadia>=1.0.0
BUILDLINK_PKGSRCDIR.go-cascadia?=	../../wip/go-cascadia
.endif	# GO_CASCADIA_BUILDLINK3_MK

BUILDLINK_TREE+=	-go-cascadia
