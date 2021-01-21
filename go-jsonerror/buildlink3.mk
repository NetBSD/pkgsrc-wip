# $NetBSD$

BUILDLINK_TREE+=	go-jsonerror

.if !defined(GO_JSONERROR_BUILDLINK3_MK)
GO_JSONERROR_BUILDLINK3_MK:=

BUILDLINK_CONTENTS_FILTER.go-jsonerror=	${EGREP} gopkg/
BUILDLINK_DEPMETHOD.go-jsonerror?=	build

BUILDLINK_API_DEPENDS.go-jsonerror+=	go-jsonerror>=0.1.2
BUILDLINK_PKGSRCDIR.go-jsonerror?=	../../wip/go-jsonerror
.endif	# GO_JSONERROR_BUILDLINK3_MK

BUILDLINK_TREE+=	-go-jsonerror
