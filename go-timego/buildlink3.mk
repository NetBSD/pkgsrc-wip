# $NetBSD$

BUILDLINK_TREE+=	go-timego

.if !defined(GO_TIMEGO_BUILDLINK3_MK)
GO_TIMEGO_BUILDLINK3_MK:=

BUILDLINK_CONTENTS_FILTER.go-timego=	${EGREP} gopkg/
BUILDLINK_DEPMETHOD.go-timego?=		build

BUILDLINK_API_DEPENDS.go-timego+=	go-timego>=20181230
BUILDLINK_PKGSRCDIR.go-timego?=		../../wip/go-timego
.endif	# GO_TIMEGO_BUILDLINK3_MK

BUILDLINK_TREE+=	-go-timego
