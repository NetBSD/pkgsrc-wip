# $NetBSD$

BUILDLINK_TREE+=	go-goptlib

.if !defined(GO_GOPTLIB_BUILDLINK3_MK)
GO_GOPTLIB_BUILDLINK3_MK:=

BUILDLINK_CONTENTS_FILTER.go-goptlib=	${EGREP} gopkg/
BUILDLINK_DEPMETHOD.go-goptlib?=		build

BUILDLINK_API_DEPENDS.go-goptlib+=	go-goptlib>=0.7
BUILDLINK_PKGSRCDIR.go-goptlib?=	../../wip/go-goptlib
.endif	# GO_GOPTLIB_BUILDLINK3_MK

BUILDLINK_TREE+=	-go-goptlib
