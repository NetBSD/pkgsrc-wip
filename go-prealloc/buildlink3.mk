# $NetBSD$

BUILDLINK_TREE+=	go-prealloc

.if !defined(GO_PREALLOC_BUILDLINK3_MK)
GO_PREALLOC_BUILDLINK3_MK:=

BUILDLINK_CONTENTS_FILTER.go-prealloc=	${EGREP} gopkg/
BUILDLINK_DEPMETHOD.go-prealloc?=	build

BUILDLINK_API_DEPENDS.go-prealloc+=	go-prealloc>=20180630
BUILDLINK_PKGSRCDIR.go-prealloc?=	../../wip/go-prealloc
.endif	# GO_PREALLOC_BUILDLINK3_MK

BUILDLINK_TREE+=	-go-prealloc
