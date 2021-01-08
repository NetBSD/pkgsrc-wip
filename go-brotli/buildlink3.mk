# $NetBSD$

BUILDLINK_TREE+=	go-brotli

.if !defined(GO_BROTLI_BUILDLINK3_MK)
GO_BROTLI_BUILDLINK3_MK:=

BUILDLINK_CONTENTS_FILTER.go-brotli=	${EGREP} gopkg/
BUILDLINK_DEPMETHOD.go-brotli?=		build

BUILDLINK_API_DEPENDS.go-brotli+=	go-brotli>=1.0.1
BUILDLINK_PKGSRCDIR.go-brotli?=		../../wip/go-brotli
.endif	# GO_BROTLI_BUILDLINK3_MK

BUILDLINK_TREE+=	-go-brotli
