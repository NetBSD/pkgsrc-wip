# $NetBSD$

BUILDLINK_TREE+=	go-compress

.if !defined(GO_COMPRESS_BUILDLINK3_MK)
GO_COMPRESS_BUILDLINK3_MK:=

BUILDLINK_CONTENTS_FILTER.go-compress=	${EGREP} gopkg/
BUILDLINK_DEPMETHOD.go-compress?=	build

BUILDLINK_API_DEPENDS.go-compress+=	go-compress>=1.5.0
BUILDLINK_PKGSRCDIR.go-compress?=	../../wip/go-compress
.endif	# GO_COMPRESS_BUILDLINK3_MK

BUILDLINK_TREE+=	-go-compress
