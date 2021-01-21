# $NetBSD$

BUILDLINK_TREE+=	go-httprouter

.if !defined(GO_HTTPROUTER_BUILDLINK3_MK)
GO_HTTPROUTER_BUILDLINK3_MK:=

BUILDLINK_CONTENTS_FILTER.go-httprouter=	${EGREP} gopkg/
BUILDLINK_DEPMETHOD.go-httprouter?=		build

BUILDLINK_API_DEPENDS.go-httprouter+=	go-httprouter>=1.3.0
BUILDLINK_PKGSRCDIR.go-httprouter?=	../../wip/go-httprouter
.endif	# GO_HTTPROUTER_BUILDLINK3_MK

BUILDLINK_TREE+=	-go-httprouter
