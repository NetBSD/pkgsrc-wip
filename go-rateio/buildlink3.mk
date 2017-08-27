# $NetBSD$

BUILDLINK_TREE+=	go-rateio

.if !defined(GO_RATEIO_BUILDLINK3_MK)
GO_RATEIO_BUILDLINK3_MK:=

BUILDLINK_CONTENTS_FILTER.go-rateio=	${EGREP} gopkg/
BUILDLINK_DEPMETHOD.go-rateio?=		build

BUILDLINK_API_DEPENDS.go-rateio+=	go-rateio>=0.0.1
BUILDLINK_PKGSRCDIR.go-rateio?=	../../wip/go-rateio
.endif	# GO_RATEIO_BUILDLINK3_MK

BUILDLINK_TREE+=	-go-rateio
