# $NetBSD$

BUILDLINK_TREE+=	go-pointer

.if !defined(GO_POINTER_BUILDLINK3_MK)
GO_POINTER_BUILDLINK3_MK:=

BUILDLINK_CONTENTS_FILTER.go-pointer=	${EGREP} gopkg/
BUILDLINK_DEPMETHOD.go-pointer?=		build

BUILDLINK_API_DEPENDS.go-pointer+=	go-pointer>=20200722
BUILDLINK_PKGSRCDIR.go-pointer?=	../../wip/go-pointer
.endif	# GO_POINTER_BUILDLINK3_MK

BUILDLINK_TREE+=	-go-pointer
