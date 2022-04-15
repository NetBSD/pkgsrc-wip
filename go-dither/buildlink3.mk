# $NetBSD$

BUILDLINK_TREE+=	go-dither

.if !defined(GO_DITHER_BUILDLINK3_MK)
GO_DITHER_BUILDLINK3_MK:=

BUILDLINK_CONTENTS_FILTER.go-dither=	${EGREP} gopkg/
BUILDLINK_DEPMETHOD.go-dither?=		build

BUILDLINK_API_DEPENDS.go-dither+=	go-dither>=2.2.0
BUILDLINK_PKGSRCDIR.go-dither?=		../../wip/go-dither

.endif	# GO_DITHER_BUILDLINK3_MK

BUILDLINK_TREE+=	-go-dither
