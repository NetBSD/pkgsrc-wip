# $NetBSD$

BUILDLINK_TREE+=	go-transcoder

.if !defined(GO_TRANSCODER_BUILDLINK3_MK)
GO_TRANSCODER_BUILDLINK3_MK:=

BUILDLINK_CONTENTS_FILTER.go-transcoder=	${EGREP} gopkg/
BUILDLINK_DEPMETHOD.go-transcoder?=		build

BUILDLINK_API_DEPENDS.go-transcoder+=	go-transcoder>=1.1.1
BUILDLINK_PKGSRCDIR.go-transcoder?=	../../wip/go-transcoder
.endif	# GO_TRANSCODER_BUILDLINK3_MK

BUILDLINK_TREE+=	-go-transcoder
